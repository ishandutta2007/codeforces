#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < (n); )
#define rep1(i,n) for (int i = 0; i ++ < (n); )
#define len(x) ((int)x.size())
#define lamb(args, ret) [&]args {return ret;}

template<class x> ostream& operator<<(ostream& cout, const vector<x>& a) {
  cout << "[";
  if (len(a)) cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i];
  return cout << "]";
}

template<class u, class v> ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}

llong la, ra, ta, lb, rb, tb;

int main(void ){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> la >> ra >> ta >> lb >> rb >> tb;
  if (la < lb) {
    swap(la, lb);
    swap(ra, rb);
    swap(ta, tb);
  }

  llong pa = ra - la + 1, pb = rb - lb + 1;

  llong g = __gcd(ta, tb);
  llong deltal = (la - lb);

  clog << deltal << endl ;

  llong lo = - deltal % g;
  llong hi = lo + g;
  clog << pa << ' ' << pb << endl;
  clog << g << ' ' << lo << ' ' << hi << endl;

  llong ans = 0;
  ans = max(ans, min(lo + pb, pa));
  clog << ans << endl;
  ans = max(ans, min(pb - 1 + hi, pa - 1) - hi + 1);
  
  cout << ans;

  return 0;
}