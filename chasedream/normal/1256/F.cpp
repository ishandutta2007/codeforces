#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define RE register
#define rint RE int
#define rll RE ll
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define req(i, l, r) for (rint i = l; i >= r; i--)
#define Each(i) for (rint i = head[u]; i != -1; i = edge[i].nxt)
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

template <typename T1, typename T2>
void ckmax(T1 &x, T2 y) {
  if (x < y) x = y;
}

template <typename T1, typename T2>
void ckmin(T1 &x, T2 y) {
  if (x > y) x = y;
}

const int N = 1000005;
char s1[N], s2[N];
char s[N];
int cnt1[26], cnt2[26], n;

long long ans1, ans2;

void merge1(int l, int r) {
  if (l == r) return ;
  int mid = l + r >> 1;
  merge1(l, mid); merge1(mid + 1, r);
  int x = l, y = mid + 1, z = l;
  while (x <= mid && y <= r) {
    if (s1[x] <= s1[y]) s[z++] = s1[x++];
    else ans1 += mid - x + 1, s[z++] = s1[y++];
  }
  while (x <= mid) s[z++] = s1[x++];
  while (y <= r) s[z++] = s1[y++];
  for (int i = l; i <= r; i++) s1[i] = s[i];
}

void merge2(int l, int r) {
  if (l == r) return ;
  int mid = l + r >> 1;
  merge2(l, mid); merge2(mid + 1, r);
  int x = l, y = mid + 1, z = l;
  while (x <= mid && y <= r) {
    if (s2[x] <= s2[y]) s[z++] = s2[x++];
    else ans2 += mid - x + 1, s[z++] = s2[y++];
  }
  while (x <= mid) s[z++] = s2[x++];
  while (y <= r) s[z++] = s2[y++];
  for (int i = l; i <= r; i++) s2[i] = s[i];
}

void work() {
  memset(cnt1, 0, sizeof(cnt1));
  memset(cnt2, 0, sizeof(cnt2));

  scanf("%d", &n);
  scanf("%s%s", s1 + 1, s2 + 1);
  for (int i = 1; i <= n; i++) cnt1[s1[i] - 'a']++;
  for (int i = 1; i <= n; i++) cnt2[s2[i] - 'a']++;
  for (int i = 0; i < 26; i++) {
    if (cnt1[i] != cnt2[i]) {
      puts("NO"); return ;
    }
  }
  
  for (int i = 0; i < 26; i++) {
    if (cnt1[i] >= 2) {
      puts("YES"); return ;
    }
  }
  ans1 = ans2 = 0LL;
  merge1(1, n); merge2(1, n);
  if ((ans1 - ans2) & 1) puts("NO"); else puts("YES");
}

int main() {
  int T; scanf("%d", &T);
  while (T--) work();
  return 0;
}