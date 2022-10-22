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

int acnt[5000][5000];
int dcnt[5000][5000];

void solve(){
  int n;
  cin >> n;
  vector<Int> p(n);
  for(auto &e:p)cin >> e;
  for(int c = 2;c < n-1;c++){
    int cnt = 0;
    for(int a = 0;a+1 < c;a++){
      if(p[a] < p[c])cnt++;
      acnt[a+1][c] = cnt;
    }
  }
  for(int b = n-3;b >= 1;b--){
    int cnt = 0;
    for(int d = n-1;d-1 > b;d--){
      if(p[d] < p[b])cnt++;
      dcnt[b][d-1] = cnt;
    }
  }
  Int ans = 0;
  for(int b = 1;b <= n-3;b++){
    for(int c = b+1;c <= n-2;c++){
      ans += Int(acnt[b][c]) * dcnt[b][c];
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