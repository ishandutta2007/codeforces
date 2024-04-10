#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
/// #define int long long

const char BIG_CH = '|';
int n, k;
string s;

char add(char ch) {
  int x = (ch - 'a');
  x = (x + 1) % k;
  return 'a' + x;
}

char sub(char ch) {
  int x = (ch - 'a');
  x = (x + k - 1) % k;
  return 'a' + x;
}

void minimize(string &s, string a) {
  s = min(s, a);
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int tests;
  cin >> tests;
  for (int tc = 1; tc <= tests; tc++) {
    cin >> n >> k >> s;
    assert((int) s.size() == n);
    string impossible_string(n + 2, BIG_CH);
    vector<string> dp1(n + 1, impossible_string);
    vector<string> dp2(n + 1, impossible_string);
    dp1[0] = "";
    for (int i = 0; i < n; i++) {
      if (dp1[i] != impossible_string) {
        minimize(dp1[i + 1], dp1[i] + s[i]);
        minimize(dp1[i + 1], dp1[i] + add(s[i]));
        minimize(dp1[i + 1], dp1[i] + sub(s[i]));
        if (i >= 1) {
          string without_back = dp1[i];
          without_back.pop_back();
          minimize(dp1[i + 1], without_back + s[i] + dp1[i].back());
        }
        if (i + 1 < n) {
          minimize(dp2[i + 1], dp1[i] + s[i]);
        }
      }
      if (dp2[i] != impossible_string) {
        assert(i >= 1);
        string without_back = dp2[i];
        without_back.pop_back();
        minimize(dp1[i + 1], without_back + s[i] + dp2[i].back());
        minimize(dp1[i + 1], without_back + add(s[i]) + dp2[i].back());
        minimize(dp1[i + 1], without_back + sub(s[i]) + dp2[i].back());
        if (i >= 2) {
          string without_back2 = without_back;
          without_back2.pop_back();
          minimize(dp1[i + 1], without_back2 + s[i] + without_back.back() + dp2[i].back());
        }
        minimize(dp1[i + 1], dp2[i] + s[i]);
      }
    }
    cout << dp1[n] << "\n";
  }

}