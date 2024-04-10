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
  map<int, int> vals;
  for(int i = 0;i < n;i++){
    int a;
    cin >> a;
    vals[a]++;
  }
  for(int i = 0;i < n-1;i++){
    map<int, int> diffs;
    for(auto it = vals.begin();it != vals.end();it++){
      if(it->second > 1){
	diffs[0] += it->second - 1;
      }
      if(next(it) != vals.end()){
	diffs[next(it)->first - it->first]++;
      }
    }
    vals = diffs;
  }
  cout << vals.begin()->first << endl;
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