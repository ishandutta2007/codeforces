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
#define debug(...) 42

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

/*
  find the k-th array that satified f().
  time complexity: O(n^2*T(f))
  parameters: 
    f(int n, vector<int> a) should return the number of valid arrays,
    which the first n elements is a[1], a[2], ..., a[n].
    if no valid arrays start with those n elements, return 0.
  note:
    all the arrays(vectors) are 1-based!
    if the complexity is unacceptable, try read inside this function.
  example:
    // find the k-th permutation of length n.
    auto f = [&](int n, vector<int> a) -> ll{
      int m = sz(a);
      assert(m <= n);
      set<int> S;
      rep(i, 0, m) {
        if (S.count(a[i])) return 0;
        S.insert(a[i]);
      }
      ll fac = 1;
      rep(i, 1, n - m + 1) fac *= i;
      return fac; // return (n-m)!
    };
    debug(find_kth(5, 12, f)); // should be [1, 3, 5, 4, 2]
    debug(find_kth(5, 119, f)); // should be [5, 4, 3, 1, 2]
    debug(find_kth(5, 121, f)); // should be assertion failed.
*/
vector<int> find_kth(int n, ll k, const function<ll(int, vector<int>)>& f) {
  debug(n, k);
  vector<int> ret;
  assert(k <= f(n, ret));
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= n; j++) {
      ret.pb(j);
      assert(sz(ret) == i + 1);
      ll count = f(n, ret);
      debug(i, j, count);
      if (k > count) {
        k -= count;
      } else {
        break;
      }
      ret.pop_back();
    }
    assert(sz(ret) == i + 1);
  }
  return ret;
}

ll gcd(ll a, ll b) { 
  return b ? gcd(b, a % b) : a;
}

void my_main() {
  int T;
  cin >> T;
  const ll UPPER_BOUND = (ll)1e18 + 1;
  auto mul = [&](ll x, ll y) -> ll {
    if ((long double)x * (long double)y > UPPER_BOUND) {
      return UPPER_BOUND;
    }
    return x * y;
  };
  auto add = [&](ll x, ll y) -> ll {
    if (x + y > UPPER_BOUND) {
      return UPPER_BOUND;
    }
    return x + y;
  };
  auto f = VL(51);
  auto fac = VL(51);
  fac[0] = 1;
  f[0] = 1;
  rep(i, 1, 51) fac[i] = mul(fac[i - 1], i);
  rep(i, 1, 51) rep(j, 1, i + 1) {
    f[i] = add(f[i], mul((j >= 2 ? fac[j - 2] : 1), f[i - j]));
  }
  while (T--) {
    int n;
    ll k;
    cin >> n >> k;
    if (k > f[n]) {
      cout << -1 << "\n";
      continue;
    }
    function<vector<int>(int, ll)> solve;
    solve = [&](int n, ll k) -> vector<int> {
      vector<int> ret;
      if (k == 1) {
        rep(i, 0, n) ret.pb(i + 1);
        return ret;
      }
      // decide the first position
      rep(first, 1, n + 1) {
        ll cnt = mul((first >= 2 ? fac[first - 2] : 1), f[n - first]);
        if (k > cnt) {
          k -= cnt;
        } else {
          ll back = f[n - first];
          // (front_k - 1) * back + back_k = k
          // 1 <= back_k <= back
          ll front_k = k / back + 1;
          ll back_k = k % back;
          if (back_k == 0) {
            back_k += back;
            front_k -= 1;
          }
          ret = find_kth(first, front_k, [&](int n, vector<int> a) -> ll {
            int m = sz(a);
            debug(n, m, a);
            ll ret = (n - m >= 1 ? fac[n - m - 1] : 1);
            if (m == 0) return ret;
            if (a[0] != n) return 0;
            set<int> S;
            rep(i, 0, m) S.insert(a[i]);
            if (sz(S) != m) return 0;
            vector<int> fa(n + 1);
            rep(i, 1, n + 1) fa[i] = i;
            function<int(int)> find = [&](int x) -> int {
              if (fa[x] == x) return x;
              return fa[x] = find(fa[x]);
            };
            if (m < n) {
              rep(i, 0, m) {
                if (find(i + 1) == find(a[i])) return 0;
                fa[find(a[i])] = find(i + 1);
              }
            } else {
              rep(i, 0, n - 1) {
                if (find(i + 1) == find(a[i])) return 0;
                fa[find(a[i])] = find(i + 1);
              }
              if (find(n) != find(a[n - 1])) return 0;
            }
            return ret;
          });
          for (auto v: solve(n - first, back_k)) ret.pb(v + first);
          return ret;
        }
      }
      assert(false);
    };
    for (auto v: solve(n, k)) {
      cout << v << " ";
    }
    cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);
  my_main();
  return 0;
}