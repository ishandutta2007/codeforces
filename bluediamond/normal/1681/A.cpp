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
    int n,m;

    cin>>n;
    vector<int> a(n);
    for (auto &x:a) cin>>x;

    cin>>m;
    vector<int> b(m);
    for (auto &x:b) cin>>x;

    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());

    if (a[0]>b[0]) {
      cout<<"Alice\n";
      cout<<"Alice\n";
      continue;
    }
    if (a[0]<b[0]) {
      cout<<"Bob\n";
      cout<<"Bob\n";
      continue;
    }
    assert(a[0]==b[0]);
    cout<<"Alice\n";
    cout<<"Bob\n";
  }

}