#include<bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())
#define double long double

llong k, d, t;
llong p;

bool cancook(double x) {
  //clog << x << ' ';
  double a = 0;
  llong cnt = (llong)x / p;
  a += (double)cnt * k + (double)cnt * (p - k) / 2.0;
  x -= cnt * p;
  if (x <= k) a += x;
  else a += (double)k + (x - k) / 2.0;
  //clog << a << endl;
  return a >= t;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
  cin >> k >> d >> t;
  if (k % d == 0) {
    cout << t;
    return 0;
  }
  p = (k / d + 1) * d;
  //clog << p << endl;
  double l = 0, r = 1;
  while (!cancook(r)) r *= 2;
  rep(i, 1000000) {
    double mid = (l + r) / 2;
    //clog << l << ' ' << r << ' ' << mid << endl;
    if (cancook(mid)) r = mid;
    else l = mid;
  }
  cout << fixed << r;

  return 0;
}