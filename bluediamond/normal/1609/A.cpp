#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll


signed main(){
  ios::sync_with_stdio(0); cin.tie(0);



  int t;
  cin>>t;
  while (t--){
    int n,sum=0,prod=1,mx=0;
    cin>>n;
    for (int i=0;i<n;i++){
      int x;
      cin>>x;
      while (x%2==0){
        prod*=2;
        x/=2;
      }
      sum+=x;
      mx=max(mx,x);
    }

    sum+=mx*prod-mx;

    cout<<sum<<"\n";
  }

  return 0;
}