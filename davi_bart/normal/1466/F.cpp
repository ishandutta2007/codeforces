#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int N,M;
const int mod=1e9+7;
vector<int> par=vector<int> (500010);
struct dsu{
  vector<int> dim=vector<int> (500010,1);
  dsu(){
    for(int i=0;i<M+5;i++)par[i]=i;
  }
  int find(int a){
    if(a==par[a])return a;
    return par[a]=find(par[a]);
  }
  void unite(int a,int b){
    if(dim[a]<dim[a])swap(a,b);
    dim[a]+=dim[b];
    par[b]=a;
  }
}k;
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=0;i<par.size();i++)par[i]=i;
  cin>>N>>M;
  vector<int> ans;
  for(int i=0;i<N;i++){
    int x;
    cin>>x;
    int a,b;
    cin>>a;
    if(x==2)cin>>b;
    else b=0;

    a=k.find(a);
    b=k.find(b);
    if(a==b)continue;
    ans.pb(i+1);
    k.unite(a,b);
  }
  int pot=1;
  for(int i=0;i<ans.size();i++){
    pot=pot*2%mod;
  }
  cout<<pot<<" "<<ans.size()<<'\n';
  for(int i:ans)cout<<i<<" ";
}