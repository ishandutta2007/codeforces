#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 223456
const int P = 998244353;

int n, k, l[maxN], r[maxN], alive[maxN], a[maxN], b[maxN];
void solve() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    l[i] = 0;
    r[i] = 0;
    alive[i] = 0;
  }
  for (int i = 1; i < n; i++) {
    l[a[i + 1]] = a[i];
    r[a[i]] = a[i + 1];
  }
  for (int i = 0; i < k; i++) {
    scanf("%d", &b[i]);
    alive[b[i]] = 1;
  }
  i64 answer = 1;
  for (int i = 0; i < k; i++) {
    int way = 0;
    if (l[b[i]] != 0 && alive[l[b[i]]] == 0)
      way += 1;
    if (r[b[i]] != 0 && alive[r[b[i]]] == 0)
      way += 1;
    answer = answer * way % P;
    alive[b[i]] = 2;
    r[l[b[i]]] = r[b[i]];
    l[r[b[i]]] = l[b[i]];
  }
  printf("%lld\n", answer);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    solve();
  }
}