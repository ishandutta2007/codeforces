#include <bits/stdc++.h>

using namespace std;

void fastio() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

typedef long long ll;
const int N = 100000 + 7;
const int M = 333 + 7;
int n, m, q, bs, bk[N], lim[N][M], answer[N][M];
int first[M], last[M], bucket[N];
vector<int> gol[N];

int main() {
  fastio();
  cin >> n >> m;
  bs = sqrt(n);
  for (int i = 1; i <= n; i++) {
    bk[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int l, r;
    cin >> l >> r;
    gol[l].push_back(r);
    bk[r] = l;
  }
  for (int i = 1; i <= n; i++) {
    bucket[i] = (i - 1) / bs + 1;
    last[bucket[i]] = i;
  }
  for (int i = n; i >= 1; i--) {
    first[bucket[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    sort(gol[i].rbegin(), gol[i].rend());
    for (int j = bucket[1]; j <= bucket[n]; j++) {
      lim[i][j] = max(i, lim[i][j - 1]);
      while (!gol[i].empty() && gol[i].back() <= last[j]) {
        lim[i][j] = max(lim[i][j], gol[i].back());
        gol[i].pop_back();
      }
    }
  }
  for (int j = bucket[1]; j <= bucket[n]; j++) {
    vector<int> stk;
    for (int i = n; i >= 1; i--) {
      int cur = i;
      while (!stk.empty() && stk.back() <= lim[i][j]) {
        cur = max(cur, answer[stk.back()][j]);
        stk.pop_back();
      }
      answer[i][j] = cur;
      stk.push_back(i);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (bucket[l] == bucket[r]) {
      int x = l;
      for (int i = l + 1; i <= r; i++) {
        if (l <= bk[i] && bk[i] <= x) {
          x = i;
        }
      }
      cout << x << "\n";
    } else {
      int x = answer[l][bucket[r] - 1];
      for (int i = first[bucket[r]]; i <= r; i++) {
        if (l <= bk[i] && bk[i] <= x) {
          x = i;
        }
      }
      cout << x << "\n";
    }
  }
  return 0;
}