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

const int N = 200005;
const int p = 1000000007;

struct node {
  int l, r, id, z;
  ll ans = 0;
  void init() {
    ans = 0;
  }
} ques[N << 1]; 

ll w[N], ans[N], fac[N], inv[N], k;
int n, sz;

bool cmp(node a, node b) {
  return a.l / sz == b.l / sz ? a.r < b.r : a.l < b.l; 
}

ll qpow(ll u, ll v) {
  ll ans = 1;
  while (v > 0) {
    if (v & 1) ans = ans * u % p;
    u = u * u % p; v >>= 1;
  }
  return ans;
}

ll getans(int a, int b) {
  if (a < b) return 0;
  return fac[a] * inv[b] % p * inv[a - b] % p;
}

void pre() {
  fac[0] = inv[0] =1;
  for (int i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i % p;
    inv[i] = qpow(fac[i], p - 2);
  } 
}

int op = 0;
void modui() {
  sz = sqrt(200000);
  sort(ques + 1, ques + op + 1, cmp);
  ll sum = 1;
  for (int i = 1, L = 1, R = 0 ; i <= op ; i++) {
    while(L < ques[i].l) sum = (2 * sum - getans(L++, R) + p) % p;
    while(L > ques[i].l) sum = ((sum + getans(--L, R)) * inv[2]) % p;
    while(R < ques[i].r) sum = (sum + getans(L, ++R)) % p;
    while(R > ques[i].r) sum = (sum - getans(L, R--) + p) % p;
    ques[i].ans = sum;
  }
  sum = 0;
  ans[n + 1] = qpow(2, n);
  for(int i=1;i<=op;i++)
    ans[ques[i].id] = (qpow(2,ques[i].id) -ques[i].ans+p)*qpow(2,n-ques[i].id)%p;
	for(int i=1;i<=n+1;i++)
    sum=(sum+(ans[i]-ans[i-1])*(i-1))%p;

	cout<<(sum+p)*qpow(qpow(2,n),p-2)%p;
}

int main() {
  scanf("%d%lld", &n, &k);
  pre();
  for (int i = 1; i <= n; i++) {
    scanf("%d", &w[i]);
    w[i] += w[i - 1]; // calc sum
  }
  
  for (int i = 1; i <= n; i++) {
    ll c = k - w[i];
    //printf("%lld\n", c);
    if (c < 0) ans[i] = qpow(2, n);
    else if (c > i) ans[i] = 0;
    else ques[++op].id = i, ques[op].l = i, ques[op].r = c; 
  }
  
  modui();
  return 0;
}