#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;
typedef long long LL;

int n, a[110];
bool v[110];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  long long ans = 1;
  for (int i = 0; i < n; ++i) if (!v[i]) {
    vector<int> b;
    for (int j = i; !v[j]; j = a[j]) {
      b.push_back(j);
      v[j] = true;
    }
    if (a[b.back()] != b.front()) {
      puts("-1");
      exit(0);
    }
    LL sz = b.size();
    LL t = sz % 2 == 0 ? sz / 2 : sz;
    ans = ans / __gcd(ans, t) * t;
  }
  cout << ans << endl;
  return 0;
}