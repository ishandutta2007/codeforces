#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
using namespace std;
typedef long long Int;
typedef pair<Int, Int> P;

bool ok(Int a, Int n, Int x, Int y, Int p, Int q){
  Int b = ((x + a) / p + n) * q;
  if(b - y <= a + n * p && b >= y)return true;
  else return false;
}

void solve(){
  Int x, y, p, q;
  cin >> y >> x >> q >> p;
  if(p == 1 && q == 1){
    if(x != y)cout << -1 << endl;
    else cout << 0 << endl;
    return;
  }
  if(q == 0){
    if(y != 0)cout << -1 << endl;
    else cout << 0 << endl;
    return;
  }
  Int a = p - x % p;a %= p;if(a < 0)a +=p;
  Int bottom = 0, top = (1LL << 61) / max(q, p);
  while(top - bottom > 1){
    Int mid = (top + bottom) / 2;
    if(ok(a, mid-1, x, y, p, q))top = mid;
    else bottom = mid;
  }
  cout << a + p * (top - 1) << endl;
  return;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}