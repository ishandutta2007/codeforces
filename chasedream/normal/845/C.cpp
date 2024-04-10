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

const int N = 200005;
struct ele {
  int x, y;
  bool operator < (const ele &b) const {
    if (x != b.x) return x < b.x;
    else return y < b.y;
  }
} s[N];

int t1 = -1, t2 = -1;
int n;

int main() {
  read(n);
  for (int i = 1; i <= n; i++) {
    read(s[i].x, s[i].y);
  }
  sort(s + 1, s + n + 1);
  
  for (int i = 1; i <= n; i++) {
    if (s[i].x > t1) {
      t1 = s[i].y;
    }
    else if (s[i].x > t2) {
      t2 = s[i].y;
    }
    else {
      puts("NO"); exit(0);
    }
  }
  puts("YES");
  return 0;
}