#include <cstdio>
#include <queue>
#include <set>

using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<pii> > graph;

int n,m;
graph G;
vector<int> in;

set<pii> Q;
//ok if <= t
bool unique(int t) {
  Q.clear();
  for(int i = 0; i < n; ++i)
    in[i] = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < G[i].size(); ++j) {
      if(G[i][j].second > t) continue;
      ++in[G[i][j].first];
    }
  }
  for(int i = 0; i < n; ++i)
    Q.insert(pii(in[i],i));

  while(!Q.empty()) {
    pii nxt = *Q.begin();
    Q.erase(Q.begin());
    if(!Q.empty() && Q.begin()->first == 0)
      return 0;
    int v = nxt.second;
    for(int i = 0; i < G[v].size(); ++i) {
      if(G[v][i].second > t) continue;
      int u = G[v][i].first;
      Q.erase(pii(in[u],u));
      Q.insert(pii(--in[u],u));
    }
  }
  return 1;
}

int main() {
    scanf("%d %d",&n,&m);
    G = graph(n,vector<pii>());
    in = vector<int>(n,0);
    for(int i = 0; i < m; ++i) {
      int u,v;
      scanf("%d %d",&u,&v);
      G[u-1].push_back(pii(v-1,i+1));
    }
    if(!unique(m)) {
      printf("-1\n");
      return 0;
    }
    int lo = 1;
    int hi = m;
    while(lo < hi-1) {
      int mid = (lo+hi)/2;
      // printf("%d -> %d\n",mid,unique(mid));
      if(unique(mid))
        hi = mid;
      else lo = mid;
    }
    printf("%d\n",hi);
}