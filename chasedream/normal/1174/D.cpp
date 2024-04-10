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

vector <int> ans;
int vis[5000005], n, x;

int main() {
  scanf("%d%d", &n, &x);
  ans.push_back(0);
  vis[x] = 1, vis[0] = 1;
  for (int i = 1; i < (1 << n); i++) {
    if (!vis[i]) {
      vis[i ^ x] = 1;
      ans.push_back(i);
    }
  }
  printf("%d\n", ans.size() - 1);
  for (int i = 1; i < ans.size(); i++) {
    printf("%d ", ans[i - 1] ^ ans[i]);
  }
  putchar('\n');
  return 0;
}