%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 5000;
const int M = 10001;


int n, cnt1, cnt2;
long long ans;

// (x1, y1) 
// (x2, y2)  
struct ele {
  int x1, y1, x2, y2;
  
  bool operator < (const ele& b) const {
    return y2 < b.y2;
  }
} row[N + 3], col[N + 3];

struct Bit_tree {
  int c[M + 3];
  
  void clear() {
    memset(c, 0, sizeof(c));
  }
  int lowbit(int x) {
    return x & -x;
  }
  void add(int x, int val) {
    while (x <= M) {
      c[x] += val; x += lowbit(x);
    }
  }
  
  int query(int x) {
    int res = 0;
    while (x > 0) {
      res += c[x]; x -= lowbit(x);
    }
    return res;
  } 
  int query(int l, int r) {
    return query(r) - query(l - 1);
  }
} bit;

int q[N + 3];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    x1 += N + 1, x2 += N + 1, y1 += N + 1, y2 += N + 1;
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    if (y1 == y2) {
      row[++cnt1] = (ele){x1, y1, x2, y2};
    } else {
      col[++cnt2] = (ele){x1, y1, x2, y2};
    }
  }
  sort(row + 1, row + cnt1 + 1);
  sort(col + 1, col + cnt2 + 1);
  
  //  
  for (int i = 1; i <= cnt1; i++) {
    bit.clear();
    int tail = 0, k = 1;
    
    for (int j = 1; j <= cnt2; j++) {
      //  
      if (row[i].x1 <= col[j].x1 && row[i].x2 >= col[j].x2 && 
          col[j].y1 <= row[i].y1 && col[j].y2 >= row[i].y1) {
        bit.add(col[j].x1, 1);
        q[++tail] = j;      
      }
    }
    
    //  
    for (int j = i + 1; j <= cnt1; j++) {
      //  
      for (; col[q[k]].y2 < row[j].y1 && k <= tail; k++) {
        bit.add(col[q[k]].x1, -1);
      }
      
      int l = max(row[i].x1, row[j].x1);
      int r = min(row[i].x2, row[j].x2);
      if (l < r) {
        long long res = bit.query(l, r);
        ans += (ll)res * (res - 1) / 2;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}

// wlzhouzhuan, 233