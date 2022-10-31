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

const int N = 300005;

string s;
int n;
int ans[N];
int lans, rans;

int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      if (lans < rans) ans[i] = 0, lans++;
      else ans[i] = 1, rans++;
    }
    else if (s[i] == ')') {
      if (lans > rans) ans[i] = 0, lans--;
      else ans[i] = 1, rans--;
    }
  }
  
  for (int i = 0; i < n; i++) {
    printf("%d", ans[i]);
  }
  putchar('\n');
  return 0;
}