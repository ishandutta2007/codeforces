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

void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  int ans = n;
  for(auto &e:a)cin >> e;
  if(n == 1){
    cout << 0 << endl;
    return;
  }
  for(int l = 0;l < n;l++){
    for(int r = l+1;r < n;r++){
      int tmp = 0;
      for(int i = 0;i < n;i++){
	tmp += (a[i] - a[l]) * (r-l) != (a[r] - a[l]) * (i-l);
      }
      ans = min(ans, tmp);
    }
  }
  cout << ans << endl;
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