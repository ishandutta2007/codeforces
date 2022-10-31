%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 100005;
struct ele {
  ll sum, cost;
  int id;
  bool operator < (const ele& b) const {
    if (cost != b.cost) return cost < b.cost;
    else id < b.id;
  }
} q[N];

long long ans = 0LL;
int t[N], n, m;
int st = 1;
bool over;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    q[i].id = i;
    scanf("%lld", &q[i].sum);
  }
  for (int i = 1; i <= n; i++)
    scanf("%lld", &q[i].cost);
  
  sort(q + 1, q + n + 1);
  for (int i = 1; i <= n; i++)
    t[q[i].id] = i;
  
  for (int i = 1; i <= m; i++) {
    ans = 0;
    int x; ll y;
    scanf("%d%lld", &x, &y);
    int &id = t[x];
    if (over) {
      puts("0"); continue;
    }
    if (y <= q[id].sum) {
      q[id].sum -= y;
      ans += q[id].cost * y;
      while (q[st].sum == 0) st++;
    } 
    else {
      y -= q[id].sum;
      ans += q[id].cost * q[id].sum;
      q[id].sum = 0;
      while (y) {
        ll tmp2 = min(y, q[st].sum);
        ans += q[st].cost * tmp2;
        y -= tmp2;
        q[st].sum -= tmp2;
        while (q[st].sum == 0) {
          st++;
          if (st > n) {
            over = 1;
            if (y) puts("0");
            else printf("%lld\n", ans);
            break;
          }
        }
        if (over) break;
      }
    }
    if (!over) printf("%lld\n", ans);
  }
  return 0;
}