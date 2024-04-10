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

  int t;
  cin>>t;
  while (t--) {
    int n,c0=0,c1=0;
    cin>>n;
    for (int i=1;i<=n;i++) {
      int x;
      cin>>x;
      c0+=(x%2==0);
      c1+=(x%2==1);
    }
    cout<<min(c0,c1)<<"\n";
  }
}

/**
**/