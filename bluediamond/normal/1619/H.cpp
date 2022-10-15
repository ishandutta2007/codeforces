#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
const int R = 333;

int n;
int q;
int p[N];
int inv[N];
int skip[N];

void compute(int i) {
  skip[i] = i;
  for (int j = 1; j <= R; j++) {
    skip[i] = p[skip[i]];
  }
}

void upd(int i) {
  vector<int> all;
  for (int it = 1; it <= R; it++) {
    all.push_back(i);
    i = inv[i];
  }
  reverse(all.begin(), all.end());
  compute(all[0]);
  for (int it = 1; it < (int) all.size(); it++) {
    skip[all[it]] = p[skip[all[it - 1]]];
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    inv[p[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    compute(i);
  }

  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, y;
      cin >> x >> y;
      swap(p[x], p[y]);

      inv[p[x]] = x;
      inv[p[y]] = y;

      upd(x);
      upd(y);

    } else {
      int i, k;
      cin >> i >> k;
      for (int j = 1; j <= k / R; j++) {
        i = skip[i];
      }
      for (int j = 1; j <= k % R; j++) {
        i = p[i];
      }
      cout << i << "\n";
    }
  }


  exit(0);
}