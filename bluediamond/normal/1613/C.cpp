#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);

  #define int long long
  int t;
  cin>>t;
  while (t--){
    int n,h;
    cin>>n>>h;
    vector<int>a(n);
    for (auto &x:a){
      cin>>x;
    }
    sort(a.begin(),a.end());
    function<int(int)>get=[&](int k){
      int sol=0;
      for (int i=0;i<n;i++){
        if(i==n-1||a[i+1]>=a[i]+k)sol+=k;
        else sol+=a[i+1]-a[i];
      }
      return sol;
    };
    int l=1,r=(int)1e18,sol=-1;
    while (l<=r){
      int m=(l+r)/2;
      if(get(m)>=h){
        sol=m;
        r=m-1;
      }else{
        l=m+1;
      }
    }
    assert(sol!=-1);
    cout<<sol<<"\n";
  }
  return 0;
}