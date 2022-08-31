#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

void solve() {
  
  string s;
  cin >> s;

  vector<int> cnt(26, 0);
  for (auto x : s) cnt[x - 'a']++;

  for (int i = 0; i < 26; ++i) if (cnt[i] == s.size()) {
    cout << s << '\n';
    return;
  }

  string ans = "";
  int tot = s.size();

  for (int i = 0; i < 26; ++i) {
    if (cnt[i] == 1) {
      cnt[i]--;
      ans += (char) ('a' + i);
      tot--;
      break;
    }
  }

  if (!ans.size()) {

    for (int i = 0; i < 26; ++i) {
      if (cnt[i]) {
        cnt[i]--;
        ans += (char) ('a' + i);
        break;
      }
    }
    tot--;

  }

  int Q = ans[0] - 'a';
  if (cnt[Q] && 2 * (cnt[Q] - 1) <= tot - 1) {
    ans += (char) ('a' + Q);
    cnt[Q]--;
  }
  else {
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] && i != Q) {
        cnt[i]--;
        ans += (char) ('a' + i);
        break;
      }
    }
  }

  tot--;

  for (int i = 2; i < s.size(); ++i) {
    for (int j = 0; j < 26; ++j) {
      if (ans[i - 1] == ans[0] && ans[1] - 'a' == j) continue;
      if (!cnt[j]) continue;

      bool can = true;

      if (ans[0] - 'a' == j) {
        bool good = false;
        for (int e = 0; e < 26; ++e) if (j != e && cnt[e] && ans[1] - 'a' != e) {
          good = true;
        }
        if (!cnt[ans[1] - 'a']) good = true;
        if (i + 1 == s.size()) good = true;

        if (!good) can = false;
      } 

      if (!can) continue;
      ans += (char) ('a' + j);
      cnt[j]--;
      break;
    }
  }

  cout << ans << '\n';


}

int main(){
#ifdef LOCAL
  freopen("B_input.txt", "r", stdin);
  //freopen("B_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}