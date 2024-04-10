#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home = 1;

const int N = (int) 1e6 + 7;
const int INF = (int) 1e9;
int n, dinit, y, dp[N];
vector<pair<int, int>> v;
vector<pair<int, int>> ginv[N];
vector<pair<int, int>> g[N];

bool cmp(pair<int, int> a, pair<int, int> b) {
  return a.second < b.second;
}

int aib[N], extra;

void add(int i, int x) {
  while (i < N) aib[i] += x, i += i & (-i);
}

int get(int i) {
  assert(i < N);
  int sol = 0;
  while (i) sol += aib[i], i -= i & (-i);
  return sol;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("input", "r", stdin);
  }

  ///map<int, int> mp;
  cin >> n >> dinit;
  vector<pair<int, int>> cox;
  cox.push_back({dinit, -1});
  for (int i = 1; i <= n; i++) {
    int s, d;
    cin >> s >> d;
    if (s < dinit) continue;
    if (d <= dinit) {extra++; continue;}
    cox.push_back({s, (int) v.size() * 2});
    cox.push_back({d, (int) v.size() * 2 + 1});
    v.push_back({s, d});
  }
  sort(cox.begin(), cox.end());
  int cnt = 0;
  for (int j = 0; j < (int) cox.size(); j++) {
    if (j == 0 || (j > 0 && cox[j].first != cox[j - 1].first)) cnt++;
    if (cox[j].second == -1) {
      dinit = cnt;
    }
    else {
      if (cox[j].second & 1) v[cox[j].second / 2].second = cnt;
      else v[cox[j].second / 2].first = cnt;
    }
  }
  y = cnt;
  for (int i = 1; i < y; i++) {
    g[i].push_back({i + 1, 0});
  }

  vector<pair<int, int>> segs;

  for (auto &it : v) {
    int s = it.first, d = it.second;
    if (s <= d) {
      g[s].push_back({d, 1});
    } else {

      /// dinit <= s
      ///     d <  s
      /// dinit ajunge pana la d si dupa creste cu 1 ca bonus
      /// [d, s] fiecare din [d, s] primeste un bonus unic

      /// s > d

      segs.push_back({d, s});
    }
  }

  for (int i = 1; i <= y; i++) {
    for (auto &it : g[i]) {
      ginv[it.first].push_back({i, it.second});
    }
  }

  n = y;

  sort(segs.begin(), segs.end(), cmp);


  for (auto &seg : segs) {
    add(seg.first, 1);
  }

  int ptr = 0;
  for (int j = 1; j <= y; j++) {
    while (ptr < (int) segs.size() && segs[ptr].second < j) add(segs[ptr].first, -1), ptr++;
    for (auto &it : ginv[j]) {
      int i = it.first;
     /// cout << i << " and " << j << " : " << get(j) - get(i) << "\n";
      it.second += get(j) - get(i);
    }
  }



  for (int i = 1; i <= y; i++) {
    dp[i] = -INF;
  }

  int sol = 0;
  dp[dinit] = 0;

  for (int i = 1; i <= y; i++) {
    for (auto &j : ginv[i]) {
      dp[i] = max(dp[i], dp[j.first] + j.second);
    }
    sol = max(sol, dp[i]);
  }

  cout << sol + extra << "\n";

  return 0;
}