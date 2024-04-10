#include <bits/stdc++.h>

using namespace std;

const int K=20;
const int N=(int) 1e6+7;
int n=1, v1, v2;
int par[K][N];
int dep[N];

int get_lca(int a,int b){

  if(!(dep[a]<=dep[b])) swap(a, b);

  assert(dep[a]<=dep[b]);
  int need_to_dec=dep[b]-dep[a];
  for (int j=0;(1<<j)<=need_to_dec;j++){
    if(need_to_dec&(1<<j)){
      b=par[j][b];
    }
  }

  assert(dep[a]==dep[b]);

  if(a==b)return a;

  for (int j=K-1;j>=0;j--){
    if(par[j][a]!=par[j][b]){
      a=par[j][a];
      b=par[j][b];
    }
  }
  assert(a!=b);
  assert(par[0][a]==par[0][b]);
  return par[0][a];
}

int get_dist(int a,int b){
  return dep[a]+dep[b]-2*dep[get_lca(a,b)];
}

void addChild(int p) {
  n++;
  par[0][n]=p;
  for (int j=1;j<K;j++){
    par[j][n]=par[j-1][par[j-1][n]];
  }
  dep[n]=1+dep[p];

  if(get_dist(v1,n)>get_dist(v1,v2)){
    v2=n;
    return;
  }
  if(get_dist(n,v2)>get_dist(v1,v2)){
    v1=n;
    return;
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt","r",stdin);
#endif // ONLINE_JUDGE

  v1=v2=1;
  addChild(1), addChild(1), addChild(1);

  int Q;
  cin>>Q;
  for (int iq=1;iq<=Q;iq++){
    int p;
    cin>>p;
    addChild(p), addChild(p);
    cout<<get_dist(v1,v2)<<"\n";
  }
}