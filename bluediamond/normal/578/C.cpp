#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll

const int N = (int) 2e5 + 7;
int n;
ld s[N], sol = 1e18, ss[N];

pair<ld, ld> eval(ld x) {
  ld mn = 1e18, mx = -1e18, mic = 0, mare = 0;
  for (int i = 1; i <= n; i++) {
    ss[i] = s[i] + x * i;
    ld cur = 0;
    mic = min(mic, ss[i]);
    mare = max(mare, ss[i]);

    mn = min(mn, ss[i] - mare);
    mx = max(mx, ss[i] - mic);

  }
  sol = min(sol, max(abs(mn), abs(mx)));
  return {abs(mn), abs(mx)};
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);


  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] += s[i - 1];
  }


  ld lo = -1e4, hi = 1e4;
  for (int it = 1; it <= 200; it++) {
    ld m = (lo + hi) / 2;
    auto itr = eval(m);
    if (itr.first > itr.second) {
      lo = m;
    } else {
      hi = m;
    }
  }

  cout << fixed << setprecision(6) << sol << "\n";

  return 0;
}