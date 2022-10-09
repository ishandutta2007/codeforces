#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

vector<int> getfactor(llong u) {
  vector<int> ans;
  llong t = u;
  for (llong i = 2; i * i <= u and i <= t; ++i) {
    if (t % i) continue;
    ans.push_back(i);
    while (t % i == 0) t/= i;
  }
  if (t > 1) ans.push_back(t);
  return ans;
}

#define maxn 150101
int n;
llong a[maxn], b[maxn];

bool ok(llong x) {
  rep(i, n) {
    if (a[i] % x and b[i] % x) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> n;
  rep(i, n) cin >> a[i] >> b[i];
  vector<int> fa = getfactor(a[0]);
  vector<int> fb = getfactor(b[0]);
  
  for (auto i: fa) if (ok(i)) {
    cout << i;
    return 0;
  }
  for (auto i: fb) if (ok(i)) {
    cout << i;
    return 0;
  }
  cout << -1;
  
  return 0;
}