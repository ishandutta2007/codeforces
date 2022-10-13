#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

pair<vector<int>, vector<int>> split(vector<int>& v) {
  static vector<bitset<1000000>> dp(1005);

  int n = v.size();
  for (int i = 0; i <= n; ++i) {
    dp[i].reset();
  }

  int total = 0;
  for (int i = 0; i < n; ++i)
    total += v[i];
  
  if (total % 2) return {{}, {}};
  
  dp[0][0] = true;
  for (int i = 0; i < n; ++i) {
    dp[i + 1] |= dp[i];
    dp[i + 1] |= (dp[i] << v[i]);
  }

  if (!dp[n][total / 2]) return {{}, {}};
  vector<int> a, b;
  int rem = total / 2;
  for (int i = n - 1; i >= 0; --i) {
    assert(dp[i + 1][rem]);
    if (dp[i][rem]) b.push_back(v[i]);
    else {
      rem -= v[i];
      a.push_back(v[i]);
    }
  }
  return {a, b};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> hor(n, -1);
    for (int i = 0; i < n; ++i)
      cin >> hor[i];

    int m; cin >> m;
    vector<int> ver(m, -1);
    for (int i = 0; i < m; ++i)
      cin >> ver[i];

    if (n != m) {
      cout << "No\n";
      continue;
    }

    auto [l, r] = split(hor);
    auto [u, d] = split(ver);
    if (u.size() < d.size()) swap(u, d);
    if (l.size() < r.size()) swap(l, r);
    if (u.empty() || l.empty()) {
      cout << "No" << '\n';
      continue;
    } 

    // cerr << "u: "; for (auto x : u) cerr << x << " "; cerr << endl;
    // cerr << "d: "; for (auto x : d) cerr << x << " "; cerr << endl;
    // cerr << "l: "; for (auto x : l) cerr << x << " "; cerr << endl;
    // cerr << "r: "; for (auto x : r) cerr << x << " "; cerr << endl;


    sort(u.begin(), u.end());
    sort(d.rbegin(), d.rend());
    sort(r.rbegin(), r.rend());
    sort(l.begin(), l.end());

    vector<int> remx, remy;

    vector<pair<int, int>> lower = {{0, 0}};
    for (int i = 0; i < max(r.size(), u.size()); ++i) {
      if (i < min(r.size(), u.size())) {
        {
          auto [x, y] = lower.back();
          lower.emplace_back(x + r[i], y);
        }
        {
          auto [x, y] = lower.back();
          lower.emplace_back(x, y + u[i]);
        }
      } else {
        if (i < u.size()) remy.push_back(u[i]);
        else remx.push_back(r[i]);
      }
    }
    vector<pair<int, int>> upper = {{0, 0}};
    for (int i = 0; i < max(d.size(), l.size()); ++i) {
      if (i < min(d.size(), l.size())) {
        {
          auto [x, y] = upper.back();
          upper.emplace_back(x, y + d[i]);
        }
        {
          auto [x, y] = upper.back();
          upper.emplace_back(x + l[i], y);
        }
      } else {
        if (i < d.size()) remy.push_back(-d[i]);
        else remx.push_back(-l[i]);
      }
    }

    assert(remx.size() == remy.size());
    for (int i = 0; i < (int)remx.size(); ++i) {
      {
        auto [x, y] = lower.back();
        lower.emplace_back(x + remx[i], y);
      }
      {
        auto [x, y] = lower.back();
        lower.emplace_back(x, y + remy[i]);
      }
    }

    // cerr << "lower: " << endl;
    // for (auto [x, y] : lower) cerr << x << " " << y << '\n';
    //   cerr << endl;
    // cerr << 
    // for (auto [x, y] : upper) cerr << x << " " << y << '\n';
    //   cerr << endl;
    assert(lower.back() == upper.back());
    reverse(upper.begin(), upper.end());
    upper.pop_back();
    lower.pop_back();

    cout << "Yes" << '\n';  
    for (auto [x, y] : lower) cout << x << " " << y << '\n';
    for (auto [x, y] : upper) cout << x << " " << y << '\n';
  }

  return 0;
}