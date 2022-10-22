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
  for(auto &e:a)cin >> e;
  if(*max_element(a.begin(), a.end()) == 0){
    cout << 0 << endl;
    return;
  }
  int l = 0, r = n-1;
  while(a[l] == 0)l++;
  while(a[r] == 0)r--;
  if(*min_element(a.begin() + l, a.begin() + r + 1) > 0){
    cout << 1 << endl;
  }
  else{
    cout << 2 << endl;
  }
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