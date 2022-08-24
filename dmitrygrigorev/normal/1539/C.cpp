#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;


main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, k, x;
  cin >> n >> k >> x;

  vector<int> v(n);
  for (auto &x : v) cin >> x;

  sort(all(v));
  
  vector<int> want;
  for (int i = 1; i < n; ++i) {
    int delta = v[i] - v[i-1];
    int tet = (delta + x - 1) / x - 1;

    if (tet > 0) want.pb(tet);

  }

  sort(all(want), greater<int>());

  while (want.size()) {
    if (want.back() <= k) {
      k -= want.back();
      want.pop_back();
    }
    else break;
  }

  cout << want.size() + 1;


}