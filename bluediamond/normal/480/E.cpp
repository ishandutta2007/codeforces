#include <bits/stdc++.h>

using namespace std;

const int N = 2000 + 7;
int n, m, k, a[N][N], rr[N], cc[N], st[N][N], dr[N][N], nemo[N], retg;

void updr(int r) {
  int cnt = 0;
  for (int c = 1; c <= m; c++) {
    if (a[r][c]) cnt = 0;
    else cnt++;
    st[r][c] = cnt;
  }
  cnt = 0;
  for (int c = m; c >= 1; c--) {
    if (a[r][c]) cnt = 0;
    else cnt++;
    dr[r][c] = cnt;
  }
}

int univ;
int histo1[N], histo2[N], cnt, first;
deque<int> d1, d2;

int lungime() {
  return univ - first + 1;
}

int inaltime() {
  return histo1[d1.front()] + histo2[d2.front()] - 1;
}

int getc(int col) {
  cnt = n;
  for (int i = 1; i <= cnt; i++) {
    histo1[i] = st[i][col];
    histo2[i] = dr[i][col];
  }
  first = 1;
  d1.clear(), d2.clear();
  int ret = 0;
  for (int i = 1; i <= cnt; i++) {
    if (histo1[i] == 0 || histo2[i] == 0) {
      first = i + 1;
      d1.clear();
      d2.clear();
      continue;
    }
    univ = i;
    while (!d1.empty() && histo1[d1.back()] >= histo1[i]) d1.pop_back(); d1.push_back(i);
    while (!d2.empty() && histo2[d2.back()] >= histo2[i]) d2.pop_back(); d2.push_back(i);
    while (1) {
      ret = max(ret, min(lungime(), inaltime()));
      if (lungime() > inaltime()) {
        first++;
        while (!d1.empty() && d1.front() < first) d1.pop_front();
        while (!d2.empty() && d2.front() < first) d2.pop_front();
      } else {
        break;
      }
    }
  }
  return ret;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++) {
      a[i][j] = (s[j - 1] == 'X');
    }
  }
  for (int i = 1; i <= k; i++) {
    cin >> rr[i] >> cc[i];
    a[rr[i]][cc[i]] = 1;
  }
  for (int i = 1; i <= n; i++) updr(i);
  for (int i = 1; i <= m; i++) retg = max(retg, getc(i));
  for (int id = k; id >= 1; id--) {
    int r = rr[id], c = cc[id];
    nemo[id] = retg;
    a[r][c] = 0;
    updr(r);
    retg = max(retg, getc(c));
  }
  for (int i = 1; i <= k; i++) {
    cout << nemo[i] << "\n";
  }
}