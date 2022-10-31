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

int n, a[110];
vector<PII> ans;

int main() {
  cin >> n;
  REP(i, n) cin >> a[i];
  int sum = 0;
  int j = 0;
  REP(i, n) {
    if (sum && sum + a[i] == 0) {
      ans.EB(j, i - 1);
      j = i;
      sum = a[i];
    } else {
      sum += a[i];
    }
  }
  if (sum == 0) {
    puts("NO");
  } else {
    puts("YES");
    ans.EB(j, n - 1);
    cout << ans.size() << endl;
    for (auto x : ans)
      cout << x.F + 1 << ' ' << x.S + 1 << endl;
  }
  return 0;
}