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
  map<int, int> m;
  int sum = 0, t = 0;
  for (int i = 0; i < 5; ++i) {
    int x;
    cin >> x;
    m[x]++;
    sum += x;
    if (m[x] == 2) t = max(t, x * 2);
    if (m[x] == 3) t = max(t, x * 3);
  }
  cout << sum - t<< endl;

  return 0;
}