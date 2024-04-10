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

using ll = long long;
using PII = pair<int, int>;
using PIL = pair<int, ll>;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define VL(n) vector<ll>(n)
#define VI(n) vector<int>(n)
#define VII(n, m) vector<vector<int>>(n, vector<int>(m))
#define VLL(n, m) vector<vector<ll>>(n, vector<ll>(m))
#define VIII(n, m, p) vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(p)))
#define VLLL(n, m, p) vector<vector<vector<ll>>>(n, vector<vector<ll>>(m, vector<ll>(p)))

/*
  find the biggest x that check(x) is true.
  time complexity: O(log(r-l))
  space commplexity: O(1)
*/
int bs_biggest(int l, int r, const function<bool(int)>& check) {
  assert(l <= r);
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (check(mid)) l = mid; else r = mid - 1;
  }
  return l;
}

/*
  find the smallest x that check(x) is true.
  time complexity: O(log(r-l))
  space commplexity: O(1)
*/
int bs_smallest(int l, int r, const function<bool(int)>& check) {
  assert(l <= r);
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid; else l = mid + 1;
  }
  return l;
}

const int MOD = (int)1e9 + 7;

int fexp(int a, int b) {
  int res = 1;
  for(int i = 1; i <= b; i <<= 1) {
    if(i & b) res = (ll)res * a % MOD;
    a = (ll)a * a % MOD;
  }
  return res;
}

int inv(int x) {
  return fexp(x, MOD - 2);
}

ll gcd(ll a, ll b) { 
  return b ? gcd(b, a % b) : a;
}

void my_main() {
  int n, m;
  cin >> n >> m;
  auto a = VII(n + 1, m + 1);
  rep(i, 1, n + 1) {
    string s;
    cin >> s;
    rep(j, 1, m + 1) {
      a[i][j] = s[j - 1] - '0';
    }
  }
  if (n >= 4 && m >= 4) {
    cout << -1 << "\n";
    return;
  }
  auto solve = [&](const vector<vector<int>>& a) -> int {
    int n = a.size() - 1;
    int m = a[0].size() - 1;
    assert(n <= m);
    if (n == 1) {
      return 0;
    } else if (n == 2) {
      auto dp = VII(m + 1, 4);
      rep(i, 1, m + 1) rep(j, 0, 4) dp[i][j] = INT_MAX;
      rep(j, 0, 4) {
        int x = j & 1;
        int y = (j >> 1) & 1;
        int cost = (a[1][1] != x) + (a[2][1] != y);
        dp[1][j] = cost;
      }
      rep(i, 2, m + 1) {
        rep(j, 0, 4) {
          int x = j & 1;
          int y = (j >> 1) & 1;
          int cost = (a[1][i] != x) + (a[2][i] != y);
          rep(k, 0, 4) {
            int x2 = k & 1;
            int y2 = (k >> 1) & 1;
            if ((x + y + x2 + y2) % 2 == 0) continue;
            dp[i][j] = min(dp[i][j], dp[i - 1][k] + cost);
          }
        }
      }
      int ret = INT_MAX;
      rep(j, 0, 4) ret = min(ret, dp[m][j]);
      return ret;
    } else {
      assert(n == 3);
      auto dp = VII(m + 1, 8);
      rep(i, 1, m + 1) rep(j, 0, 8) dp[i][j] = INT_MAX;
      rep(j, 0, 8) {
        int x = j & 1;
        int y = (j >> 1) & 1;
        int z = (j >> 2) & 1;
        int cost = (x != a[1][1]) + (y != a[2][1]) + (z != a[3][1]);
        dp[1][j] = cost;
      }
      rep(i, 2, m + 1) {
        rep(j, 0, 8) {
          int x = j & 1;
          int y = (j >> 1) & 1;
          int z = (j >> 2) & 1;
          int cost = (x != a[1][i]) + (y != a[2][i]) + (z != a[3][i]);
          rep(k, 0, 8) {
            int x2 = k & 1;
            int y2 = (k >> 1) & 1;
            int z2 = (k >> 2) & 1;
            if ((x + y + x2 + y2) % 2 == 0) continue;
            if ((y + z + y2 + z2) % 2 == 0) continue;
            dp[i][j] = min(dp[i][j], dp[i - 1][k] + cost);
          }
        }
      }
      int ret = INT_MAX;
      rep(j, 0, 8) ret = min(ret, dp[m][j]);
      return ret;
    }
  };
  int ans = 0;
  if (n > m) {
    auto b = VII(m + 1, n + 1);
    rep(i, 1, n + 1) rep(j, 1, m + 1) {
      b[j][i] = a[i][j];
    }
    ans = solve(b);
  } else {
    ans = solve(a);
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);
  my_main();
  return 0;
}