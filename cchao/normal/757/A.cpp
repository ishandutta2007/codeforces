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
  string s;
  cin >> s;
  string p = "Bulbasaur";
  map<char, int> a, b;
  for (char c : s)
    a[c]++;
  for (char c : p)
    b[c]++;
  int ans = INT_MAX;
  for (auto it : b) {
    ans = min(ans, a[it.F] / it.S);
  }
  printf("%d\n", ans);
  return 0;
}