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
int add(int a,int b){
  if(a*2>=b)return 0;
  return 1+add(a*2,b);
}
void solve(){
  int N;
  cin>>N;
  vector<int> v(N);
  for(int &i:v)cin>>i;
  int tot=0;
  for(int i=1;i<N;i++)tot+=add(min(v[i],v[i-1]),max(v[i],v[i-1]));
  cout<<tot<<'\n';
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T;
  cin>>T;
  while(T--)solve();
}