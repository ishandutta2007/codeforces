#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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

// binary search the biggest x that check(x) is true.
int bs_biggest(int l, int r, function<bool(int)> check) {
  assert(l <= r);
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (check(mid)) l = mid; else r = mid - 1;
  }
  return l;
}

// binary search the smallest x that check(x) is true.
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

/*
  get mu(1), mu(2), ..., mu(n).
  time complexity: O(n).
  space complexity: O(n).
*/
vector<int> get_mu(int n) {
  auto mu = VI(n + 1);
  auto min_factor = VI(n + 1);
  vector<int> prime;
  mu[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!min_factor[i]) {
      prime.pb(i);
      min_factor[i] = sz(prime);
      mu[i] = -1;
    }
    for (int j = 1; ; j++) {
      int t = i * prime[j - 1];
      if (t > n) break;
      min_factor[t] = j;
      if (j == min_factor[i]) {
        mu[t] = 0;
        break;
      }
      mu[t] = -mu[i];
    }
  }
  return mu;
}


/*
  find the max value of x * y that gcd(x, y) == 1.
  time complexity: O(nlogn + vlogv).
  space complexity: O(n + vlogv).
  v is the max element in vals.

  depends on: get_mu(int).
*/
ll biggest_coprime_prod(vector<int> vals) {
  if (sz(vals) < 2) return 0;
  sort(vals.begin(), vals.end(), greater<int>());
  int max_v = vals[0];
  auto mu = get_mu(max_v + 1);
  auto cnt = VI(max_v + 1);
  vector<vector<int>> divs(max_v + 1);
  rep(i, 1, max_v + 1) {
    for (int j = i; j <= max_v; j += i) divs[j].pb(i);
  }
  auto coprime_count = [&](int x) -> int {
    int ret = 0;
    for (auto d: divs[x]) {
      ret += mu[d] * cnt[d];
    }
    return ret;
  };
  auto update = [&](int x, int v) -> void {
    for (auto d: divs[x]) cnt[d] += v;
  };
  stack<int> S;
  ll ret = 0;
  for (auto v: vals) {
    int c = coprime_count(v);
    while (c) {
      if (gcd(v, S.top()) == 1) {
        ret = max(ret, (ll)v * S.top());
        --c;
      }
      update(S.top(), -1);
      S.pop();
    }
    update(v, 1);
    S.push(v);
  }
  return ret;
}

void my_main() {
  int n;
  cin >> n;
  auto a = VI(n + 1);
  ll ans = 0;
  rep(i, 1, n + 1) {
    cin >> a[i];
    ans = max(ans, (ll)a[i]);
  }
  int max_v = *max_element(a.begin() + 1, a.end());
  auto cnt = VI(max_v + 1);
  rep(i, 1, n + 1) ++cnt[a[i]];
  rep(i, 1, max_v + 1) {
    vector<int> vals;
    for (int j = i; j <= max_v; j += i) {
      if (cnt[j]) vals.pb(j / i);
    }
    if (vals.empty()) continue;
    ans = max(ans, biggest_coprime_prod(vals) * i);
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);
  my_main();
  return 0;
}