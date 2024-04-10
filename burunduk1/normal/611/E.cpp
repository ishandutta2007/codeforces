/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define sz(a) (int)(a).size()

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, a[3];
  cin >> n;
  forn(i, 3) cin >> a[i];
  sort(a, a + 3);
  int b[n];
  forn(i, n) cin >> b[i];
  sort(b, b + n);
  if (b[n - 1] > a[0] + a[1] + a[2]) {
    puts("-1");
    return 0;
  }
  int l = 0, r = n - 1, ans = 0, can[3] = {0, 0, 0};
  while (r >= l && b[r] > a[1] + a[2])
    r--, ans++;
  while (r >= l && b[r] > a[0] + a[2])
    r--, ans++, can[0]++;
  while (r >= l && b[r] > max(a[0] + a[1], a[2]))
    r--, ans++, can[1]++;
  while (r >= l && b[r] > a[2])
    r--, ans++, can[2]++;
  multiset<int> s;
  while (l <= r)
    s.insert(b[l++]);

  auto del = [&]( int x ) {
    if (!s.size())
      return 0;
    auto it = s.upper_bound(x);
    if (it == s.begin())
      return 0;
    s.erase(--it);
    return 1;
  };

  forn(i, 3) 
    while (can[i] && del(a[i]))
      can[i]--;
  //printf("ans = %d, rest = %d\n", ans, sz(s));
  while (s.size()) 
    if (*s.begin() <= a[1]) {
      forn(i, 3) del(a[i]);
      ans++;
    } else {
      del(a[0] + a[1]), del(a[2]);
      ans++;
    }
  cout << ans << endl;
}