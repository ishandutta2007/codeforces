#include <bits/stdc++.h>

using namespace std;

long long a, b;
int lo[20], hi[20], n;
int cnt[10], ans = 0;

bool cek(int c, bool up, bool down) {
  if (up && down) return 1;
  if (c < 0) return 1;
  for (int k = 0; k < 10; k++) if (cnt[k]) {
    if (k < hi[c] && k > lo[c])
      return 1;
    if (k < hi[c] && down)
      return 1;
    if (k > lo[c] && up)
      return 1;
  }
  for (int k = 0; k < 10; k++) if (cnt[k]) {
    if (k < lo[c] && !down) continue;
    if (k > hi[c] && !up) continue;
    cnt[k]--;
    bool res = cek(c-1, up || (k < hi[c]), down || (k > lo[c])); 
    cnt[k]++;
    if (res) return true;
  }
  return false;
}


void dfs(int z, int d) {
  if (z == n) {
    ans += cek(n-1, 0, 0);
    return;
  }
  for (; d < 10; d++) {
    cnt[d]++;
    dfs(z+1, d);
    cnt[d]--;
  }
}

int main() {
  cin >> a >> b;
  int k = 0;
  while (a) {
    lo[k++] = a % 10;
    a /= 10;
  }
  k = 0;
  while (b) {
    hi[k++] = b % 10;
    b /= 10;
  }
  n = k; 
  ans = 0;
  dfs(0, 0);
  printf("%d\n", ans);
  return 0;
}