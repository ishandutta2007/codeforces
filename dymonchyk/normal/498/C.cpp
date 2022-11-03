#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

struct DinicFlow{
  struct Edge{
    Edge(int _to,int _cap,int _next) : to(_to), cap(_cap), next(_next) {};
    int to,cap,next;
  };
  int n,s,t,fl;
  vector <int> first,d,q,ptr;
  vector <bool> used;
  vector <Edge> a;
  DinicFlow(int _n,int _s,int _t) : n(_n), s(_s), t(_t) {
    first.resize(n,-1);
  };
  void addEdge(int u,int v,int cap,bool oriented = true) {
    a.push_back(Edge(v,cap,first[u])); first[u]=a.size()-1;
    a.push_back(Edge(u,oriented ? 0 : cap,first[v])); first[v]=a.size()-1;
  }
  bool bfs() {
    d.clear(); d.resize(n,-1);
    d[s]=0; q.clear(); q.push_back(s);
    for(int i=0;i<q.size();++i) {
      int v=q[i];
      for(int e=first[v];e!=-1;e=a[e].next) {
        int u=a[e].to;
        if (d[u]==-1&&a[e].cap) {
          d[u]=d[v]+1;
          q.push_back(u);
        }
      }
    }
    return d[t]!=-1;
  }
  int dfs(int v,int push = 1000000000) {
    if (v==t||push<=0) {
      fl+=push;
      return push;
    }
    int pushed=0;
    for(int e=ptr[v];e!=-1;e=a[e].next) {
      int u=a[e].to; ptr[v]=a[e].next;
      if (d[v]+1==d[u]) {
        if (int val=dfs(u,min(push-pushed,a[e].cap))) {
          pushed+=val;
          a[e].cap-=val;
          a[e^1].cap+=val;
        }
      }
    }
    return pushed;
  }
  int flow() {
    fl=0;
    while(bfs()) {
      ptr=first;
      dfs(s);
    }
    return fl;
  }
};

int arr[101], x[101], y[102];

vector<int> p;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", &arr[i]);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    --x[i]; --y[i];
  }
  for (int i = 0; i < n; ++i) {
    int k = arr[i];
    for (int j = 2; j * j <= k; ++j) {
      if (k % j == 0) {
        p.push_back(j);
        while (k % j == 0) k /= j;
      }
    }
    if (k > 1) p.push_back(k);
  }
  sort(p.begin(), p.end());
  p.resize(unique(p.begin(), p.end()) - p.begin());
  int ans = 0;
  for (int pr : p) {
    DinicFlow flow(n + 2, n, n + 1);
    for (int i = 0; i < n; ++i) {
      int cnt = 0, k = arr[i];
      while (k % pr == 0) {
        ++cnt;
        k /= pr;
      }
      if (i & 1) flow.addEdge(n, i, cnt);
      else flow.addEdge(i, n + 1, cnt);
    }
    for (int i = 0; i < m; ++i) {
      int k1 = arr[x[i]], k2 = arr[y[i]], cnt = 0;
      while (k1 % pr == 0 && k2 % pr == 0) {
        ++cnt;
        k1 /= pr; k2 /= pr;
      }
      if (y[i] & 1) swap(x[i], y[i]);
      flow.addEdge(x[i], y[i], cnt);
    }
    ans += flow.flow();
  }
  printf("%d\n", ans);
  return 0;
}