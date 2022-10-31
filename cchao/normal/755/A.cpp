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

const int maxn = 1e6 + 10;
bool v[maxn];
int main() {
  v[0] = v[1] = true;
  for (int i = 2; i < maxn; ++i) if (!v[i]) {
    for (int j = i + i; j < maxn; j += i)
      v[j] = true;
  }
  int n;
  cin >> n;
  REPE(i, 1, 1000) if (v[n * i + 1]) {
    cout << i << endl;
    return 0;
  }
  return 0;
}