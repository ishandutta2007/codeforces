#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 101010
int n;
llong k;
int a[maxn];

llong vistime(llong loop) {
  llong ans = 0;
  rep(i, n) ans += min((llong)a[i], loop);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  llong sum = 0;
  rep(i, n) cin >> a[i], sum += a[i];
  if (sum < k) {
    cout << -1;
    return 0;
  }
  llong l = 0, r = *max_element(a, a + n);
  while (l < r) {
    llong mid = l + (r - l + 1) / 2;
    if (vistime(mid) < k) l = mid;
    else r = mid - 1;
  }
  
  k -= vistime(l);
  queue<int> qu;
  rep(i, n) if (a[i] > l) qu.push(i), a[i] -= l;
  while (k--) {
    int u = qu.front();
    qu.pop();
    if (--a[u] != 0) qu.push(u);
  }
  for (; len(qu); qu.pop()) cout << qu.front() + 1 << ' ';
  
  return 0;
}