#include <bits/stdc++.h>

using namespace std;

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
#define VI(n) vector<int>(n)
#define VII(n, m) vector<vector<int>>(n, vector<int>(m))
#define VIII(n, m, p) vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(p)))

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

/*
  find the biggest x that check(x) is true.
  time complexity: O(log(r-l))
  space commplexity: O(1)
*/
int bs_biggest(int l, int r, function<bool(int)> check) {
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
int bs_smallest(int l, int r, function<bool(int)> check) {
  assert(l <= r);
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid; else l = mid + 1;
  }
  return l;
}

ll gcd(ll a, ll b) { 
  return b ? gcd(b, a % b) : a;
}

void my_main() {
  auto f = VI(5005);
  f[0] = 0, f[1] = 0, f[2] = 1;
  rep(i, 3, 5001) {
    if (__builtin_popcount(i) == 1) {
      f[i] = f[i - 1] + (f[i - 1] - f[i - 2] + 1);
    } else {
      f[i] = f[i - 1] + (f[i - 1] - f[i - 2]);
    }
  }
  auto g = VI(5005);
  g[0] = 0, g[1] = 0, g[2] = 1;
  rep(i, 3, 5001) {
    g[i] = g[i - 1] + (i - 1);
  }
  int T;
  cin >> T;
  while (T--) {
    int n, d;
    cin >> n >> d;
    auto good = [&](int n, int d) -> bool {
      return d >= f[n] && d <= g[n];
    };
    if (!good(n, d)) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      auto ans = VI(n + 1);
      function<void(int, int, int, int)> solve = [&](int cur, int fa, int n, int d) {
        if (n == 0) return;
        ans[cur] = fa;
        if (n == 1) {
          assert(d == 0);
          return;
        }
        rep(x, 0, n) {
          int min_y = max(f[x], d - (n - 1) - g[n - x - 1]);
          int max_y = min(g[x], d - (n - 1) - f[n - x - 1]);
          if (min_y <= max_y) {
            int y = min_y;
            solve(cur + 1, cur, x, y);
            solve(cur + x + 1, cur, n - 1 - x, d + 1 - n - y);
            break;
          }
        }
      };
      solve(1, 0, n, d);
      rep(i, 2, n + 1) cout << ans[i] << (i == n ? '\n' : ' ');
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);
  my_main();
  return 0;
}