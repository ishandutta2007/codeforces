#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  while (t--) {
    int n,ma=0,l=1,cr=0,a;
    cin>>n;
    for (int i=1;i<=n;i++) {
      cin>>a;
      ma+=(a==i);
      if (a==i) {
        cr++;
      } else {
        cr=0;
      }
      l+=(ma==i);
    }
    if (ma==n) {
      cout<<"0\n";
      continue;
    }
    cout<<1+(l-1+cr!=ma)<<"\n";
  }
  return 0;
}