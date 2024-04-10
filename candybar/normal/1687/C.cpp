/*
start thinking:
BULB:
result of thinking:

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
template<class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template<class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 200005
int n, m, a[maxn], b[maxn];
ll sum[maxn];
vector<int> adj[maxn];

void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    adj[i].clear();
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i);
  for (int i = 1; i <= n; i++) {
    scanf("%d", b + i);
    sum[i] = sum[i - 1] + b[i] - a[i];
  }
  for (int i = 1; i <= m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    adj[l - 1].push_back(r);
    adj[r].push_back(l - 1);
  }
  if (sum[n]) {
    puts("NO");
    return;
  }
  set<int> not0;
  queue<P> que;
  for (int i = 0; i <= n; i++) {
    if (sum[i]) {
      not0.insert(i);
    } else {
      for (auto j : adj[i]) {
        if (!sum[j] && j < i)
          que.push({i, j});
      }
    }
  }
  while (!que.empty()) {
    int l = que.front().first, r = que.front().second;
    if (l > r)
      swap(l, r);
    que.pop();
    while (true) {
      auto it = not0.lower_bound(l);
      if (it == not0.end() || *it > r)
        break;
      sum[*it] = 0;
      for (auto j : adj[*it]) {
        if (!sum[j])
          que.push({*it, j});
      }
      not0.erase(it);
    }
  }
  puts(not0.empty() ? "YES" : "NO");
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}