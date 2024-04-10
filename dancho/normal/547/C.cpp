#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int li[1 << 20];

int n, q;
int a[1 << 20];
vector<int> pf[1 << 20];

int isp[1 << 20];
vector<int> pr;

int c;
bool in[1 << 20];

int main() {
  memset(isp, 0, sizeof(isp));
  for (int i = 2; i < (1 << 20); ++i) {
    if (isp[i] == 0) {
      pr.push_back(i);
      for (int j = i + i; j < (1 << 20); j += i) {
        isp[j] = 1;
      }
    }
  }

  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    int x = a[i];
    for (int j = 0; j < (int) pr.size(); ++j) {
      if (pr[j] * pr[j] > x) {
        break;
      }
      if (x % pr[j] == 0) {
        pf[i].push_back(pr[j]);
        while (x % pr[j] == 0) {
          x /= pr[j];
        }
      }
    }
    if (x > 1) {
      pf[i].push_back(x);
    }
    sort(pf[i].begin(), pf[i].end());
  }

  long long ans = 0;
  memset(in, 0, sizeof(in));
  memset(li, 0, sizeof(li));
  c = 0;
  for (int i = 0; i < q; ++i) {
    int x;
    scanf("%d", &x);

    // printf("OP %d %d %d\n", x, in[x], c);
    // for (int l = 0; l < (int) pf[x].size(); ++l) {
      // printf("_ %d ", pf[x][l]);
    // }
    // printf("\n");

    int a = c;
    for (int j = 1; j < (1 << pf[x].size()); ++j) {
      int mu = 1;
      int sign = 1;
      for (int k = 0; k < (int) pf[x].size(); ++k) {
        if (j & (1 << k)) {
          mu *= pf[x][k];
          sign = -sign;
        }
      }
      bool f = 0;
          if (in[x]) {
            --li[mu];
          }
          a += sign * li[mu];
          // printf("FOUND %d\n", it->second);
          if (!in[x]) {
            ++li[mu];
          }
    }
    if (in[x]) {
      in[x] = 0;
      --c;
      --a;
      ans -= a;
    } else {
      in[x] = 1;
      ++c;
      ans += a;
    }
    printf("%lld\n", ans);
  }
  return 0;
}