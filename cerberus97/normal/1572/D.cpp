/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

template<typename flow_t = int, typename cost_t = int>
struct mcSFlow{
    struct Edge{
        cost_t c;
        flow_t f;
        int to, rev;
        Edge(int _to, cost_t _c, flow_t _f, int _rev):c(_c), f(_f), to(_to), rev(_rev){}
    };
    const cost_t INFCOST = numeric_limits<cost_t>::max()/2;
    const cost_t INFFLOW = numeric_limits<flow_t>::max()/2;
    cost_t epsilon;
    int N, S, T;
    vector<vector<Edge> > G;
    vector<unsigned int> isEnqueued, state;
    mcSFlow(int _N, int _S, int _T):epsilon(0), N(_N), S(_S), T(_T), G(_N){}
    void add_edge(int a, int b, cost_t cost, flow_t cap){
      // cout << a << ' ' << b << ' ' << cost << ' ' << cap << endl;
        if(a==b){assert(cost>=0); return;}
        cost*=N;// to preserve integer-values
        epsilon = max(epsilon, abs(cost));
        assert(a>=0&&a<N&&b>=0&&b<N);
        G[a].emplace_back(b, cost, cap, G[b].size());
        G[b].emplace_back(a, -cost, 0, G[a].size()-1);
    }
    flow_t calc_max_flow(){ // Dinic max-flow
        vector<flow_t> dist(N), state(N);
        vector<Edge*> path(N);
        auto cmp = [](Edge*a, Edge*b){return a->f < b->f;};
        flow_t addFlow, retflow=0;;
        do{
            fill(dist.begin(), dist.end(), -1);
            dist[S]=0;
            auto head = state.begin(), tail = state.begin();
            for(*tail++ = S;head!=tail;++head){
                for(Edge const&e:G[*head]){
                    if(e.f && dist[e.to]==-1){
                        dist[e.to] = dist[*head]+1;
                        *tail++=e.to;
                    }
                }
            }
            addFlow = 0;
            fill(state.begin(), state.end(), 0);
            auto top = path.begin();
            Edge dummy(S, 0, INFFLOW, -1);
            *top++ = &dummy;
            while(top != path.begin()){
                int n = (*prev(top))->to;
                if(n==T){
                    auto next_top = min_element(path.begin(), top, cmp);
                    flow_t flow = (*next_top)->f;
                    while(--top!=path.begin()){
                        Edge &e=**top, &f=G[e.to][e.rev];
                        e.f-=flow;
                        f.f+=flow;
                    }
                    addFlow=1;
                    retflow+=flow;
                    top = next_top;
                    continue;
                }
                for(flow_t &i=state[n], i_max = G[n].size(), need = dist[n]+1;;++i){
                    if(i==i_max){
                        dist[n]=-1;
                        --top;
                        break;
                    }
                    if(dist[G[n][i].to] == need && G[n][i].f){
                        *top++ = &G[n][i];
                        break;
                    }
                }
            }
        }while(addFlow);
        return retflow;
    }
    vector<flow_t> excess;
    vector<cost_t> h;
    void push(Edge &e, flow_t amt){
        //cerr << "push: " << G[e.to][e.rev].to << " -> " << e.to << " (" << e.f << "/" << e.c << ") : " << amt << "\n";
        if(e.f < amt) amt=e.f;
        e.f-=amt;
        excess[e.to]+=amt;
        G[e.to][e.rev].f+=amt;
        excess[G[e.to][e.rev].to]-=amt;
    }
    void relabel(int vertex){
        cost_t newHeight = -INFCOST;
        for(unsigned int i=0;i<G[vertex].size();++i){
            Edge const&e = G[vertex][i];
            if(e.f && newHeight < h[e.to]-e.c){
                newHeight = h[e.to] - e.c;
                state[vertex] = i;
            }
        }
        h[vertex] = newHeight - epsilon;
    }
    const int scale=2;
    pair<flow_t, cost_t> minCostFlow(){
        cost_t retCost = 0;
        for(int i=0;i<N;++i){
            for(Edge &e:G[i]){
                retCost += e.c*(e.f);
            }
        }
        //find feasible flow
        flow_t retFlow = calc_max_flow();
        excess.resize(N);h.resize(N);
        queue<int> q;
        isEnqueued.assign(N, 0); state.assign(N,0);
        for(;epsilon;epsilon>>=scale){
            //refine
            fill(state.begin(), state.end(), 0);
            for(int i=0;i<N;++i)
                for(auto &e:G[i])
                    if(h[i] + e.c - h[e.to] < 0 && e.f) push(e, e.f);
            for(int i=0;i<N;++i){
                if(excess[i]>0){
                    q.push(i);
                    isEnqueued[i]=1;
                }
            }
            while(!q.empty()){
                int cur=q.front();q.pop();
                isEnqueued[cur]=0;
                // discharge
                while(excess[cur]>0){
                    if(state[cur] == G[cur].size()){
                        relabel(cur);
                    }
                    for(unsigned int &i=state[cur], max_i = G[cur].size();i<max_i;++i){
                        Edge &e=G[cur][i];
                        if(h[cur] + e.c - h[e.to] < 0){
                            push(e, excess[cur]);
                            if(excess[e.to]>0 && isEnqueued[e.to]==0){
                                q.push(e.to);
                                isEnqueued[e.to]=1;
                            }
                            if(excess[cur]==0) break;
                        }
                    }
                }
            }
            if(epsilon>1 && epsilon>>scale==0){
                epsilon = 1<<scale;
            }
        }
        for(int i=0;i<N;++i){
            for(Edge &e:G[i]){
                retCost -= e.c*(e.f);
            }
        }
        //cerr << " -> " << retFlow << " / " << retCost << " bzw. " << retCost/2/N << "\n";
        return make_pair(retFlow, retCost/2/N);
    }
    flow_t getFlow(Edge const &e){
        return G[e.to][e.rev].f;
    }
};

const ll inf = 1e12 + 42;

int main() {
  fast_cin();
  int n, k;
  cin >> n >> k;
  int tot = (1 << n);
  vector<int> a(tot);
  for (auto& i : a) {
    cin >> i;
  }
  int need = 2 * k * n + 1;
  struct grp {
    int i, j, val;
    bool operator<(const grp& o) const {
      return val > o.val;
    }
  };
  priority_queue<grp> pq;
  for (int i = 0; i < tot; ++i) {
    if (__builtin_popcount(i) % 2 == 1) {
      continue;
    }
    for (int b = 0; b < n; ++b) {
      int j = i ^ (1 << b);
      int val = a[i] + a[j];
      pq.push({i, j, val});
      // cout << "pq " << i << ' ' << j << ' ' << val << endl;
      if (int(pq.size()) > need) {
        pq.pop();
      }
    }
  }
  map<int, int> mp;
  int vertices = 0;
  vector<grp> edges;
  while (!pq.empty()) {
    auto g = pq.top();
    pq.pop();
    if (mp.find(g.i) == mp.end()) {
      mp[g.i] = ++vertices;
    }
    if (mp.find(g.j) == mp.end()) {
      mp[g.j] = ++vertices;
    }
    edges.pb(g);
  }
  // mcSFlow(int _N, int _S, int _T):epsilon(0), N(_N), S(_S), T(_T), G(_N){}
  //   void add_edge(int a, int b, cost_t cost, flow_t cap){
  mcSFlow<ll, ll> mcmf(vertices + 3, 0, vertices + 2);
  mcmf.add_edge(vertices + 1, vertices + 2, 0, k);
  for (auto& [u, id] : mp) {
    if (__builtin_popcount(u) % 2 == 0) {
      mcmf.add_edge(0, id, 0, 1);
    } else {
      mcmf.add_edge(id, vertices + 1, 0, 1);
    }
  }
  for (auto& e : edges) {
    int u = e.i, v = e.j;
    if (__builtin_popcount(u) % 2 == 1) {
      swap(u, v);
    }
    mcmf.add_edge(mp[u], mp[v], inf - e.val, 1);
  }
  auto ans = mcmf.minCostFlow();
  cout << ans.first * inf - ans.second << '\n';
}