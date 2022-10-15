#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


vector<int> kmp(string s, string pat) {
  int m = (int) pat.size();
  int n = (int) s.size();
  vector<int> ps(m, 0);
  int j = 0;
  for (int i = 1; i < m; i++) {
    while (j && pat[i] != pat[j]) {
      j = ps[j - 1];
    }
    if (pat[i] == pat[j]) {
      j++;
    }
    ps[i] = j;
  }
  j = 0;
  vector<int> ret;
  for (int i = 0; i < n; i++) {
    while (j && s[i] != pat[j]) {
      j = ps[j - 1];
    }
    if (pat[j] == s[i]) {
      j++;
    }
    if (j == m) {
      j = ps[m - 1];
      ret.push_back(i - m + 1);
    }
  }
  return ret;
}

string getstr(string s, int l, int r) {
  assert(0 <= l && l <= r && r < (int) s.size());
  string sol;
  for (int j = l; j <= r; j++) {
    sol += s[j];
  }
  return sol;
}

const int N = 3000 + 7;
int n;
pair<int, int> seg[N];
string s[N], t[N];


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i];
  for (int i = 1; i <= n; i++) cin >> t[i];
  for (int i = 1; i <= n; i++) assert((int) s[i].size() == (int) t[i].size());

  set<pair<string, string>> prs;

  vector<int> inds;

  for (int i = 1; i <= n; i++) {
    if (s[i] != t[i]) {
      string a = s[i], b = t[i];
      int l = 0, r = (int) a.size() - 1;
      while (l <= r) {
        if (a[l] == b[l]) {l++; continue;}
        if (a[r] == b[r]) {r--; continue;}
        break;
      }
      assert(l <= r);
      prs.insert({getstr(a, l, r), getstr(b, l, r)});
      seg[i] = {l, r};
      inds.push_back(i);
    } else {
      seg[i] = {-1, -1};
    }
  }

  assert((int) prs.size() > 0);

  if ((int) prs.size() != 1) {
    cout << "NO\n";
    return 0;
  }

  { /// l--;
    while (1) {
      bool ok = 1;
      for (auto &i : inds) {
        if (seg[i].first == 0) {
          ok = 0;
        }
      }
      if (!ok) {
        break;
      }
      set<pair<char, char>> kek;
      for (auto &i : inds) {
        kek.insert({s[i][seg[i].first - 1], t[i][seg[i].first - 1]});
      }
      if ((int) kek.size() != 1) {
        break;
      }
      for (auto &i : inds) {
        seg[i].first--;
      }
    }
  }
  { /// r++;
    while (1) {
      bool ok = 1;
      for (auto &i : inds) {
        if (seg[i].second == (int) s[i].size() - 1) {
          ok = 0;
        }
      }
      if (!ok) {
        break;
      }
      set<pair<char, char>> kek;
      for (auto &i : inds) {
        kek.insert({s[i][seg[i].second + 1], t[i][seg[i].second + 1]});
      }
      if ((int) kek.size() != 1) {
        break;
      }
      for (auto &i : inds) {
        seg[i].second++;
      }
    }
  }

  string first, second;
  assert(!inds.empty());

  for (int j = seg[inds[0]].first; j <= seg[inds[0]].second; j++) {
    first += s[inds[0]][j];
    second += t[inds[0]][j];
  }
  for (int i = 1; i <= n; i++) {
    auto it = kmp(s[i], first);
    if (it.empty()) {
      continue;
    }
    int l = it[0], r = it[0] + (int) first.size() - 1;
    for (int j = l; j <= r; j++) {
      s[i][j] = second[j - l];
    }
    if (s[i] != t[i]) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  cout << first << "\n";
  cout << second << "\n";


  return 0;
}