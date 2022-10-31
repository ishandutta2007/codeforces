#include <bits/stdc++.h>
#define int long long
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

using ll = long long;

const int MAXN = 1005;
char s[MAXN];

vector<pair<int, int>> ord;
int n, m, lcp[MAXN][MAXN];
ll k, dp[MAXN][MAXN];

bool check(int x) {
  memset(dp, 0, sizeof(dp));
  vector<int> to(n + 1);
  for (int i = 0; i <= n; i++) to[i] = i + 1;
  for (int i = x; i < sz(ord); i++) {
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
}

void my_main() {
  cin >> n >> m >> k;
  cin >> (s + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      ord.push_back({i, j});
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = n; j >= 1; j--) {
      if (i == j) lcp[i][j] = n - i + 1;
      else {
        if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
        else lcp[i][j] = 0;
      }
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
  reverse(ord.begin(), ord.end());
  int l = 0, r = sz(ord) - 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  int ans_l, ans_r;
  if (check(r)) ans_l = ord[r].x, ans_r = ord[r].y;
  else ans_l = ord[l].x, ans_r = ord[l].y;
  for (int i = ans_l; i <= ans_r; i++) {
    cout << s[i];
  }
  cout << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);
  my_main();
  return 0;
}