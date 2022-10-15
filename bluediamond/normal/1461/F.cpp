#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

string get(vector<int> c) {
  int n = (int) c.size();
  vector<bool> con(n, 0);
  for (ll i = 0; i < n; i++) {
    if (c[i] == 1) con[i] = 1; else break;
  }
  for (ll i = n - 1; i >= 0; i--) {
    if (c[i] == 1) con[i] = 1; else break;
  }
  vector<int> non1;
  for (int i = 0; i < n; i++) {
    if (c[i] > 1) non1.push_back(i);
  }
 int fori = -1, lori = -1;
  for (int i = 0; i + 1 < n; i++) {
    if (con[i] || con[i + 1]) {}
    else {
      if (fori == -1) fori = i;
      lori = i;
    }
  }
  if (fori == -1) {
    string sol;
    for (int i = 1; i < n; i++) sol += "+";
    return sol;
  }
  if ((int) non1.size() > 18) {
    string sol;
    for (int i = 0; i + 1 < n; i++) {
      if (con[i] || con[i + 1]) sol += "+"; else sol += "*";
    }
    return sol;
  }
  vector<int> dp(n), p(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    dp[i] = sum + c[i];
    p[i] = -1;
    vector<int> pos;
    for (auto &j : non1) if (j < i) pos.push_back(j);
    reverse(pos.begin(), pos.end());
    int prod = c[i];
    for (auto &j : pos) {
      prod *= c[j];
      if (j == 0) {
        dp[i] = max(dp[i], prod);
        if (dp[i] == prod) p[i] = j;
      } else {
        dp[i] = max(dp[i], dp[j - 1] + prod);
        if (dp[i] == prod + dp[j - 1]) p[i] = j;
      }
    }
    sum = dp[i];
  }
  int now = n - 1;
  string sol;
  while (now >= 0) {
    if (p[now] == -1) {
      now--;
      sol += "+";
    } else {
      for (int j = 1; j <= now - p[now]; j++) sol += "*";
      now = p[now] - 1;
    }
  }
  assert((int) sol.size() == n || (int) sol.size() == n - 1);
  if ((int) sol.size() == n) sol.pop_back();
  reverse(sol.begin(), sol.end());
  //cout << dp[n - 1] << "\n";
  return sol;
  cout << dp[n - 1] << "\n";
}

const int N = (int) 1e5 + 7;
int n, a[N];
string s;
int cnt_s;
bool pl, mn, ori;

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);


  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> s;
  cnt_s = (int) s.size();
  for (auto &ch : s) {
    if (ch == '+') pl = 1;
    if (ch == '-') mn = 1;
    if (ch == '*') ori = 1;
  }
  if (cnt_s == 1) {
    for (int i = 1; i <= n; i++) {
      cout << a[i];
      if (i < n) {
        cout << s[0];
      }
    }
    cout << "\n";
    return 0;
  }
  if (cnt_s == 2) {
    if (pl && mn) {
      for (int i = 1; i <= n; i++) {
        cout << a[i];
        if (i < n) {
          cout << "+";
        }
      }
      cout << "\n";
      return 0;
    }
    if (mn && ori) {
      int p0 = -1;
      for (int i = 1; i <= n; i++) if (a[i] == 0) {p0 = i; break;}
      if (p0 == -1) {
        for (int i = 1; i <= n; i++) {
          cout << a[i];
          if (i < n) {
            cout << "*";
          }
        }
        cout << "\n";
      } else {
        for (int i = 1; i <= n; i++) {
          cout << a[i];
          if (i < n) {
            if (i != p0 - 1) cout << "*"; else cout << "-";
          }
        }
        cout << "\n";
      }
      return 0;
    }
  }

  /// o sa folosesc doar plus si ori
  vector<pair<vector<int>, int>> kek;
  int l = 1;
  while (l <= n) {
    vector<int> copo;
    int cnt = 0;
    while (l <= n && a[l] > 0) copo.push_back(a[l++]);
    while (l <= n && a[l] == 0) {cnt++; l++;}
    kek.push_back({copo, cnt});
  }
  bool firstt = 1;
  for (auto &it : kek) {
    if (!firstt) {
      cout << "+";
    }
    string s = get(it.first);
    for (int j = 0; j < (int) it.first.size(); j++) {
      firstt = 0;
      cout << it.first[j];
      if (j + 1 < (int) it.first.size()) cout << s[j];
    }
    for (int i = 1; i <= it.second; i++) {
      if (!firstt) cout << "+";
      firstt = 0;
      cout << "0";
    }
  }
  cout << "\n";
}