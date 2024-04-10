#include <bits/stdc++.h>

using namespace std;

const int N=(int)2e5+7;
const int K=20;
int n,m,x[N],y[N],t[N],l[N],r[N],top,dep[N];
vector<int> g[N];

int get_root(int a){
  if(t[a]==a)return a;
  return t[a]=get_root(t[a]);
}

void join(int a,int b){
  t[get_root(a)]=get_root(b);
}

int safe[N];
int kek[N];

void add_to(int a,int x) {
  kek[a]+=x;
}

int anc[K][N];

void build(int a,int p=-1) {
  l[a]=++top;
  vector<int> kds;
  for(auto&b:g[a]){
    if(b==p)continue;
    anc[0][b]=a;
    dep[b]=1+dep[a];
    build(b,a);
    kds.push_back(b);
  }
  g[a]=kds;
  r[a]=top;
}


void finito(int a){
  safe[a]+=kek[a];
  for(auto&b:g[a]){
    kek[b]+=kek[a];
    finito(b);
  }
  kek[a]=0;
}

int godown(int a,int cnt){
  assert(cnt>=0);
  for(int i=0;i<K;i++){
    if(cnt&(1<<i)){
      a=anc[i][a];
    }
  }
  return a;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt","r",stdin);
#endif // ONLINE_JUDGE

  cin>>n>>m;
  vector<pair<int,int>> tr;
  for(int i=1;i<=n;i++)t[i]=i; /// nush dc nu folosesc iota pe vectori normali
  for(int i=1;i<=m;i++){
    cin>>x[i]>>y[i];
    if(get_root(x[i])!=get_root(y[i])){
      join(x[i], y[i]);
      g[x[i]].push_back(y[i]);
      g[y[i]].push_back(x[i]);
    }else{
      tr.push_back({x[i], y[i]});
    }
  }
  int root=2;
  build(root);
  for(int k=1;k<K;k++){
    for(int i=1;i<=n;i++){
      anc[k][i]=anc[k-1][anc[k-1][i]];
    }
  }
  for(auto&it:tr){
    if(l[it.first]<=l[it.second]&&r[it.second]<=r[it.first]){
      add_to(root,+1);
      int v=godown(it.second,dep[it.second]-dep[it.first]-1);
      add_to(v,-1);
      add_to(it.second,+1);
      continue;
    }
    swap(it.first,it.second);
    if(l[it.first]<=l[it.second]&&r[it.second]<=r[it.first]){
      add_to(root,+1);
      int v=godown(it.second,dep[it.second]-dep[it.first]-1);
      add_to(v,-1);
      add_to(it.second,+1);
      continue;
    }
    add_to(it.first,+1);
    add_to(it.second,+1);
  }
  finito(root);
  for (int i=1;i<=n;i++){
    cout<<(safe[i]==(int)tr.size());
  }
  cout<<"\n";


}