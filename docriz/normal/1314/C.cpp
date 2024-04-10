#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

//  [l, r]  check(x) == true  x
int bs_biggest(int l, int r, function<bool(int)> check) {
  assert(l <= r);
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (check(mid)) l = mid; else r = mid - 1;
  }
  return l;
}

//  [l, r]  check(x) == true  x
int bs_smallest(int l, int r, function<bool(int)> check) {
  assert(l <= r);
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid; else l = mid + 1;
  }
  return l;
}

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()

using ll = long long;

// s start from 1
vector<pair<int, int>> sort_all_substrings(int n, string s) {
  assert((int)s.size() == n + 1);
  vector<pair<int, int>> ord;
  rep(i, 1, n + 1) rep(j, i, n + 1) ord.push_back({i, j});
  vector<vector<int>> lcp(n + 2, vector<int>(n + 2));
  for (int i = n; i >= 1; i--) {
    for (int j = n; j >= 1; j--) {
      if (i == j) lcp[i][j] = n - i + 1;
      else lcp[i][j] = (s[i] == s[j] ? lcp[i + 1][j + 1] + 1 : 0);
    }
  }
  sort(ord.begin(), ord.end(), [&](const pair<int, int>&a, const pair<int, int>& b) {
    int len1 = a.y - a.x + 1;
    int len2 = b.y - b.x + 1;
    if (lcp[a.x][b.x] >= min(len1, len2)) {
      if (len1 == len2) return false;
      return len1 == min(len1, len2);
    } else {
      return s[a.x + lcp[a.x][b.x]] < s[b.x + lcp[a.x][b.x]];
    }
  });
  return ord;
}

void my_main() {
  int n, m;
  ll k;
  cin >> n >> m >> k;
  string s;
  cin >> s;
  s = "#" + s;
  vector<pair<int, int>> ord = sort_all_substrings(n, s);
  int p = bs_smallest(0, sz(ord) - 1, [&](int x) -> bool {
    vector<vector<ll>> dp(n + 2, vector<ll>(m + 2));
    vector<int> to(n + 1);
    for (int i = 0; i <= n; i++) to[i] = i + 1;
    for (int i = 0; i <= x; i++) {
      to[ord[i].x - 1] = max(to[ord[i].x - 1], ord[i].y + 1);
    }
    dp[0][0] = 1;
    for (int j = 0; j <= m; j++) {
      if (j) for (int i = 1; i <= n; i++) {
        dp[i][j] += dp[i - 1][j];
        if (dp[i][j] > k) dp[i][j] = k;
      }
      for (int i = j; i <= n; i++) {
        if (to[i] <= n) {
          dp[to[i]][j + 1] += dp[i][j];
          if (dp[to[i]][j + 1] > k) {
            dp[to[i]][j + 1] = k;
          }
        }
      }
    }
    return dp[n][m] < k;
  });
  cout << s.substr(ord[p].x, ord[p].y - ord[p].x + 1) << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);
  my_main();
  return 0;
}