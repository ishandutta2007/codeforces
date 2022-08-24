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

  int n;
  cin >> n;

  vector<pair<int, int> > v(n);
  for (auto &x : v) cin >> x.y >> x.x;

  sort(all(v));
  int ans = 0;

  int u1 = 0, u2 = n - 1;
  int b = 0;

  while (u1 <= u2) {
    int to_buy = v[u1].x - b;

    if (to_buy <= 0) {
      ans += v[u1].y;
      b += v[u1].y;

      u1++;
      continue;
    }

    if (to_buy >= v[u2].y) {
      ans += 2*v[u2].y;
      b += v[u2].y;

      u2--;
      continue;
    }

    ans += 2*to_buy;
    b += to_buy;
    v[u2].y -= to_buy;
    continue;
  }

  cout << ans;




}