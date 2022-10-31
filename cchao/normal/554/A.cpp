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
  set<string> f;
  int n = s.size();
  for (int i = 0; i <= n; ++i) {
    string a = s.substr(0, i);
    string b = s.substr(i);
    for (char c = 'a'; c <= 'z'; ++c) {
      f.insert(a + c + b);
    }
  }
  cout << f.size() << endl;
  return 0;
}