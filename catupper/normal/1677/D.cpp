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
const Int PRIM = 3;
const Int LINF = (1LL << 60);
const int INF = (1000000007);
const Real EPS = 1e-10;
const long double PI = 3.141592653589793238462643383279502884L;



void solve(){
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for(auto &e:A)cin >> e;
  for(int i = 0;i < k;i++){
    if(A[n-1-i] > 0){
      cout << 0 << endl;
      return;
    }
    A[n-1-i] = 0;    
  }
  Int ans = 1;
  for(int i = 1;i <= k;i++)ans = ans * i % MOD2;
  for(int i = 0;i < n-k;i++){
    if(A[i] > i){
      cout << 0 << endl;
      return;
    }
    if(A[i] == -1){
      ans *= k+1+i;ans %= MOD2;
    }
    if(A[i] == 0){
      ans *= k+1;ans %= MOD2;
    }
  }
  cout << ans << endl;
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    Int T;
    cin >> T;
    while(T--)solve();
    return 0;
}