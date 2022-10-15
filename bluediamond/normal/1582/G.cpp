#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home = 1;
///#define int ll


const int N = (int) 1e6 + 7;
int n, a[N], b[N], lim[4 * N];
vector<int> primes;
int lp[N];

/**

1 = mult
2 = div
**/

void build(int v, int tl, int tr) {
  lim[v] = n;
  if (tl < tr) {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
  }
}

void force(int v, int tl, int tr, int l, int r, int x) {
  if (tr < l || r < tl) return;
  if (l <= tl && tr <= r) {
    lim[v] = min(lim[v], x);
    return;
  }
  int tm = (tl + tr) / 2;
  force(2 * v, tl, tm, l, r, x);
  force(2 * v + 1, tm + 1, tr, l, r, x);
}

void force(int l, int r, int x) {
  force(1, 1, n, l, r, x);
}

int get(int v, int tl, int tr, int i) {
  if (tr < i || i < tl) return n;
  int sol = lim[v];
  if (tl < tr) {
    int tm = (tl + tr) / 2;
    sol = min(sol, get(2 * v, tl, tm, i));
    sol = min(sol, get(2 * v + 1, tm + 1, tr, i));
  }
  return sol;
}

vector<pair<int, int>> cool[N];
int cur[N], suf[N], first[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("input", "r", stdin);
  }

  for (int i = 2; i < N; i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      primes.push_back(i);
    }
    for (int j = 0; j < (int) primes.size() && primes[j] <= lp[i] && primes[j] * i < N; j++) {
      lp[primes[j] * i] = primes[j];
    }
  }


  cin >> n;
  build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int num = a[i];
    while (num > 1) {
      int p = lp[num], cnt = 0;
      while (num % p == 0) {
        num /= p;
        cnt++;
      }
      cool[p].push_back({i, cnt});
    }
  }

  {
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++) {
      char ch = s[i - 1];
      if (ch == '*') b[i] = 1;
      else b[i] = 2;
    }
  }

  for (int p = 1; p < N; p++) {
    if (cool[p].empty()) continue;
    vector<int> pos;
    for (auto &it : cool[p]) {
      pos.push_back(it.first);
      if (b[it.first] == 1) cur[it.first] = it.second;
      else cur[it.first] = -it.second;
    }
    int y = (int) pos.size();
    vector<pair<int, int>> segs;
    if (pos[0] > 1) {
      segs.push_back({1, pos[0] - 1});
    }
    for (int i = 0; i + 1 < y; i++) {
      segs.push_back({pos[i], pos[i + 1] - 1});
    }
    segs.push_back({pos[y - 1], n});
    {
      int sz = 0;
      for (auto &it : segs) sz += it.second - it.first + 1;
    }
    y = (int) segs.size();
    suf[y] = 0;
    for (int i = y - 1; i >= 0; i--) {
      suf[i] = suf[i + 1] + cur[segs[i].first];
    }
    vector<int> stk;
    for (int i = y; i >= 0; i--) {
      while (!stk.empty() && suf[i] >= suf[stk.back()]) stk.pop_back();
      if (stk.empty()) first[i] = -1;
      else first[i] = stk.back();
      stk.push_back(i);
    }
    for (int i = y - 1; i >= 0; i--) {
      /// only segs[i].first !!
      if (first[i] != -1) {
        int j = first[i];
        force(segs[i].first, segs[i].first, segs[j - 1].first - 1);
      }

      if (segs[i].first + 1 <= segs[i].second) { /// all the others
        if (first[i + 1] != -1) {
          int j = first[i + 1];
          force(segs[i].first + 1, segs[i].second, segs[j - 1].first - 1);
        }
      }
    }
    for (auto &it : cool[p]) {
      cur[it.first] = 0;
    }
  }



  long long sol = 0;
  for (int i = 1; i <= n; i++) {
    int r = get(1, 1, n, i);
    if (r >= i) {
      sol += r - i + 1;
    }
  }
  cout << sol << "\n";

  return 0;
}
/**



**/