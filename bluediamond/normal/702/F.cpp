#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;

struct rtx {
  int c;
  int q;
};

bool operator < (rtx a, rtx b) {
  if (a.q != b.q) return a.q > b.q;
  return a.c < b.c;
}

int n, a[N];
rtx vv[N];
int sumlight[30][N];
int tab[30][20][N];
int cnt[30][N], total[30][N];
int lg[N];
const int INF = (int) 1e9 + 7;
int value[30][N];

int add(int a, int b) {
  return min(a + b, INF);
}

int cntlight(int kk, int l, int r) {
  return (total[kk][r] - total[kk][l - 1]) - (cnt[kk][r] - cnt[kk][l - 1]);
}

int light(int kk, int l, int r) {
  return sumlight[kk][r] - sumlight[kk][l - 1];
}


int cu(int kk, int l, int r) {
  int k = lg[r - l + 1];
  return sumlight[kk][r] - sumlight[kk][l - 1] + value[kk][r];
}

int gmin(int kk, int l, int r) {
  int k = lg[r - l + 1];
  return min(tab[kk][k][l], tab[kk][k][r - (1 << k) + 1]);
}

bool is(int k, int x, int pos, int i) {
  int l = (1 << k);
  int val = light(k, pos, i);
  if (x - val < l) {
    return 1;
  }

  val = gmin(k, pos, i);
  if (val <= x + sumlight[k][pos - 1]) {
    return 1;
  }
  return 0;
}



int solve(int x, int pos) {
  if (x == 0) return 0;
  int k = log2(x), l = (1 << k), r = 2 * l - 1;

  int lo = pos, hi = n, sol = -1;
  while (lo <= hi) {
    int i = (lo + hi) / 2;
    if (is(k, x, pos, i)) {
      sol = i;
      hi = i - 1;
    } else {
      lo = i + 1;
    }
  }
  if (sol != -1) {
    int i = sol;
    int val = light(k, pos, i);
    if (x - val < l) {
      return cntlight(k, pos, i) + solve(x - val, i + 1);
    }

    val = gmin(k, pos, i);
    if (val <= x + sumlight[k][pos - 1]) {
      return cntlight(k, pos, i) + 1 + solve(x + sumlight[k][pos - 1] - val, i + 1);
    }
  }

  /// daca am ajuns la sfarsit inseamna ca nu am gasit nimic asa => le iau pe toate light care sunt in numar de total - cnt heavy
  return cntlight(k, pos, n);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  //freopen ("input", "r", stdin);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> vv[i].c >> vv[i].q;
  }
  sort(vv + 1, vv + n + 1);

  for (int i = 1; i <= n; i++) {
    a[i] = vv[i].c;
  }

  for (int i = 2; i <= n; i++) {
    lg[i] = 1 + lg[i / 2];
  }

  for (int kk = 0; kk < 30; kk++) {
    int l = (1 << kk), r = (1 << (kk + 1)) - 1;
    for (int i = 1; i <= n; i++) {
      value[kk][i] = INF;
      sumlight[kk][i] = sumlight[kk][i - 1];
      cnt[kk][i] = cnt[kk][i - 1];
      total[kk][i] = total[kk][i - 1];


      if (a[i] <= r) {
        total[kk][i]++;
        if (a[i] > l) {
          cnt[kk][i]++;
          value[kk][i] = a[i];
        } else {
          sumlight[kk][i] = add(sumlight[kk][i], a[i]);
        }
      }

      tab[kk][0][i] = sumlight[kk][i] + value[kk][i];

    }
    for (int k = 1; (1 << k) <= n; k++) {
      for (int i = 1; i + (1 << k) - 1 <= n; i++) {
        tab[kk][k][i] = min(tab[kk][k - 1][i], tab[kk][k - 1][i + (1 << (k - 1))]);
      }
    }
  }

  int k;
  cin >> k;
  while (k--) {
    int x, sol = 0;
    cin >> x;
    cout << solve(x, 1) << " ";
  }
  cout << "\n";

  return 0;
}