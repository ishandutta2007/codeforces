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
  string str;
  cin >> n;
  cin >> str;
  string ans1(2, str[0]);
  string ans2;
  for(auto c:str){
    if(!ans2.empty() && ans2.back() < c)break;
    ans2.push_back(c);
  }
  for(int i = ans2.size() - 1;i >= 0;i--)
    ans2 += ans2[i];
  cout <<  min(ans1, ans2) << endl;
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