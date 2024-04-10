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
 
string a[3];
 
int main() {
  cin >> a[0] >> a[1] >> a[2]; 
  if (a[0] == a[1] && a[1] == a[2]) {
    puts("0"); return 0;
  }
  sort(a, a + 3);
  //cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
  
  int mn = 0;
  if (a[0][1] == a[1][1] && a[2][1] == a[1][1]) {
    if (a[0][0] + 1 == a[1][0] && a[1][0] + 1 == a[2][0]) {
      puts("0"); return 0;
    }
  }
  if (a[0][1] == a[1][1] && a[0][0] + 2 >= a[1][0]) mn = 1;
  else if (a[1][1] == a[2][1] && a[1][0] + 2 >= a[2][0]) mn = 1;
  else if (a[0][1] == a[2][1] && a[0][0] + 2 >= a[2][0]) mn = 1;
  else mn = 2;
  
  if (a[0] == a[1]) mn = 1;
  else if (a[0] == a[2]) mn = 1;
  else if (a[1] == a[2]) mn = 1;
  else mn = min(mn, 2);
  printf("%d\n", mn); return 0;
}
// fst