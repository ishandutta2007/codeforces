#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;

#define int long long


class flow {
public:
  struct edge {
    int to;
    int cap;
    int nxt;
  };

  int n;
  vector<edge> edges;
  vector<int> level, pos, head;

  flow(int nn) : n(nn), level(n + 1), pos(n + 1), head(nn + 1, -1) {
  }

  void add(int a, int b, int c) {
    edges.push_back({b, c, head[a]});
    edges.push_back({a, 0, head[b]});


    head[a] = (int) edges.size() - 2;
    head[b] = (int) edges.size() - 1;
  }

  int dfs(int a, int cur) {
    if (a == n || !cur) return cur;
    while (pos[a] != -1) {
      int i = pos[a];
      pos[a] = edges[i].nxt;
     // cout << pos[a] << "\n";
      int b = edges[i].to, cap = edges[i].cap;
      if (level[b] == 1 + level[a] && cap > 0) {
        int x = dfs(b, min(cur, cap));
        if (x > 0) {
          edges[i].cap -= x;
          edges[i ^ 1].cap += x;
          return x;
        }
      }
    }
    return 0;
  }

  int get() {
    int sol = 0;
    while (1) {
      for (int i = 1; i <= n; i++) {
        level[i] = -1;
        pos[i] = head[i];
      }
      level[1] = 0;
      queue<int> q;
      q.push(1);
      while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (int i = head[a]; i != -1; i = edges[i].nxt) {
          int b = edges[i].to;
          if (edges[i].cap && level[b] == -1) {
            level[b] = 1 + level[a];
            q.push(b);
          }
        }
      }

      if (level[n] == -1) break;

      while (1) {
        int nw = dfs(1, (int) 1e18);

        if (nw == 0) break;
        sol += nw;
      }
    }

    return sol;
  }

};


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int n,m;
  cin>>n>>m;
  flow f(1+m+n+1);
  for(int i=1;i<=n;i++){
    int cost;
    cin>>cost;
    f.add(1+m+i,1+m+n+1,cost);
  }
  int s=0;
  for(int i=1;i<=m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    f.add(1,1+i,c);
    f.add(1+i,1+m+a,(int)1e18);
    f.add(1+i,1+m+b,(int)1e18);
    s+=c;
  }
  cout<<s-f.get()<<"\n";


  return 0;
}