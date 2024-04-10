#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

map<pair<string, bool>, int> memo;
int best_dif(string s, bool can_rev) {
  if (memo.count({s, can_rev})) return memo[{s, can_rev}];
  bool only_ones = 1;
  for (auto &ch : s) {
    if (ch == '0') {
      only_ones = 0;
    }
  }
  if (only_ones) {
    memo[{s, can_rev}] = 0;
    return 0;
  }
  int best = (int) 1e9;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == '0') {
      s[i] = '1';
      best = min(best, 1 - best_dif(s, 1));
      s[i] = '0';
    }
  }
  if (can_rev) {
    string t = s;
    reverse(t.begin(), t.end());
    if (s != t) {
      best = min(best, -best_dif(t, 0));
    }
  }
  assert(best != (int) 1e9);
  memo[{s, can_rev}] = best;
  return best;
}

int get(string s) {
  int val = best_dif(s, 1);
  if (val == 0) return 0;
  if (val > 0) return +1;
  if (val < 0) return -1;
  assert(0);
}

int want = 7;

int f(string s) {
  int cnt_1 = 0;
  for (auto &ch : s) {
    cnt_1 += (ch == '1');
  }
  if (cnt_1 == (int) s.size()) return 0;
  if ((int) s.size() % 2 == 0) return +1;
  int sz = (int) s.size();
  if (s[sz / 2] == '1') return +1;

  if (cnt_1 >= (int) s.size() - 1) return 1;
  return -1;
}

void print(string s) {
  if ((int) s.size() > want) return;
  string t = s;
  reverse(t.begin(), t.end());
  if (s == t && ((int) s.size() == want || 0)) {
    assert(get(s) == f(s));

    if ((int) s.size() % 2 == 1 && s[(int) s.size() / 2] == '0') {
    if (get(s) == +1) {
      cout << s << "\n";
    ///  assert(sum % 2 == 0);
    }
    if (get(s) == -1) {
     /// assert(sum % 2 == 1);
      cout << "                 " << s << "\n";
    }
    }
  //  return;
  //  cout << s << " : " << get(s) << "\n";
  }
  print(s + "0");
  print(s + "1");
}

signed main()
{
  ios::sync_with_stdio(0); cin.tie(0);

 // freopen ("input", "r", stdin);

  //print("");
//  return 0;
/**

  int cnt = 0, lim = 8;
  for (int l = 1; l <= lim; l++) {
    cnt += (1 << l);
  }
  cout << cnt << "\n";
  for (int l = 1; l <= lim; l++) {
    for (int m = 0; m < (1 << l); m++) {
      cout << l << "\n";
      for (int i = 0; i < l; i++) {
        if (m & (1 << i)) cout << 1;
        else cout << 0;
      }
      cout << "\n";
    }
  }
  return 0;**/

/**
  cout << get("1001") << "\n";
  cout << get("0") << "\n";

  return 0;**/
/**  print("");
  return 0;**/


  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    int x = f(s);
    if (x == 0) cout << "DRAW\n";
    if (x == +1) cout << "BOB\n";
    if (x == -1) cout << "ALICE\n";
    continue;
    string t = s;
    reverse(t.begin(), t.end());
    if (s != t) {
      continue;
    }
    bool all_1 = 1;
    for (auto &x : s) {
      if (x == '0') all_1 = 0;
    }
    if (all_1) {
      cout << "DRAW\n";
      assert(get(s) == 0);
      continue;
    }
    int val = 0;
    if ((int) s.size() % 2 == 0) {
      val = 1;
    } else {
      if (s[(int) s.size() / 2] == '0') {
        val = -1;
      } else {
        val = +1;
      }
    }
    if (s == "0") val = 1;
    cout << s << " : " << get(s) << " " << val << "\n";
    ///assert(get(s) == val);
   /// continue;
  }
  return 0;
}