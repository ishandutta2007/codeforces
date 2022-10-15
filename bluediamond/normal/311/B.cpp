#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = (int) 1e5 + 7;
const int INF = (int) 1e18;
int n;
int m;
int p;
int d[N];
int a[N];
int s[N];
int dp[N];
int dp2[N];

struct Line {
  int a;
  int b;
  int eval(int t) {
    return a * t + b;
  }
};

int orientation(Line f, Line s) {
  return (f.a - s.a) * (f.b + s.b);
}

bool better(Line p1, Line p2, Line p3) {
  return orientation(p1, p2) + orientation(p2, p3) + orientation(p3, p1) > 0;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> p;
  for (int i = 2; i <= n; i++) {
    cin >> d[i];
    d[i] += d[i - 1];
  }
  n = m;
  for (int i = 1; i <= n; i++) {
    int h, tm;
    cin >> h >> tm;
    a[i] = tm - d[h];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
  }
  for (int i = 0; i < N; i++) {
    dp[i] = dp2[i] = INF;
  }
  dp[0] = 0;
  for (int step = 1; step <= p; step++) {
    for (int j = 1; j <= n; j++) {
      if (dp[j] != INF) {
        dp[j] += s[j];
      }
    }
    vector<Line> stk;
    int pos = 0;
    for (int i = 1; i <= n; i++) {
      if (dp[i - 1] != INF) {
        int j = i - 1;
        Line l = {-j, dp[j]};
        while ((int) stk.size() >= 2 && better(stk[(int) stk.size() - 2], stk[(int) stk.size() - 1], l)) {
          stk.pop_back();
        }
        stk.push_back(l);
      }
      while (pos + 1 < (int) stk.size() && stk[pos + 1].eval(a[i]) < stk[pos].eval(a[i])) {
        pos++;
      }
      if (pos < (int) stk.size()) {
        dp2[i] = stk[pos].eval(a[i]);
      }
      if (dp2[i] != INF) {
        dp2[i] -= s[i];
        dp2[i] += a[i] * i;
      }
    }
    for (int i = 1; i <= n; i++) {
      dp2[i] = min(dp2[i], dp2[i - 1]);
      dp[i] = dp2[i];
      dp2[i] = INF;
    }
  }
  cout << dp[n] << "\n";
}