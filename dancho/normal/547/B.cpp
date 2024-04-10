#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
pair<int, int>  a[1 << 20];

bool us[1 << 20];
int par[1 << 20];
int sz[1 << 20];
int sl[1 << 20];

int ufind(int v) {
  if (par[v] == -1) {
    return v;
  }

  return (par[v] = ufind(par[v]));
}

void merge(int a, int b) {
  int pa = ufind(a);
  int pb = ufind(b);
  par[pa] = pb;
  sz[pb] += sz[pa];
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i].first);
    a[i].first = -a[i].first;
    a[i].second = i;
  }

  memset(par, -1, sizeof(par));
  memset(sz, 0, sizeof(sz));
  memset(us, 0, sizeof(us));
  sort(a, a + n);
  int lsl = 0;
  for (int i = 0; i < n; ++i) {
    int k = a[i].second;
    us[k] = 1;
    sz[k] = 1;
    if (k > 0 && us[k - 1]) {
      merge(k, k - 1);
    }
    if (k + 1 < n && us[k + 1]) {
      merge(k, k + 1);
    }
    int j = ufind(k);
    while (sz[j] > lsl) {
      ++lsl;
      sl[lsl] = -a[i].first;
    }
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d%c", sl[i], " \n"[i == n]);
  }
  return 0;
}