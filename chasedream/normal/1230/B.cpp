#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define RE register
#define rint RE int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define req(i, l, r) for (rint i = l; i >= r; i--)
#define Each(i) for (rint i = head[u]; i > 0; i = edge[i].nxt)
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

int n, k;
string s;

int main() {
  cin >> n >> k >> s;
  if (k == 0) {
    cout << s << '\n';
    exit(0);
  }
  if (n == 1) {
    cout << "0" << '\n';
    exit(0);
  }
  for (int i = 0; i < n; i++) {
    if (i == 0 && s[i] > '1') {
      s[i] = '1'; k--;
    }
    if (i > 0 && s[i] > '0') {
      s[i] = '0'; k--;
    }
    if (k == 0) break;
  }
  cout << s << '\n';
  return 0;
}