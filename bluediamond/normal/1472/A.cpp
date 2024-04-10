#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);

  int t;
  cin>>t;
  while(t--) {
  int a,b,n;
  cin>>a>>b>>n;
  int c1=0,c2=0;
  while (a%2==0) {
    a/=2;
    c1++;
  }
  while (b%2==0){
    b/=2;
    c2++;
  }
  int x=(1<<c1)*(1<<c2);
  if(x>=n){
    cout<<"YES\n";
  } else cout << "NO\n";
  }

}