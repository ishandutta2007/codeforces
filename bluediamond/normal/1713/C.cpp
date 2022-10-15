#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;


void solve(int n) {
  set<int> free;
  for(int i=0;i<n;i++) free.insert(i);
  vector<int> what(n,-1);
  int last=(int)1e9;
  int sum=2*n;
  vector<bool> e_ppf(sum+1,0);
  for(int i=0;i*i<=sum;i++){
    e_ppf[i*i]=1;
  }
  for(int x=n-1;x>=0;x--){
    while(!free.count(sum-x)||!e_ppf[sum]){
      sum--;
    }
    what[x]=sum-x;
    free.erase(sum-x);
  }
  for(auto&x:what)cout<<x<<" ";
  cout<<"\n";
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen("___input___.txt","r",stdin);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    solve(n);
  }
}