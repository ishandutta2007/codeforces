#include <cstdio>
#include <set>
#include <vector>
#include <queue>

using namespace std;
typedef vector<vector<int> > graph;

graph G;
int n,m,q;
const int N = 300005;
int lp[N];
int uf[N];

int id(int a) {
  if(uf[a]==a) return a;
  return uf[a]=id(uf[a]);
}

void merge(int a, int b) {
  uf[id(a)]=id(b);
}

set<int> seen;

queue<int> Q;
bool qs[N];
void find_leaf(int v, int f) {
  qs[v]=0;
  if(G[v].size()<=1) Q.push(v);
  for(int i = 0; i < G[v].size(); ++i) {
    if(G[v][i]==f) continue;
    find_leaf(G[v][i],v);
  }
}

int lng=-1,lng_d=0;
void farthest(int v, int f, int d) {
  if(d > lng_d) {
    lng_d = d;
    lng = v;
  }
  int last = v;
  for(int i = 0; i < G[v].size(); ++i) {
    if(G[v][i]==f) continue;
    farthest(G[v][i],v,d+1);
  }
}

int long_t(int v, int f) {
  int ans = 0;
  for(int i = 0; i < G[v].size(); ++i) {
    if(G[v][i]==f) continue;
    ans = max(ans,1+long_t(G[v][i],v));
  }
  return ans;
}

void mrg(int v, int u) {
  if(id(v)==id(u)) return;
  int a = lp[id(v)];
  int b = lp[id(u)];
  merge(v,u);
  lp[id(v)] = max(max(a,b),(a+1)/2+(b+1)/2+1);
}

int query(int v) {
  return lp[id(v)];
}

int main() {
  scanf("%d%d%d",&n,&m,&q);
  for(int i = 0; i < n; ++i) {
    uf[i]=i;
    lp[i]=0;
  }
  G = graph(n,vector<int>());
  for(int i = 0; i < m; ++i) {
    int a,b;
    scanf("%d%d",&a,&b);
    G[--a].push_back(--b);
    G[b].push_back(a);
    merge(a,b);
  }
  for(int i = 0; i < n; ++i) {
    if(seen.count(id(i))) continue;
    lng_d=-1;
    farthest(i,-1,0);
    lp[id(i)]=long_t(lng,-1);
    seen.insert(id(i));
  }

  while(q--) {
    int type;
    scanf("%d",&type);
    if(type == 1) {
      int x;
      scanf("%d",&x);
      printf("%d\n",query(x-1));
    } else if(type == 2) {
      int x,y;
      scanf("%d%d",&x,&y);
      mrg(x-1,y-1);
    }

  }
  return 0;
}