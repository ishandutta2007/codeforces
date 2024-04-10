#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
using LL = long long;
using PII = pair<int, int>;
#define F first
#define S second

int main() {
  int n, c;
  cin >> n >> c;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  int ans = 0;
  REP(i, n - 1) {
    ans = max(ans, a[i] - a[i+1] - c);
  }
  cout << ans << endl;
  return 0;
}