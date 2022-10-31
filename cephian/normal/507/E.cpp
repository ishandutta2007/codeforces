#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> state;

vector<vector<pii> > G;
int n, m;
priority_queue<state, vector<state>, greater<state> > Q;
pii dist[100005];
int prv[100005];

pii mpi(int a, int b) {
  // return 7;
  // return pii(0,0);
  return pii(min(a, b), max(a, b));
}

pii add(pii a, pii b) {
  return pii(a.first + a.first, a.second + a.second);
}

void search(int s, int e) {
  for(int i = 1; i <=n; ++i)
    dist[i] = pii(0x7fffffff, 0x7fffffff);
  prv[s] = -1;
  dist[s] = pii(0, 0);
  Q.push(state(pii(0, 0), s));

  while(!Q.empty()) {
    state s = Q.top();
    pii w = s.first;
    int v = s.second;
    Q.pop();
    if(w != dist[v]) continue;
    if(v == e) break;
    for(int i = 0; i < G[v].size(); ++i) {
      pii edge = G[v][i];
      int u = edge.second;
      int type = edge.first;
      pii w2 = w;
      ++w2.first;
      if(!type) ++w2.second;
      if(w2 < dist[u]) {
        dist[u] = w2;
        prv[u] = v;
        Q.push(state(w2, u));
      }
    }
  }
}

set<pii> taken;

vector<string> ans;
  stringstream ss;

int main() {
  cin >> n >> m;
  for(int i = 0; i <= n; ++i)
    G.push_back(vector<pii>());
  for(int i = 0; i < m; ++i) {
    int a, b, z;
    cin >> a >> b >> z;
    G[a].push_back(pii(z, b));
    G[b].push_back(pii(z, a));
  }
  search(1, n);

  int pre = n;
  int cur = prv[n];
  while(cur != -1) {
    pii p = mpi(cur, pre);
    taken.insert(p);
    pre = cur;
    cur = prv[cur];
  }
  int amt = 0;
  for(int v = 1; v <= n; ++v) {
    for(int j = 0; j < G[v].size(); ++j) {
      int u = G[v][j].second;
      if(u <= v) continue;
      pii edg(v, u);
      if(taken.find(edg) == taken.end()) {
        if(G[v][j].first == 1) {
          ss << v << " " << u << " 0\n";
          ++amt;
        }

      } else {
        if(G[v][j].first == 0) {
          ss << v << " " << u << " 1\n";
          ++amt;
        }
      }
    }
  }
  cout << amt << "\n" << ss.str();
  return 0;
}