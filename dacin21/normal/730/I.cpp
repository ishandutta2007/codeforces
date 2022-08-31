//Min cost max flow by successive shortest paths using Leviticus? with reduced edge weights.
//Should support negative edge weights.
//Runs in O(|flow| * E * V)?

#include<bits/stdc++.h>
using namespace std;

typedef int flow_t;
typedef long long cost_t;
struct mcFlow{
    struct Edge{
        cost_t c;
        flow_t f;
        int to, rev;
        Edge(int _to, cost_t _c, flow_t _f, int _rev):c(_c), f(_f), to(_to), rev(_rev){}
    };
    const cost_t INFCOST = numeric_limits<cost_t>::max()/2;
    const cost_t INFFLOW = numeric_limits<flow_t>::max()/2;
    int N, S, T;
    vector<vector<Edge> > G;
    mcFlow(int _N, int _S, int _T):N(_N), S(_S), T(_T), G(_N){}
    void add_edge(int a, int b, cost_t cost, flow_t cap){
        assert(cost>=0);
        if(a==b){return;}
        assert(a>=0&&a<N&&b>=0&&b<N);
        G[a].emplace_back(b, cost, cap, G[b].size());
        G[b].emplace_back(a, -cost, 0, G[a].size()-1);
    }

    pair<flow_t, cost_t> minCostFlow(){
        vector<cost_t> phi(N, 0);
        vector<cost_t> dist(N);
        vector<int> state(N);
        vector<Edge*> from(N, 0);
        queue<int> q1, q2;
        cost_t retCost=0; flow_t retFlow=0;
        do{
            fill(dist.begin(), dist.end(), INFCOST);
            fill(state.begin(), state.end(), 0);
            fill(from.begin(), from.end(), (Edge*)0);
            dist[S]=0; state[S]=1;
            q1.push(S);

            while(!q1.empty()||!q2.empty()){
                int cur;
                if(!q1.empty()){ cur = q1.front();q1.pop();}
                else {cur=q2.front();q2.pop();}
                state[cur]=2;
                for(Edge &e:G[cur]){
                    if(e.f==0)continue;
                    cost_t newDist = dist[cur] + phi[cur] - phi[e.to] + e.c;
                    if(newDist < dist[e.to]){
                        dist[e.to]=newDist; from[e.to]=&e;
                        if(state[e.to]==0) q2.push(e.to);
                        else if(state[e.to]==2)q1.push(e.to);
                        state[e.to]=1;
                    }
                }
            }
            flow_t augment=INFFLOW;
            for(Edge*e = from[T];e;e=from[G[e->to][e->rev].to]){
                augment=min(augment, e->f);
            }
            for(Edge*e = from[T];e;e=from[G[e->to][e->rev].to]){
                retCost+=e->c*augment;
                e->f-=augment;
                G[e->to][e->rev].f+=augment;
            }
            retFlow+=augment;
            for(int i=0;i<N;++i){
                phi[i]+=dist[i];
            }
        }while(from[T]);
        return make_pair(retFlow, retCost);
    }
    flow_t getFlow(Edge const&e){
        return G[e.to][e.rev].f;
    }
};

int main()
{
  //freopen("in.txt", "r", stdin);
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n, p, s;
  cin >> n >> p >> s;
  mcFlow fl(n+7, n+3, n+4);
  int a;
  fl.add_edge(n+1, fl.T, 0, p);
  fl.add_edge(n+2, fl.T, 0, s);
  const int maxCost = 3000;
  for(int i=1;i<=n;++i){
    cin >> a;
    fl.add_edge(fl.S, i, 0, 1);
    fl.add_edge(i, n+1, maxCost-a, 1);
  }
  for(int i=1;i<=n;++i){
    cin >> a;
    fl.add_edge(i, n+2, maxCost-a, 1);
  }
  cout  << (s+p)*maxCost-fl.minCostFlow().second << "\n";
  for(int i=1;i<=n;++i){
    if(fl.getFlow(fl.G[i][1])) cout << i << " ";
  }
  cout << "\n";
  for(int i=1;i<=n;++i){
    if(fl.getFlow(fl.G[i][2])) cout << i << " ";
  }
  cout << "\n";
  return 0;
}