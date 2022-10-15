#include <bits/stdc++.h>

bool home = 1;

using namespace std;

typedef long long ll;




const int N = (int) 1e6 + 7;
int n;
int sub[N];
vector<int> g[N];

void build(int a, int p = -1) {
  sub[a] = 1;
  for (auto &b : g[a]) {
    if (b == p) continue;
    build(b, a);
    sub[a] += sub[b];
  }
}

int fcen(int a, int p = -1) {
  int mx = n - sub[a];
  for (auto &b : g[a]) {
    if (b == p) continue;
    mx = max(mx, sub[b]);
  }
  if (mx <= n / 2) {
    return a;
  }
  for (auto &b : g[a]) {
    if (b == p) continue;
    if (mx == sub[b]) {
      return fcen(b, a);
    }
  }
  cout << "no cen found\n";
  exit(0);
}

bitset<N / 2> ok;

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin >> n;
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    g[p].push_back(i);
    g[i].push_back(p);
  }

  build(1);
  int cen = fcen(1);

  for (int i = 1; i <= n; i++) {
    i = cen;
    build(i);
    ll S = 0;
    for (int j = 1; j <= n; j++) {
      S += sub[j];
    }
    ok = 0;
    ok[0] = 1;
    vector<int> Vb, V;
    for (auto &j : g[cen]) {
      Vb.push_back(sub[j]);
    }
    sort(Vb.begin(), Vb.end());

    {
      int l = 0;
      while (l < (int) Vb.size()) {
        int r = l;
        while (r + 1 < (int) Vb.size() && Vb[r + 1] == Vb[r]) {
          r++;
        }
        int cnt = r - l + 1, i = Vb[l];
        for (int bit = 0; (1 << bit) <= cnt; bit++) {
          cnt -= (1 << bit);
          int x = (1 << bit) * i;
          V.push_back(x);
        }
        if (cnt) {
          int x = cnt * i;
          V.push_back(x);
        }

        l = r + 1;
      }
    }
    sort(V.begin(), V.end());
    for (auto &x : V) {
      ok = ok | (ok << x);
    }
    ll best = S;
    for (int j = 0; j <= n / 2; j++) {
      if (ok[j]) {
        best = max(best, S + j * (ll) (n - 1 - j));
      }
    }
    cout << best << "\n";
    return 0;
  }
}