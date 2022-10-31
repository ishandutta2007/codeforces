#include <bits/stdc++.h>

using namespace std;

template <class T> void mini(T &l, T r) {l = min(l, r);}
template <class T> void maxi(T &l, T r) {l = max(l, r);}

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(bool a) {
  return a ? "T" : "F";
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
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
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using ll = long long;
using ld = long double;

const int N = 5010, M = 1 << 12;

string s;
int dp[N][M];

void run() {
  cin >> s;
  int n = s.length();
  int a = log2(n);
  debug(a);
  int H = (1 << a);
  string ans = "";
  int z = n - (H - 1);
  for (int i = 0; i <= z; ++i) fill_n(dp[i], M, 100);
  dp[0][0] = -1;
  for (int msk = 0; msk < H; ++msk) {
    for (int j = 0; j < a; ++j) {
      if (!(msk & (1 << j))) {
        mini(dp[0][msk | (1 << j)], dp[0][msk]);
      }
    }
  }
  debug(dp[0][7]);
  int old = -1;
  for (int i = 1; i <= z; ++i) {
    for (int msk = 0; msk < H; ++msk) if (dp[i - 1][msk] == old) {
      debug(i - 1, msk);
      dp[i][msk] = s[msk + i - 1] - 'a';
      debug(i, dp[i][msk]);
    }
    for (int msk = 0; msk < H; ++msk) {
      for (int j = 0; j < a; ++j) if (!(msk & (1 << j))) {
        mini(dp[i][msk | (1 << j)], dp[i][msk]);
      }
    }
    old = *min_element(dp[i], dp[i] + H);
    ans += char('a' + old);
  }
  cout << ans << endl;

}

int main() {
  run();
  return 0;
}