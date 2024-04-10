#pragma GCC optimize(2)
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

const int N = 505;
char s[N];
int n;

pii pre[N], suf[N];

int getans() {
  #ifdef debug
  for (int i = 1; i <= n; i++) {
    printf("%c", s[i]);
  }
  putchar('\n');
  #endif
  int cnt1 = 0, cnt2 = 0;
  stack <char> st;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '(') st.push('('), cnt1++;
    else {
      if (!st.empty() && st.top() == '(') st.pop(), cnt1--;
      else st.push(')'), cnt2++;
    }
    pre[i] = mp(cnt1, cnt2);
    //printf("pre[%d] = (%d, %d)\n", i, pre[i].fi, pre[i].se);
  }

  cnt1 = cnt2 = 0;
  while (!st.empty()) st.pop();
  for (int i = n; i >= 1; i--) {
    if (s[i] == ')') st.push(')'), cnt2++;
    else {
      if (!st.empty() && st.top() == ')') st.pop(), cnt2--;
      else st.push('('), cnt1++;
    }
    suf[i] = mp(cnt1, cnt2);
    //printf("suf[%d] = (%d, %d)\n", i, suf[i].fi, suf[i].se);
  }

  int tot = 0;
  for (int i = 0; i < n; i++) {
    if (pre[i].fi == 0 && suf[i + 1].se == 0 && pre[i].se == suf[i + 1].fi)
      tot++;
  }
  return tot;
}

int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  int ans = 0;
  pii id = mp(1, 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      swap(s[i], s[j]);
      int res = getans();
      swap(s[i], s[j]);
      if (res > ans)
        ans = res, id = mp(i, j);
    }
  }
  printf("%d\n", ans);
  printf("%d %d\n", id.first, id.second);
  return 0;
}