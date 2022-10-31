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
const int mod = 998244353;

ll fac[N];

void pre(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i % mod;
  }
}

struct ele {
  int a, b;
  bool operator == (ele bb) {
    return a == bb.a && b == bb.b;
  }
} s[N];
int n;

bool cmp(ele a, ele b) {
  if (a.a != b.a) return a.a < b.a;
  else return a.b < b.b;
}

bool cmp1(ele a, ele b) {
  return a.a < b.a;
}

bool cmp2(ele a, ele b) {
  return a.b < b.b;  
}

ll calc1() {
  sort(s + 1, s + n + 1, cmp1);
  ll ans = 1LL;
  for (int i = 1, j = 1; i <= n; i = j + 1) {
    while (j < n && s[j + 1].a == s[i].a) j++;
    ans *= fac[j - i + 1]; ans %= mod;
  }
  return ans;
}

ll calc2() {
  sort(s + 1, s + n + 1, cmp2);
  ll ans = 1LL;
  for (int i = 1, j = 1; i <= n; i = j + 1) {
    while (j < n && s[j + 1].b == s[i].b) j++;
    ans *= fac[j - i + 1]; ans %= mod;
  }
  return ans;
}

ll calc() {
  sort(s + 1, s + n + 1, cmp);
  for (int i = 1; i < n; i++) {
    if (s[i].b > s[i + 1].b) {
      return 0LL;
    }
  }
  ll ans = 1LL;
  for (int i = 1, j = 1; i <= n; i = j + 1) {
    while (j < n && s[j + 1] == s[i]) j++;
    ans *= fac[j - i + 1]; ans %= mod;
  }
  return ans;
}

int main() {
  read(n); pre(n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &s[i].a, &s[i].b);
  }
  printf("%d\n", ((fac[n] - calc1() - calc2() + calc()) % mod + mod) % mod);
  return 0;
}