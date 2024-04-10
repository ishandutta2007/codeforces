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
#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()

void my_main() {
  int n;
  cin >> n;
  map<int, vector<int>> M;
  vector<pair<int, int>> a(n + 1);
  int min_v = INT_MAX;
  rep(i, 1, n + 1) {
    cin >> a[i].x;
    min_v = min(min_v, a[i].x);
  }
  rep(i, 1, n + 1) cin >> a[i].y;
  rep(i, 1, n + 1) {
    M[a[i].x].push_back(a[i].y);
  }
  sort(a.begin() + 1, a.end());
  long long ans = 0;
  long long sum = 0;
  int cnt = 0;
  multiset<int> S;
  for (int cur = min_v; ;) {
    for (auto v: M[cur]) {
      S.insert(v);
      sum += v;
    }
    if (S.empty()) {
      auto it = lower_bound(a.begin() + 1, a.end(), mp(cur, INT_MIN));
      cur = it->first;
      continue;
    }
    /*
    debug(cur);
    for (auto v: S) {
      cout << v << " ";
    }
    cout << endl;
    */
    auto it = S.end();
    --it;
    sum -= *it;
    S.erase(it);
    ++cnt;
    ans += sum;
    ++cur;
    if (cnt == n) break;
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