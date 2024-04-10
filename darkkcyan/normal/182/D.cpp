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

void genz(const string& s, int z[]) {
  z[0] = len(s);
  int l = 0, r = 0;
  rep1(i, len(s) - 1) {
    for (z[i] = i <= r ? min(z[i - l], r - i + 1) : 0; i + z[i] <= len(s) and s[z[i]] == s[i + z[i]]; ++z[i]);
    if (i + z[i] - 1 >= r) l = i, r = z[i] + i - 1;
  }
}

string a, b;
int za[maxn], zb[maxn];

bool isdivisor(int num, int len, int z[]) {
  if (len % num) return false;
  for (int i = 0; i < len; i += num) 
    if (z[i] < num) return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> a >> b;
  genz(a, za);
  genz(b, zb);
  
  int ans = 0;
  rep1(i, min(len(a), len(b))) {
    if (a[i - 1] != b[i - 1]) break;
    ans += isdivisor(i, len(a), za) and isdivisor(i, len(b), zb);
  }
  cout << ans;
  
  return 0;
}