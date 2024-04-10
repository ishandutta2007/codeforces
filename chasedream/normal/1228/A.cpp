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
#define pci pair <char, int>
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

int l, r;

bool check(int k) {
  int hsh[10] = {0};
  while (k > 0) {
    if (hsh[k % 10]) return 0;
    hsh[k % 10] = 1;
    k /= 10;
  } 
  return 1;
}

int main() {
  read(l, r);
  for (int i = l; i <= r; i++) {
    if (check(i)) {
      printf("%d\n", i);
      exit(0);
    }
  }
  puts("-1");
  return 0;
}