#include <bits/stdc++.h>

using namespace std;


bool home=1;

const int N=(int) 1e6+7;
const int INF=(int)1e7+7;
int n, k, a[N],stk[N],top,par[N],l[N],r[N],t;
vector<int> g[N];

void dfs(int a){
  l[a]=++t;
  for (auto &b:g[a]){
    assert(!l[b]);
    dfs(b);
  }
  r[a]=t;
}

int value[N];


int tree[4*N];
int lazy[4*N];

void push(int v,int tl,int tr){
  if(lazy[v]){
    tree[v]+=lazy[v];
    if(tl<tr){
      lazy[2*v]+=lazy[v];
      lazy[2*v+1]+=lazy[v];
    }
    lazy[v]=0;
  }
}

void add(int v,int tl,int tr,int l,int r,int x){
  push(v,tl,tr);
  if(tr<l||r<tl)return;
  if(l<=tl&&tr<=r){
    lazy[v]+=x;
    push(v,tl,tr);
    return;
  }
  int tm=(tl+tr)/2;
  add(2*v,tl,tm,l,r,x);
  add(2*v+1,tm+1,tr,l,r,x);
  tree[v]=max(tree[2*v],tree[2*v+1]);
}

void add(int l,int r,int x){
  add(1,1,n,l,r,x);

}

int getmax(){
  push(1,1,n);
  return tree[1];
}

void activate(int a){
  add(l[a],l[a],+INF);
  add(l[a],r[a],+1);
}

void del(int a){
  add(l[a],l[a],-INF);
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

  cin>>n>>k;
  for (int i=1;i<=n;i++) cin>>a[i];
  for (int i=n;i>=1;i--){
    while(top&&a[i]>=a[stk[top]])top--;
    par[i]=stk[top];
    stk[++top]=i;
  }

  for (int i=1;i<=n;i++){
    g[par[i]].push_back(i);
  }

  add(1,n,-INF);


  for (auto &r:g[0]){
    dfs(r);
  }



  for (int i=1;i<=k;i++){
    activate(i);
  }
  cout<<getmax()<<" ";

  for (int i=k+1;i<=n;i++){
    activate(i);
    del(i-k);
    cout<<getmax()<<" ";
  }
  cout<<"\n";

  return 0;
}