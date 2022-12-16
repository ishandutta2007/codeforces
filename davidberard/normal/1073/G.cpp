#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

/**
 * 1. write suffix array
 * 2. write the O(1) or O(lg) suffix RMQ structure for getting LCP quickly
 * 3. for each query, sort the a's and b's by their index, and then sweep both directions
 */

struct SuffixArray {
  const static int L = 18;
  const static int N = 1<<L;
  const static ll A = 1e9+7;
  int p[L+1][N];
  int n;
  pair<ll, int> m[N];
  void build(string s) {
    n = s.size();
    for (int i=0;i<s.size(); ++i) {
      p[0][i] = s[i];
    }
    for (int l=0, j=1; l<L; j*=2, ++l) {
      for (int i=0; i<n; ++i) {
        m[i].first = A*p[l][i] + (j+i < n ? p[l][j+i] : -1);
        m[i].second = i;
      }
      sort(m, m+n);
      for (int i=0; i<n; ++i) {
        p[l+1][m[i].second] = i;
        if (i > 0 && m[i].first == m[i-1].first) {
          p[l+1][m[i].second] = p[l+1][m[i-1].second];
        }
      }
    }
  }
  int idx(int r) const {
    return p[L][r];
  }

  int lcp(int i, int j) {
    if (i == j) {
      return n-i;
    }
    int ans = 0;
    for (int l=L; l>=0; --l) {
      if (p[l][i] == p[l][j] && max(i, j) + (1<<l) <= n) {
        i += (1<<l);
        j += (1<<l);
        ans += (1<<l);
      }
    }
    return ans;
  }
};


SuffixArray sa;
const int INF = 0x3f3f3f3f;

ll solve(const vector<pair<int, int>>& vec) {
  vector<pair<ll, ll>> st;
  ll cv = 0;
  ll ans = 0;
  if (vec[0].second == 1) {
    st.push_back({INF, 1});
    cv += INF;
  }
  for (int i=1; i<vec.size(); ++i) {
    const auto [r, t] = vec[i];
    int comm = sa.lcp(vec[i].first, vec[i-1].first);
    ll res = 0;
    while(!st.empty() && st.back().first > comm) {
      cv -= st.back().first * st.back().second;
      res += st.back().second;
      st.pop_back();
    }
    cv += comm * res;
    if (!st.empty() && st.back().first == comm) {
      st.back().second += res;
    } else {
      st.push_back({comm, res});
    }

    if (t == 2) {
      ans += cv;
    } else {
      st.push_back({INF, 1});
      cv += INF;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  sa.build(s);
  while (q--) {
    int ka, kb;
    cin >> ka >> kb;
    vector<int> a(ka), b(kb);
    vector<pair<int, int>> vec;
    for (auto& x : a) {
      cin >> x;
      --x;
      vec.push_back({x, 1});
    }
    for (auto& x : b) {
      cin >> x;
      --x;
      vec.push_back({x, 2});
    }
    sort(vec.begin(), vec.end(), [](const pair<int, int>& xa, const pair<int, int>& xb) {
      return pair<int, int>(sa.idx(xa.first), xa.second) < pair<int, int>(sa.idx(xb.first), xb.second);
    });
    ll ans = solve(vec);
    reverse(vec.begin(), vec.end());
    ans += solve(vec);
    cout << ans << "\n";
  }
  return 0;
}