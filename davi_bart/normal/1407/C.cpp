#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mod=1e9+7;
int pot(int a,int b){
  if(b==0)return 1;
  int x=pot(a,b/2);
  if(b%2)return x*x%mod*a%mod;
  return x*x%mod;
}
int ask(int a,int b){
  cout<<"? "<<a+1<<" "<<b+1<<endl;
  int k;
  cin>>k;
  return k;
}
void solve(){
    int N;
    cin>>N;
    vector<int> sol(N,0);
    int ma=0;
    for(int i=1;i<N;i++){
      int a=ask(ma,i),b=ask(i,ma);
      if(a>b){
        sol[ma]=a;
        ma=i;
      }else{
        sol[i]=b;
      }
    }
    cout<<"! ";
    for(int i=0;i<N;i++){
      if(sol[i]==0)sol[i]=N;
      cout<<sol[i]<<" ";
    }
    cout<<endl;

}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T=1;
  //cin>>T;
  while(T--)solve();
}