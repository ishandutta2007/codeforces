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
#include <unordered_map>
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



int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    unordered_map<int, vector<Int>> xs, ys;
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
      for(int j = 0;j < m;j++){
	int c;
	cin >> c;
	xs[c].push_back(i);
	ys[c].push_back(j);
      }
    }
    Int ans = 0;
    for(auto &[col, vec]: xs){
      sort(vec.begin(), vec.end());
      int n = vec.size();
      for(int i = 0;i < n;i++){
	ans += vec[i] * (i - (n-i-1));
      }
    }
    for(auto &[col, vec]: ys){
      sort(vec.begin(), vec.end());
      int n = vec.size();
      for(int i = 0;i < n;i++){
	ans += vec[i] * (i - (n-i-1));
      }
    }
    cout << ans << endl;
    return 0;
}