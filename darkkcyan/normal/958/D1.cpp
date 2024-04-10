
#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

#define maxn 201010
ii cor[maxn];
map<ii, int> cnt;

int main() {
  int n;
  scanf("%d\n", &n);
  rep(i, n) {
    int a, b, c;
    scanf("(%d+%d)/%d\n", &a, &b, &c);
    //clog << a << ' ' << b << ' ' << c << endl;
    a += b;
    int g = __gcd(a, c);
    cor[i] = ii(a / g, c / g);
    cnt[cor[i]] ++;
  }
  rep(i, n) cout << cnt[cor[i]] << ' ';

  return 0;
}