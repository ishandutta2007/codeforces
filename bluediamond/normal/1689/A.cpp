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

  int Tests;
  cin >> Tests;
  for (int tc = 1; tc <= Tests; tc++) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(26, 0), b(26, 0);
    {
      string s;
      cin >> s;
      assert((int) s.size() == n);
      for (auto &ch : s) {
        assert('a' <= ch && ch <= 'z');
        a[ch - 'a']++;
      }
    }
    {
      string s;
      cin >> s;
      assert((int) s.size() == m);
      for (auto &ch : s) {
        assert('a' <= ch && ch <= 'z');
        b[ch - 'a']++;
      }
    }
    string sol;
    int lft_a = n, lft_b = m, streak_a = 0, streak_b = 0;
    while (lft_a > 0 && lft_b > 0) {
      int min_a = -1, min_b = -1;
      for (int i = 0; i < 26; i++) {
        if (a[i] > 0) {min_a = i; break;}
      }
      for (int i = 0; i < 26; i++) {
        if (b[i] > 0) {min_b = i; break;}
      }
      assert(min_a != -1 && min_b != -1);
      if (streak_a < k && streak_b < k) {
        if (min_a < min_b) {
          streak_a++;
          streak_b = 0;
          sol += (char) ('a' + min_a);
          a[min_a]--, lft_a--;
        } else {
          streak_b++;
          streak_a = 0;
          sol += (char) ('a' + min_b);
          b[min_b]--, lft_b--;
        }
      } else {
        if (streak_a == k) {
          assert(streak_b < k);
          streak_b++;
          streak_a = 0;
          sol += (char) ('a' + min_b);
          b[min_b]--, lft_b--;
        } else {
          assert(streak_b == k);
          assert(streak_a < k);
          streak_a++;
          streak_b = 0;
          sol += (char) ('a' + min_a);
          a[min_a]--, lft_a--;
        }
      }
    }
    cout << sol << "\n";
  }
}