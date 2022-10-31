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


const int maxn = 1e5 + 10;
int p[maxn];
int f(int x) { return x == p[x] ? x : p[x] = f(p[x]); }

int main() {
  int n;
  scanf("%d", &n);
  REPE(i, 1, n) p[i] = i;
  REPE(i, 1, n) {
    int x;
    scanf("%d", &x);
    p[f(x)] = f(i);
  }
  set<int> s;
  REPE(i, 1, n) s.insert(f(i));
  cout << s.size() << endl;
  return 0;
}