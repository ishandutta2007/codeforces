#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
bool home = 1;

struct T {
  int mn;
  int mx;
  int ind;
  T() {
    mn = (int) 1e9;
    mx = -mn;
  }
  T(int x) {
    mn = mx = x;
  }
};

T operator + (T a, T b) {
  a.mn = min(a.mn, b.mn);
  a.mx = max(a.mx, b.mx);
  return a;
}

bool cmpBIG(T a, T b) {
  return a.mx < b.mx;
}

void solvetest() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int> (m));
  vector<vector<T>> prefvaa(n, vector<T> (m)), sufvaa(n, vector<T> (m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      prefvaa[i][j] = sufvaa[i][j] = a[i][j];
      if (j) prefvaa[i][j] = prefvaa[i][j - 1] + prefvaa[i][j];
    }
    for (int j = m - 2; j >= 0; j--) {
      sufvaa[i][j] = sufvaa[i][j + 1] + sufvaa[i][j];
    }
  }
  for (int splitcol = 0; splitcol < m - 1; splitcol++) {
    vector<T> pref(n), suf(n);
    for (int i = 0; i < n; i++) {
      pref[i] = prefvaa[i][splitcol];
      suf[i] = sufvaa[i][splitcol + 1];
      pref[i].ind = i;
      suf[i].ind = i;
    }
    sort(pref.begin(), pref.end(), cmpBIG);
    vector<T> sfpref = pref;
    for (int i = n - 2; i >= 0; i--) {
      sfpref[i] = sfpref[i] + sfpref[i + 1];
    }
    vector<int> p2(n), s2(n);
    for (int i = 0; i < n; i++) {
      p2[i] = suf[pref[i].ind].mn;
      if (i) p2[i] = min(p2[i - 1], p2[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
      s2[i] = suf[pref[i].ind].mx;
      if (i < n - 1) s2[i] = max(s2[i + 1], s2[i]);
    }
    for (int split = 0; split < n - 1; split++) {
      int mx = pref[split].mx;
      bool ok = 1;
      ok &= (mx < sfpref[split + 1].mn);
      ok &= (s2[split + 1] < p2[split]);

      if (ok) {
        cout << "YES\n";
        string sol(n, 'a');
        for (int i = 0; i < n; i++) {
          sol[pref[i].ind] = (i <= split) ? 'B' : 'R';
        }
        cout << sol << " " << splitcol + 1 << "\n";
        return;
      }
    }
  }
  cout << "NO\n";
}
signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ///
  }

  int tt;
  cin >> tt;
  while (tt--) {
    solvetest();
  }

  return 0;
}