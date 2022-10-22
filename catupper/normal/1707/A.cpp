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
  Int n, q;
  cin >> n >> q;
  vector<int> a(n);
  vector<int> s(n,0);
  for(auto &e:a)cin >> e;
  int iq = 0;
  for(int i = n-1;i >= 0;i--){
    if(a[i] <= iq){
      s[i] = 1;
    }else if(iq < q){
      iq++;
      s[i] = 1;
    }
  }
  for(int i = 0;i < n;i++)cout << s[i];cout << endl;
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