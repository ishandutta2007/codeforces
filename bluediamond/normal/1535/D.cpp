#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

///#define int ll

const int N = 1 << 20;
int n, result[N], id[N], curt, cnt[N], inv[N];
string initial;
vector<int> on[200];
///vector<int> nodes[N];

void place(int v, int tl, int tr, int level = 0) {
  if (tl == tr) {
    return;
  }
  on[level].push_back(v);
  int tm = (tl + tr) / 2;
  place(2 * v, tl, tm, level + 1);
  place(2 * v + 1, tm + 1, tr, level + 1);
}

void upd(int v, int tl, int tr, int i) {
  if (tr < i || i < tl) {
    return;
  }
  if (tl == tr) {
    cnt[v] = 1;
    return;
  } else {
    int tm = (tl + tr) / 2;
    upd(2 * v, tl, tm, i);
    upd(2 * v + 1, tm + 1, tr, i);
    int value = result[id[v]];
    if (value == -1) {
      cnt[v] = cnt[2 * v] + cnt[2 * v + 1];
    } else {
      if (value == 0) {
        cnt[v] = cnt[2 * v];
      } else {
        cnt[v] = cnt[2 * v + 1];
      }
    }
  }
}

signed main(){
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  cin >> n >> initial;
  n = (1 << n);

  place(1, 1, n);

  for (int i = 100; i >= 0; i--) {
    for (auto &x : on[i]) {
      id[x] = ++curt;
      inv[curt] = x;
    }
  }


  for (int i = 1; i < n; i++) {
    char ch = initial[i - 1];
    if (ch == '?') {
      result[i] = -1;
    } else {
      result[i] = ch - '0';
    }
  }

  for (int i = 1; i <= n; i++) {
    upd(1, 1, n, i);
  }

  int q;
  cin >> q;
  while (q--) {
    int i;
    string str;
    cin >> i >> str;
    char ch = str[0];
    if (ch == '?') {
      result[i] = -1;
    } else {
      result[i] = ch - '0';
    }
    int v = inv[i];
    while (v) {
      int value = result[id[v]];
      if (value == -1) {
        cnt[v] = cnt[2 * v] + cnt[2 * v + 1];
      } else {
        if (value == 0) {
          cnt[v] = cnt[2 * v];
        } else {
          cnt[v] = cnt[2 * v + 1];
        }
      }
      v /= 2;
    }
    ///upd(1, 1, n, i);
    cout << cnt[1] << "\n";
  }



  return 0;
}