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
 
const int N = 40;
int a[N];
vector <int> b, c;
int n, m, half, half2;

void pre() {
  for (int i = 0; i < (1 << half); i++) {
    int ret = 0;
    for (int j = 0; j < half; j++)
     if (i & (1 << j)) {
       ret = (ret + a[j + 1]) % m;
     }
    b.push_back(ret);
  }
  for (int i = 0; i < (1 << half2); i++) {
    int ret = 0;
    for (int j = 0; j < half2; j++)
      if (i & (1 << j)) {
        ret = (ret + a[half + j + 1]) % m;
      }
    c.push_back(ret);
  }
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
}

void print(vector <int>& b) {
  for (int i = 0; i < b.size(); i++)
    printf("%d ", b[i]);
  putchar('\n');
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  half = n / 2; half2 = n - half;
  pre();
  
  //print(b); print(c);
  
  int r = (int)c.size() - 1, ans = -1;
  for (int i = 0; i < (int)b.size(); i++) {
    while (r >= 0 && b[i] + c[r] >= m) r--;
    if (r >= 0 && b[i] + c[r] < m)
      ans = max(ans, b[i] + c[r]);
  }
  printf("%d\n", ans);
  return 0;
}