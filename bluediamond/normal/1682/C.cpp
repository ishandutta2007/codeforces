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
    int n;
    cin>>n;
    map<int, int> f;
    for (int i=1;i<=n;i++) {
      int x;
      cin>>x;
      f[x]++;
    }
    int single=0,dub=0;
    for (auto &it:f) {
      assert(1<=it.second);
      single+=(it.second==1);
      dub+=(it.second>1);
    }
    cout<<dub+(single+1)/2<<"\n";
  }

  ///print(2);


}