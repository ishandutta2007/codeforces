#include <bits/stdc++.h>

using namespace std;

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

  void init(int nn){
    n=nn;
    level.resize(n+1);
    pos.resize(n+1);
    head.resize(n+1,-1);
  }

  void add(int a, int b, int c) {
    assert(1<=a&&a<=n);
    assert(1<=b&&b<=n);
    assert(c==1);
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

  int sol=0;

  int get() {

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
        int nw = dfs(1, (int) 1e9);

        if (nw == 0) break;
        sol += nw;
      }
    }

    return sol;
  }

};


bool home = 1;

const int N=5000+7;
int n,m,p[N],c[N],mex=0;
vector<int> todo[N];
bool alive[N];
int z;
int who[N];
flow f;
int s,t,wherecol[N],wherenum[N];

void add(int i) {
  if(p[i]<=mex){
    f.add(wherecol[c[i]],wherenum[p[i]],1);
  }else{
    todo[p[i]].push_back(i);
  }
}

void grow(){
  while(f.get()==mex+1){
    mex++;
    for (auto &i:todo[mex]){
      assert(p[i]==mex);
      add(i);
    }
  }
}

int rev[N];

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

  cin>>n>>m;
  z=n+1;
  f.init(2+2*z);
  s=1;
  t=2+2*z;

  int y=1;

  for (int i=1;i<=n;i++){
    wherecol[i]=++y;
    wherenum[i]=++y;
    f.add(s,wherecol[i],1);
    f.add(wherenum[i],t,1);
  }
  wherenum[0]=++y;
  f.add(wherenum[0],t,1);


  for (int i=1;i<=n;i++)cin>>p[i];
  for (int i=1;i<=n;i++){cin>>c[i];alive[i]=1;}

  int q;
  cin>>q;
  for (int i=1;i<=q;i++){
    cin>>who[i];
    alive[who[i]]=0;
  }

  for (int i=1;i<=n;i++){
    if(alive[i])add(i);
  }


  for (int i=q;i>=1;i--){
    grow();
    rev[i]=mex;
    add(who[i]);
  }

  for (int i=1;i<=q;i++){
    cout<<rev[i]<<"\n";
  }

  return 0;
}