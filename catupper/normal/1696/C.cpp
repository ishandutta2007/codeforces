#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using Int = long long;
using Real = long double;
using CP = complex<Real>;
using P = pair<Int, Int>;

const Int MOD = 1000000007;
const Int MOD2 = 998244353;
const Int LINF = (1LL << 60);
const int INF = (1000000007);
const Real EPS = 1e-10;
const long double PI = 3.141592653589793238462643383279502884L;

vector<P> go(vector<Int> v, Int m){
  vector<P> res;
  for(auto e:v){
    Int cnt = 1;
    while(e % m == 0){
      cnt *= m;
      e /= m;
    }
    if(!res.empty() && res.back().first == e){
      res.back().second += cnt;
    }
    else{
      res.push_back({e, cnt});
    }
  }
  return res;
}

void solve(){
  Int n, m;
  cin >> n >> m;  
  vector<Int> a(n);
  for(auto &e:a)cin >> e;

  Int k;
  cin >> k;
  vector<Int> b(k);
  for(auto &e: b)cin >> e;

  if(go(a, m) == go(b, m))cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}