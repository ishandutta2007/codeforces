#include <bits/stdc++.h>

using namespace std;

bool home = 1;

typedef long long ll;
typedef long double ld;

#define int ll

int n;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("TonyStark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }


  cin>>n;

  int full=0,havemn=-(int)1e18,havemx=-(int)1e18;

  for (int i=1;i<=n;i++){
    int foo;
    cin>>foo;

    int _full=max({full,havemn+foo,havemx-foo});
    int _havemn=max({full-foo,havemn});
    int _havemx=max({full+foo,havemx});

    full=_full;
    havemn=_havemn;
    havemx=_havemx;
  }

  cout<<full;

  return 0;
}