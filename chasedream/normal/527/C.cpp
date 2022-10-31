%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

#define int long long
const int N = 200005;
int op[N], x[N], y[N];
int x2[N], y2[N];
int ansx[N], ansy[N];
int l1[N], r1[N];
int l2[N], r2[N];
int f1[N], f2[N];
ll ans[N];
int n, m, h;
int qx, qy;
int xx, yy;

char read_char() {
  for (;;) {
    char op = getchar();
    if (op == 'H' || op == 'V') return op;
  }
}

void pre() {
  sort(x2 + 1, x2 + xx + 1);
  sort(y2 + 1, y2 + yy + 1);
  x[xx + 1] = n, y[yy + 1] = m;
  x2[xx + 1] = n, y2[yy + 1] = m;
  for (int i = 1; i <= yy + 1; i++) {
    int k = y2[i];
    ansy[k] = k - y2[i - 1];
  }
  for (int i = 1; i <= xx + 1; i++) {
    int k = x2[i];
    ansx[k] = k - x2[i - 1];
  }
  
  for (int i = 1; i <= n; i++)
    qx = max(qx, ansx[i]);
  for (int i = 1; i <= m; i++)
    qy = max(qy, ansy[i]);
  
  for (int i = 1; i <= yy; i++) {
    int p = lower_bound(y2 + 1, y2 + yy + 1, y[i]) - y2;
    //l1[i] = y2[p - 1];
    l1[i] = f1[y2[p - 1]];
    //if (y2[p - 1] == 0) l1[i] = 0;
    //else l1[i] = lower_bound(y + 1, y + yy + 1, y2[p - 1]) - y;
    p = upper_bound(y2 + 1, y2 + yy + 1, y[i]) - y2;
    //r1[i] = y2[p];
    r1[i] = f1[y2[p]];
    //if (y2[p] == m) r1[i] = yy + 1; 
    //else r1[i] = lower_bound(y + 1, y + yy + 1, y2[p]) - y;
  }
  for (int i = 1; i <= xx; i++) {
    int p = lower_bound(x2 + 1, x2 + xx + 1, x[i]) - x2;
    //l2[i] = x2[p - 1];
    l2[i] = f2[x2[p - 1]];
    //if (x2[p - 1] == 0) l2[i] = 0;
    //else l2[i] = lower_bound(x + 1, x + xx + 1, x2[p - 1]) - x;
    p = upper_bound(x2 + 1, x2 + xx + 1, x[i]) - x2;
    //r2[i] = x2[p];
    r2[i] = f2[x2[p]];
    //if (x2[p] == n) r2[i] = xx + 1; 
    //else r2[i] = lower_bound(x + 1, x + xx + 1, x2[p]) - x;
  }
}

void print() {
  printf("xx: %d yy: %d\n", xx, yy);
  for (int i = 1; i <= xx; i++) {
    printf("xx %d: l (%d) r(%d)\n", x[i], l2[i], r2[i]);
  }
  for (int i = 1; i <= yy; i++) {
    printf("yy %d: l (%d) r (%d)\n", y[i], l1[i], r1[i]);
  }
}

signed main() {
  scanf("%lld%lld%lld", &n, &m, &h);

  for (int i = 1; i <= h; i++) {
    char opt = read_char();
    int gg; scanf("%lld", &gg);
    if (opt == 'H') { // update y
      y[++yy] = gg, op[i] = 0;
      y2[yy] = gg;
      f1[gg] = yy;
    }
    else { // update x
      x[++xx] = gg, op[i] = 1;
      x2[xx] = gg;
      f2[gg] = xx;
    }
  }
  f1[m] = yy + 1, f2[n] = xx + 1;
  pre();
  
  /*
  for (int i = 1; i <= n; i++)
    printf("ansx[%d] = %d\n", i, ansx[i]);
  for (int i = 1; i <= m; i++)
    printf("ansy[%d] = %d\n", i, ansy[i]);
  */
  
  //print();
  
  for (int i = h; i >= 1; i--) {
    ans[i] = (long long)qx * qy;
    //printf("nowans %d %d\n", qx,  qy);
    if (op[i] == 0) { // update y
      int k = y[yy];
      ansy[ y[r1[yy]] ] += ansy[k];
      //printf("ansy[] = %d\n", ansy[ y[r1[yy]] ]);
      l1[r1[yy]] = l1[yy];
      r1[l1[yy]] = r1[yy]; 
      qy = max(qy, ansy[ y[r1[yy]] ]);
      yy--;
    }
    else { // update x
      int k = x[xx];
      ansx[ x[r2[xx]] ] += ansx[k];
      //printf("ansx[] = %d\n", ansx[ x[r2[xx]] ]);
      l2[r2[xx]] = l2[xx];
      r2[l2[xx]] = r2[xx];
      qx = max(qx, ansx[ x[r2[xx]] ]);
      xx--;
    }
    
    //printf("debug %d\n", i);
    //print();
  }
  
  for (int i = 1; i <= h; i++)
    printf("%lld\n", ans[i]);
  return 0;
}