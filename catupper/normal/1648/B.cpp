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
  int n, c;
  cin >> n >> c;
  vector<int> cnt(c+1, 0);
  for(int i = 0;i < n;i++){
    int a;
    cin >> a;
    cnt[a] = true;
  }
  auto accum = cnt;
  for(int i = 1;i <= c;i++)accum[i] += accum[i-1];
  
  for(int i = 1;i <= c;i++){
    if(!cnt[i])continue;
    for(int j = 1;j*i <= c;j++){
      int l = i*j;
      int r = min(i*(j+1), c+1);
      bool exist = accum[r-1] != accum[l-1];
      if(exist && cnt[j] == 0){
	cout << "No" << endl;
	return;
      }
    }
  }
  cout << "Yes" << endl;
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