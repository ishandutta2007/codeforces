#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 223456

int n;
i64 x[maxN], y[maxN];
int p[maxN];
bool used[maxN];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld%lld", &x[i], &y[i]);
  }
  p[0] = 0;
  used[0] = true;
  for (int i = 1; i < n; i++) {
    i64 maxdis = -1;
    int id = -1;
    for (int j = 0; j < n; j++)
      if (!used[j]) {
        i64 dis = (x[j] - x[p[i - 1]]) * (x[j] - x[p[i - 1]]) +
                  (y[j] - y[p[i - 1]]) * (y[j] - y[p[i - 1]]);
        if (dis > maxdis) {
          maxdis = dis;
          id = j;
        }
      }
    p[i] = id;
    used[id] = true;
  }
  for (int i = 0; i < n; i++)
    printf("%d ", p[i] + 1);
  printf("\n");
}