#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  int tt;
  cin>>tt;
  while (tt--) {
    int n;
    cin>>n;
    vector<int> a(n);
    for (auto &x:a) {
      cin>>x;
    }
    int m;
    cin>>m;
    int sum=0;
    for (int i=1;i<=m;i++) {
      int x;
      cin>>x;
      sum=(sum+x)%n;
    }
    cout<<a[sum]<<"\n";
  }

}