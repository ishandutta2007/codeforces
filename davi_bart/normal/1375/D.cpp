#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int mex(vector<int> &k){
  for(int i=0;i<k.size();i++){
    if(k[i]==0)return i;
  }
}
void solve(){
  int N;
  cin>>N;
  vector<int> v(N);
  vector<int> k(N+10);
  for(int i=0;i<N;i++){
    cin>>v[i];
    k[v[i]]++;
  }
  vector<int> m;
  while(1){
    bool ok=1;
    for(int i=1;i<v.size();i++){
      if(v[i]<v[i-1]){
        ok=0;
        break;
      }
    }
    if(ok)break;
    int x=mex(k);
    if(x==N){
      int pos=0;
      for(int i=0;i<v.size();i++){
        if(v[i]!=i){
          pos=i;
          break;
        }
      }
      m.push_back(pos);
      k[v[pos]]--;
      k[x]++;
      v[pos]=x;
    }else{
      m.push_back(x);
      k[v[x]]--;
      k[x]++;
      v[x]=x;
    }
  }
  cout<<m.size()<<'\n';
  for(int h:m)cout<<h+1<<" ";
  cout<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
}