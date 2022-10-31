#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define RE register
#define rint RE int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define req(i, l, r) for (rint i = l; i >= r; i--)
#define Each(i) for (rint i = head[u]; i; i = edge[i].nxt)
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second

template <typename T>
void read(T &x) {
  x = 0; char op = getchar(); int F = 1;
  while (!isdigit(op)) {
    if (op == '-') F *= -1; op = getchar();
  }
  while (isdigit(op)) {
    x = (x << 1) + (x << 3) + op - '0'; op = getchar();
  }
  x *= F;
}

template <typename T, typename ...Args>
void read(T &x, Args &...args) {
  read(x); read(args...); 
}

const int N = 12, Mask = 5000;

int mx[Mask], ord[Mask];
int a[N][Mask], b[N][Mask], ctz[Mask];
int w[Mask], sum[Mask];
int f[Mask], g[Mask], n, m, all;

bool cmp(int i, int j) {
  return mx[i] > mx[j];
}

void work() {
  read(n, m); all = 1 << n;
  for (rint j = 1; j <= m; j++) {
    mx[j] = 0; ord[j] = j;
  }
  for (rint i = 1; i <= n; i++) {
    for (rint j = 1; j <= m; j++) {
      read(b[i][j]);
      mx[j] = max(mx[j], b[i][j]);
    }
  }
  sort(ord + 1, ord + m + 1, cmp);
  m = min(n, m);
  
  for (rint j = 1; j <= m; j++) {
    for (rint i = 1; i <= n; i++) {
      a[i][j] = b[i][ord[j]];
    }
  }
  for (rint i = 0; i < all; i++) {
    f[i] = 0; ctz[i] = __builtin_ctz(i);
  }
  
  for (rint j = 1; j <= m; j++) {
    for (rint i = 0; i < all; i++) {
      g[i] = f[i]; w[i] = 0;
    }
    for (rint k = 0; k < n; k++) {
      for (rint i = 1; i < all; i++) {
        #ifdef zz
        printf("def %d\n", i);
        #endif
        sum[i] = sum[i ^ (1 << ctz[i])] + a[(k + ctz[i]) % n + 1][j];
        w[i] = max(w[i], sum[i]);
      } 
    }
    
    for (rint i = 0; i < all; i++) {
      for (int s = i; s > 0; s = i & (s - 1)) {
        f[i] = max(f[i], g[i ^ s] + w[s]);
      }
    }
  }
  printf("%d\n", f[(1 << n) - 1]);
  return ;
}

/*

void work() {
  read(n, m);
  for (int i = 0; i < (1 << n); i++) {
    f[i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
    } 
  }
  
  for (rint j = 1; j <= m; j++) {
    for (rint i = 0; i < (1 << n); i++) {
      g[i] = f[i];
    }

    for (rint k = 0; k < n; k++) {
      for (rint i = 0; i < (1 << n); i++)
        tmp[i] = g[i];
      
      for (rint i = 0; i < (1 << n); i++) {
        for (rint l = 0; l < n; l++) {
          if (i & (1 << l))
            tmp[i] = max(tmp[i], tmp[i ^ (1 << l)] + a[(l + 1 + k) % n + 1][j]);
        }
      }
      
      for (rint i = 0; i < (1 << n); i++) {
        f[i] = max(f[i], tmp[i]);
      } 
    }
  }
  
  printf("%d\n", f[(1 << n) - 1]);
  return ;
}
*/

int main() {
  int T; read(T);
  while (T--) work();
  return 0;
}