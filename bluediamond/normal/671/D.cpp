#include <bits/stdc++.h>

using namespace std;

bool home=1;
typedef long double ll;

const int N=(int)3e5+7;
const ll INF=(ll)3e14;
const int K=20;
int n,m,dep[2*N],top,first[N],last[N],lg[2*N],par[K][N];
pair<int,int> tab[K][2*N];
vector<int> g[N];
vector<int> nodes;

struct of{
  int a,cost,b,i;
};

ll add(ll a, ll b) {
  return a+b;
}

void addup(ll &a, ll b){
  a=add(a,b);
}


int l[N],r[N],top2;

void build(int a,int p=-1){
  vector<int>kds;
  nodes.push_back(a);
  l[a]=++top2;
  tab[0][++top]={dep[a],a};
  first[a]=last[a]=top;
  for (auto &b:g[a]){
    if (b==p)continue;
    par[0][b]=a;
    dep[b]=1+dep[a];
    for (int k=1;(1<<k)<=dep[b];k++){
      par[k][b]=par[k-1][par[k-1][a]];
    }

    build(b,a);
    kds.push_back(b);
    tab[0][++top]={dep[a],a};
    last[a]=top;
  }
  r[a]=top2;
  g[a]=kds;
}

int lca(int a,int b){
  if (first[a]>last[b])swap(a,b);
  a=first[a];
  b=last[b];
  int k=lg[b-a+1];
  return min(tab[k][a],tab[k][b-(1<<k)+1]).second;
}

int getpar(int a,int z){
  for (int k=0;(1<<k)<=z;k++){
    if (z&(1<<k))a=par[k][a];
  }
  return a;
}

ll dp[N], sumk[N];
vector<of> allofs;
vector<of> ofs[N];

bool operator < (of x, of y){
  return l[x.a]<l[y.a];
}

bool invalid[N];

int gnext(int lww){
  int lw=0,r=m-1,sol=m;
  while (lw<=r){
    int m=(lw+r)/2;
    if (l[allofs[m].a]>=lww){
      sol=m;
      r=m-1;
    }else lw=m+1;
  }
  return sol;
}


bool killed[N];

ll lazy[4*N];
ll tree[4*N];

void push(int v,int tl,int tr){
  if (!lazy[v])return;
  if (tl==tr&&killed[tl]){
    lazy[v]=0;
    return;
  }
  addup(tree[v],lazy[v]);
  if (tl<tr){
    addup(lazy[2*v],lazy[v]);
    addup(lazy[2*v+1],lazy[v]);
  }
  lazy[v]=0;
}


void hunt(int v,int tl,int tr,int i){
  push(v,tl,tr);
  if (tr<i||i<tl)return;
  if (tl==tr){
    killed[i]=1;
    tree[v]=(ll)2e18;
    return;
  }else{
    int tm=(tl+tr)/2;
    hunt(2*v,tl,tm,i);
    hunt(2*v+1,tm+1,tr,i);
    tree[v]=min(tree[2*v],tree[2*v+1]);
  }
}

void add(int v,int tl,int tr,int l,int r,ll x){
  push(v,tl,tr);
  if (tr<l||r<tl)return;
  if (l<=tl&&tr<=r){
    addup(lazy[v],x);
    push(v,tl,tr);
    return;
  }
  int tm=(tl+tr)/2;
  add(2*v,tl,tm,l,r,x);
  add(2*v+1,tm+1,tr,l,r,x);
  tree[v]=min(tree[2*v],tree[2*v+1]);
}

bool print;

ll get(int v,int tl,int tr,int l,int r){
  if (print){
  //  cout<<tl<<" "<<tr<<", "<<l<<" "<<r<<"\n";
  }
  push(v,tl,tr);
  if (tr<l||r<tl)return (ll)2e18;
  if (l<=tl&&tr<=r){
    if (home){
    //  cout<<"\t\t\t"<<tree[v]<<"\n";
    }
    return tree[v];
  }
  int tm=(tl+tr)/2;
  return min(get(2*v,tl,tm,l,r),get(2*v+1,tm+1,tr,l,r));
}

void add(int l,int r,ll x){
  add(1,0,m,l,r,x);
}

ll get(int l,int r){
  return get(1,0,m,l,r);
}

void hunt(int i){
  hunt(1,0,m,i);
}

void dfs(int a){
  ll sol=INF;
  for (auto &b:g[a]){
    dfs(b);
    sumk[a]=add(sumk[a],dp[b]);
  }
  if (a>1){

    for (auto &it:ofs[a]){
      //cout << "\t\t"<<it.i<<"\n";
      hunt(it.i);
      invalid[it.i]=1;
    }
  }

  int low=gnext(l[a]),high=gnext(r[a]+1)-1;

  if (low<=high) {
    sol=get(low,high);

  }




  addup(sol,sumk[a]);

  dp[a]=sol;
  sumk[a]-=dp[a];



  add(low,high,sumk[a]);

}

int nw[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("TonyStark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin>>n>>m;
if(n==1){
  cout<<0;
  return 0;
}

  for (int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  build(1);

  for (int i=2;i<2*N;i++)lg[i]=1+lg[i/2];

  for (int k=1;(1<<k)<=top;k++){
    for (int i=1;i+(1<<k)-1<=top;i++){
      tab[k][i]=min(tab[k-1][i],tab[k-1][i+(1<<(k-1))]);
    }
  }


  for (int i=1;i<=m;i++){
    int a,b,cost;
    cin>>a>>b>>cost;
    ofs[b].push_back({a,cost,b,i});
    allofs.push_back(ofs[b].back());
  }

  sort(allofs.begin(),allofs.end());

  for (int i=0;i<m;i++){
    nw[allofs[i].i]=i;
    add(i,i,allofs[i].cost);
  }

  for (int i=1;i<=n;i++){
    for (auto &j:ofs[i]){
      j.i=nw[j.i];
    }
  }

  dfs(1);

  if (dp[1]>=INF)dp[1]=-1;
  cout<<(long long)dp[1]<<"\n";
  return 0;

  return 0;
}