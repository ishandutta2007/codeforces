#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

ll gauss(ll x) {
  return x * (x + 1) / 2;
}

ll gauss(ll l, ll r) {
  return gauss(r) - gauss(l - 1);
}

string s;

void upd(string t) {
  if (s == "-1") {
    s = t;
  } else {
    if ((int) t.size() < (int) s.size()) {
      s = t;
      return;
    }
    if ((int) t.size() == (int) s.size() && t < s) {
      s = t;
    }
  }
}

string tostr(ll num) {
  if (num == 0) {
    return "0";
  }
  vector<int> digits;
  while (num > 0) {
    digits.push_back(num % 10);
    num /= 10;
  }
  reverse(digits.begin(), digits.end());
  string s;
  for (auto &d : digits) {
    s += (char) ('0' + d);
  }
  return s;
}

string getmin(int len, int s) {
  int c9 = s / 9;
  if (c9 == len) {
    string ans;
    for (int i = 1; i <= c9; i++) {
      ans += "9";
    }
    return ans;
  }
  if (s % 9 == 0) {
    c9--;
    string ans = "1";
    for (int i = 1; i <= len - 2 - c9; i++) {
      ans += "0";
    }
    ans += "8";
    for (int i = 1; i <= c9; i++) {
      ans += "9";
    }
    return ans;
  }
  if (c9 == len - 1) {
    string ans = tostr(s % 9);
    for (int i = 1; i <= c9; i++) {
      ans += "9";
    }
    return ans;
  }
  string ans;
  ans += "1";
  for (int i = 1; i <= len - 2 - c9; i++) {
    ans += "0";
  }
  ans += tostr(s % 9 - 1);
  for (int i = 1; i <= c9; i++) {
    ans += "9";
  }
  return ans;
}

ll sumdig(ll x) {
  if (x == 0) {
    return 0;
  } else {
    return x % 10 + sumdig(x / 10);
  }
}

string gen(int dig, int cnt) {
  string ans = "";
  for (int i = 1; i <= cnt; i++) {
    ans += tostr(dig);
  }
  return ans;
}

void solve(ll n, ll k) {
  s = "-1";
  for (ll p10 = 1; p10 <= (ll) 1e18; p10 *= 10) {
    for (ll go = p10 - 20; go <= p10; go++) {
      if (go < 0) continue;
      ll val = 0;
      for (ll x = 0; x <= k; x++) {
        val += sumdig(go + x);
      }
      if (val == n) {
        upd(tostr(go));
      }
    }
  }
  for (int len = 1; len <= 25; len++) { /// same length
    for (int last = 0; last <= 9; last++) { /// last = last digit

      if (last + k <= 9) {
        ll cur = gauss(last, last + k);
        if (cur > n) continue;
        ll need = n - cur;
        if (len == 1) {
          if (need != 0) continue;
          upd(tostr(last));
          continue;
        }
        if (need % (k + 1) != 0) continue;
        ll val = need / (k + 1);
        if (val <= 0 || val > 9 * (len - 1)) continue;
        upd(getmin(len - 1, val) + tostr(last));
      } else {
        ll nd = (last + k) % 10;
        ll cur = gauss(last, 9) + gauss(1, nd);
        if (cur > n) continue;
        ll need = n - cur;
        for (ll cnt = 1; cnt < len && need > 0; cnt++) {
          ll b = nd + 1;
          ll a = k + 1 - b;
          ll starting;
          if (cnt != len - 1) {
            starting = 0;
          } else {
            starting = 1;
          }
          for (ll x = starting; x <= 8; x++) {
            ll adding = x * a + (x + 1) * b;
            if (adding > need) continue;
            if (cnt == len - 1) {
              if (adding != need) continue;
              upd(tostr(x) + gen(9, len - 2) + tostr(last));
              continue;
            }
            int need2 = need - adding;
            int rem = len - cnt - 1;
            if (need2 % (k + 1) != 0) continue;
            need2 /= (k + 1);
            if (0 < need2 && need2 <= 9 * rem) {
              upd(getmin(rem, need2) + tostr(x) + gen(9, cnt - 1) + tostr(last));
            }
          }
          need -= 9;
        }
      }
    }
  }
  cout << s << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    solve(n, k);
  }
  return 0;
}