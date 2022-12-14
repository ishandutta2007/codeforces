#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

vector<int> prefix_function (string s) {
  int n = (int) s.length();
  vector<int> pi (n);
  for (int i=1; i<n; ++i) {
    int j = pi[i-1];
    while (j > 0 && s[i] != s[j])
      j = pi[j-1];
      if (s[i] == s[j])  ++j;
      pi[i] = j;
    }
  return pi;
}

int n, m;
char p[1 << 20];
int y[1 << 20];

bool ok[1 << 20];

int main() {
  scanf("%d %d", &n, &m);
  scanf("%s", p);
  vector<int> pr = prefix_function(p);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &y[i]);
  }
  memset(ok, 0, sizeof(ok));
  int k = pr.back();
  while (k > 0) {
    ok[k] = 1;
    k = pr[k - 1];
  }

  int all;
  int lcov;
  if (m > 0) {
    all = y[0] - 1;
    lcov = y[0] + pr.size() - 1;
    bool f = true;
    for (int i = 0; i + 1 < m; ++i) {
      int cov = y[i] + pr.size() - 1 - y[i + 1] + 1;
      if (cov > 0) {
        if (!ok[cov]) {
          f = false;
        }
      }
      if (cov < 0) {
        all += y[i + 1] - 1 - lcov;
      }
      lcov = y[i + 1] + pr.size() - 1;
    }
    if (lcov < n) {
      all += n - lcov;
    }
    if (!f) {
      printf("0\n");
      return 0;
    }
  } else {
    all = n;
    lcov = -1;
  }

  long long mod = 1000000007;
  long long ans = 1;
  for (int i = 0; i < all; ++i) {
    ans = ans * 26;
    if (ans >= mod)
      ans %= mod;
  }
  printf("%lld\n", ans);
  return 0;
  
}