#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;
int n;
int k;
int a[N], have[N];
int under_0_frq[N];
multiset<int> cnt_in_order;

pair<int, int> aib[N];

pair<int, int> operator + (pair<int, int> a, pair<int, int> b) {
  return {a.first + b.first, a.second + b.second};
}

void add(int i, pair<int, int> x) {
  while (i <= n) {
    aib[i] = aib[i] + x;
    i += i & (-i);
  }
}

pair<int, int> get(int i) {
  pair<int, int> sol = {0, 0};
  while (i) {
    sol = sol + aib[i];
    i -= i & (-i);
  }
  return sol;
}

int get_max(int gold) {
  pair<int, int> cur;
  int pos = 0;
  for (int step = (1 << 20); step; step /= 2) {
    if (pos + step <= n && cur.second + aib[pos + step].second <= gold) {
      pos += step;
      cur = cur + aib[pos];
    }
  }
  pos++;

  int take = cur.first;
  if (pos <= n) {
    take += min((gold - cur.second) / pos, have[pos]);
  }

  return take;
}

void add(int cnt) {
  cnt_in_order.insert(cnt);
  have[cnt]++;
  add(cnt, {1, cnt});
}


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("___input___", "r", stdin);

  const int inf = (int) 1e9 + 7;

  int tests;
  cin >> tests;
  for (int tc = 1; tc <= tests; tc++) {
    cnt_in_order.clear();
    map<int, int> f;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      f[a[i]]++;
      have[i] = 0;
      aib[i] = {0, 0};
    }
    vector<pair<int, int>> prs;
    for (auto &it : f) {
      prs.push_back(it);
    }


    for (int x = 0; x <= n; x++) {
      under_0_frq[x] = (!f.count(x));
      if (x > 0) under_0_frq[x] += under_0_frq[x - 1];
    }

    int sol = inf;

    for (int mex = n; mex >= 0; mex--) {
      while (!prs.empty() && prs.back().first > mex) {
        add(prs.back().second);
        prs.pop_back();
      }
      int need_to_make_not_0 = ((mex == 0) ? (0) : (under_0_frq[mex - 1]));
      int need_to_kill_mex = f[mex];


      int need = max(need_to_kill_mex, need_to_make_not_0);

      if (need > k) continue;

      int av = k - need + need_to_make_not_0;
      int init = av;

      int killed = 0;
      killed = get_max(init);

      int diff = mex + (int) cnt_in_order.size() - killed;

      if (diff == 0) diff = 1;
      sol = min(sol, diff - mex);
    }


    cout << sol << "\n";
  }


  return 0;
}