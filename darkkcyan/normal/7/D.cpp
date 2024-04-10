#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define ii pair<int, int>
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

#define maxn 5010101

int n;

int ans[maxn];
string s;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> s;
  ans[0] = 1;
  llong u = s[0] - 'a' - 1, v = s[0] - 'a' - 1;
  llong sum = 1;
  const int base = 29;
  const llong rem = 1e9 + 8181;
  llong t = base;
  rep1(i, len(s) - 1) {
    u = (u * base + s[i] - 'a' - 1 + rem) % rem;
    (v += t * (s[i] - 'a' - 1 + rem)) %= rem;
    (t *= base) %= rem;
    //clog << u << ' ' << v << endl;
    if (u == v) ans[i] = ans[(i - 1) / 2] + 1;
    else ans[i] = 0;
    sum += ans[i];
  }

  cout << sum;

  return 0;
}