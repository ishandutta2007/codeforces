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
  int n, a[3] = {};
  cin >> n;
  REP(i, n) {
    int x;
    cin >> x;
    a[i % 3] += x;
  }
  string ans[] = {"chest", "biceps", "back"};
  cout << ans[max_element(a, a + 3) - a] << endl;
  return 0;
}