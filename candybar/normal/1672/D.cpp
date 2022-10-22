/*
start thinking:
BULB:
result of thinking:

ba.

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template <class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template <class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 200005
int n, a[maxn], b[maxn], cnt[maxn];

bool solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    cnt[i] = 0;
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i);
  for (int i = 1; i <= n; i++)
    scanf("%d", b + i);
  for (int i = n, j = n, k; i >= 1; i = k) {
    while (a[j] != b[i]) {
      if (!cnt[a[j]])
        return false;
      cnt[a[j]]--;
      j--;
    }
    for (k = i; b[k] == b[i]; k--)
      cnt[b[i]]++;
    cnt[b[i]]--;
    j--;
  }
  return true;
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  int t;
  scanf("%d", &t);
  while (t--)
    puts(solve() ? "Yes" : "No");
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}
/*
1
5
3 1 3 2 3
1 3 2 3 3
*/