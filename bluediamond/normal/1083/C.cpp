#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;

const int N=(int)2e5+7;
const int K=20;
int n,value[N],where[N],par[N],first[N],last[N],top,lg2[2*N],dep[N];
vector<int> g[N];
pair<int, int> rmq[K][2*N];

void build(int a){
  rmq[0][++top]={dep[a],a};
  first[a]=last[a]=top;

  for(auto &b:g[a]){
    dep[b]=1+dep[a];
    build(b);
    rmq[0][++top]={dep[a],a};
    last[a]=top;
  }
}

int getlca(int a,int b){
  if(first[a]>last[b]){
    swap(a,b);
  }
  a=first[a];
  b=last[b];
  assert(a<=b);
  int k=lg2[b-a+1];
  return min(rmq[k][a],rmq[k][b-(1<<k)+1]).second;
}

int getdist(int a,int b){
  return dep[a]+dep[b]-2*dep[getlca(a,b)];
}

struct Node{
  bool ischain;
  int a;
  int b;
};

Node operator + (Node f,int c){
  if(f.ischain==0) return f;

  int a=f.a,b=f.b;
  if(getdist(a,b)+getdist(b,c)==getdist(a,c)) return {1,a,c};
  if(getdist(a,c)+getdist(c,b)==getdist(a,b)) return {1,a,b};
  if(getdist(b,a)+getdist(a,c)==getdist(b,c)) return {1,b,c};
  f.ischain=0;
  return f;
}

Node operator + (Node f,Node s){
  Node sol;
  if(f.ischain==0||s.ischain==0){
    sol.ischain=0;
    return sol;
  }
  f=f+s.a;
  f=f+s.b;
  return f;
}

Node tree[4*N];

void upd(int v,int tl,int tr,int i){
  if(tr<i||i<tl){
    return;
  }
  if(tl==tr){
    tree[v].ischain=1;
    tree[v].a=tree[v].b=where[i];
  }else{
    int tm=(tl+tr)/2;
    upd(2*v,tl,tm,i);
    upd(2*v+1,tm+1,tr,i);
    tree[v]=tree[2*v]+tree[2*v+1];
  }
}

void upd(int i){
  upd(1,0,n-1,i);
}

Node current;
int mex;

void solve(int v,int tl,int tr){
  assert(mex==tl);
  Node nw=current+tree[v];
  if(nw.ischain==1){
    current=nw;
    mex=tr+1;
  }else{
    if(tl<tr){
      int tm=(tl+tr)/2;
      solve(2*v,tl,tm);
      if(mex==tm+1){
        solve(2*v+1,tm+1,tr);
      }
    }
  }
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


  cin>>n;
  for(int i=0;i<n;i++){
    cin>>value[i];
    where[value[i]]=i;
  }

  for(int i=1;i<n;i++){
    cin>>par[i];
    par[i]--;
    g[par[i]].push_back(i);
    if(home&&0) cout<<i<<" "<<par[i]<<"\n";
    assert(0<=par[i]&&par[i]<i);
  }

  if(home&&0) cout<<"done with edges\n";
  build(0);

  for(int k=1;(1<<k)<=top;k++){
    for(int i=1;i+(1<<k)-1<=top;i++){
      rmq[k][i]=min(rmq[k-1][i],rmq[k-1][i+(1<<(k-1))]);
    }
  }
  for(int i=2;i<=top;i++){
    lg2[i]=1+lg2[i/2];
  }

  if(0){
    for(int i=0;i<n;i++){
      assert(getlca(i,i)==i);
      assert(getlca(0,i)==0);
      for(int j=0;j<i;j++){
        assert(getlca(i,j)==getlca(j,i));
      }
      for(int j=i+1;j<n;j++){
        cout<<"lca("<<i<<", "<<j<<") = "<<getlca(i,j)<<"\n";
      }
    }
  }

  for(int i=0;i<n;i++){
    upd(i);
  }

  int q;
  cin>>q;
  while(q--){
    int type;
    cin>>type;
    if(type==1){
      int a,b;
      cin>>a>>b;
      a--;
      b--;
      swap(value[a],value[b]);
      where[value[a]]=a;
      where[value[b]]=b;
      upd(value[a]);
      upd(value[b]);
    }else{
      current={1,where[0],where[0]};
      mex=0;
      solve(1,0,n-1);
      cout<<mex<<"\n";
    }
  }


  return 0;
}