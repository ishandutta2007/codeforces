%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
#define dd double
#define _i int
#define RE register
#define rep(i, l, r) for (RE int i = l; i <= r; i++)
#define req(i, l, r) for (RE int i = l; i >= r; i--)
#define range(i, l, r) rep(i, l, r - 1)
#define Be(s, t) memset(s, t, sizeof(s))
#define poly vector <int>
#define pii pair <int, int>
template <typename T> void read(T &x) { x = 0; int FF = 1; char op = getchar(); while (!isdigit(op)) { if (op == '-') FF = -1; op = getchar(); } while (isdigit(op)) { x = (x << 1) + (x << 3) + op - '0'; op = getchar(); } x *= FF; }
template <typename T> void print(T x) { if (x < 0) { putchar('-'); x = -x; } if (x < 1) return ; print(x / 10); putchar(x % 10 + '0'); }
template <typename T> void print(T x, char _tab) { print(x); putchar(_tab); }

int n, k;

void dodo(int n, int k) {
  if (k % 3 != 0) {
    int mod = (n % 3);
    if (!mod) puts("Bob");
    else puts("Alice");
  }
  else {
    int mod = (n % (k + 1));
    if (!mod) puts("Bob");
    else if (mod % 3 == 0 && mod != k)
      puts("Bob");
    else 
      puts("Alice");
  }
}

int main() {
  int T; scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &k);
    dodo(n, k);
  }
  return 0;
}