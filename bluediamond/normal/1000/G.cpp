#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool home = 1;

const int N=(int)3e5+7;
const int K=20;
int n;
int q;
int par[K][N];
int dep[N];
vector<pair<int, ll>> g[N];

ll costup[N];
ll once[N];
ll best_down[N];
ll best_up[N];
ll contrib[N];
ll s[2][N];

void dfsdown(int a,int p=0){
  par[0][a]=p;
  for(int k=1;k<K;k++){
    par[k][a]=par[k-1][par[k-1][a]];
  }
  best_down[a]=once[a];
  vector<pair<int, ll>> kids;
  for(auto&it:g[a]){
    int b=it.first,c=it.second;
    if(b==p) continue;
    dep[b]=1+dep[a];
    costup[b]=c;
    kids.push_back(it);
    dfsdown(b,a);
    contrib[b]=max(best_down[b]-2*c,0LL);
    best_down[a]+=contrib[b];
  }
  g[a]=kids;
}

void dfsup(int a){
  if(1<=par[0][a]&&par[0][a]<=n){
    best_up[a]=0LL;
    best_up[a]-=2*costup[a];
    best_up[a]+=best_down[par[0][a]]-contrib[a];
    best_up[a]+=best_up[par[0][a]];
    best_up[a]=max(best_up[a],0LL);
  }else{
    assert(a==1);
  }
  for(auto&it:g[a]){
    dfsup(it.first);
  }
}

int getlca(int a,int b){
  if(dep[a]>dep[b]){
    swap(a,b);
  }
  assert(dep[a]<=dep[b]);
  for(int k=K-1;k>=0;k--){
    if(dep[b]-(1<<k)>=dep[a]){
      b=par[k][b];
    }
  }
  assert(dep[a]==dep[b]);
  if(a==b){
    return a;
  }
  for(int k=K-1;k>=0;k--){
    if(par[k][a]!=par[k][b]){
      a=par[k][a];
      b=par[k][b];
    }
  }
  assert(a!=b);
  a=par[0][a];
  b=par[0][b];
  assert(a==b);
  return a;
}

int goup(int vertex,int cnt){
  assert(cnt>=0);
  for(int k=K-1;k>=0;k--){
    if((1<<k)<=cnt){
      cnt-=(1<<k);
      vertex=par[k][vertex];
    }
  }
  assert(cnt==0);
  return vertex;
}

void dfs(int a){
  s[0][a]+=best_down[a]-costup[a];
  s[1][a]-=contrib[a];
  for(auto&it:g[a]){
    int b=it.first;
    s[0][b]=s[0][a];
    s[1][b]=s[1][a];
    dfs(b);
  }
}


ll solve(int a,int cnt){
  if(cnt<=0){
    return 0LL;
  }
  int v1=goup(a,cnt),v2=goup(a,cnt-1);
  return s[0][a]-s[0][v1]+s[1][a]-s[1][v2];
}

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

  bool wannap=1;

  cin>>n>>q;
  for(int i=1;i<=n;i++){
    cin>>once[i];
  }

  for(int i=1;i<n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
    if(wannap&&home){
      cout<<a<<"("<<once[a]<<") "<<b<<"("<<once[b]<<") "<<c<<"\n";
    }
  }
  if(wannap&&home){
    cout<<"\n\n\n";
  }

  dfsdown(1);
  dfsup(1);
  dfs(1);

 /// exit(0);

  if(home&&wannap){
    for(int i=1;i<=n;i++){
      cout<<"down["<<i<<"] = "<<best_down[i]<<"\n";
    }
    cout<<"\n";
    for(int i=1;i<=n;i++){
      cout<<"up["<<i<<"] = "<<best_up[i]<<"\n";
    }
  }

  while(q--){
    int a,b,c;
    cin>>a>>b;
    c=getlca(a,b);

    int vertex=a,antvertex=0;
    ll sol=0;
    sol+=solve(a,dep[a]-dep[c]);
    sol+=solve(b,dep[b]-dep[c]);

    sol+=best_down[c];
    if(a!=c){
      sol-=contrib[goup(a,dep[a]-dep[c]-1)];
    }
    if(b!=c){
      sol-=contrib[goup(b,dep[b]-dep[c]-1)];
    }
    sol+=best_up[c];
    cout<<sol<<"\n";
  }

  return 0;
}