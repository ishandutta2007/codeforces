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

class UnionFind{
public:
  int n;
  vector<int> u;
  UnionFind(int _n = 0){
    n = _n;
    u = vector<int>(n, -1);
  }
  int r(int x){
    if(u[x] < 0)return x;
    return u[x] = r(u[x]);
  }
  void unite(int x, int y){
    x = r(x);
    y = r(y);
    if(x == y)return;
    if(-u[x] < -u[y])swap(x,y);
    u[x] += u[y];
    u[y] = x;
  }
  int size(int x){
    return -u[r(x)];
  }
};


void solve(){
  int n;
  cin >> n;
  UnionFind uf(n+1);
  vector<int> ca(n), cb(n);
  for(auto &e:ca)cin >> e;
  for(auto &e:cb)cin >> e;
  for(int i = 0;i < n;i++){
    uf.unite(ca[i], cb[i]);
  }
  Int up = n, low =1;
  Int ans = 0;
  for(int i = 1;i <= n;i++){
    if(uf.r(i) != i)continue;
    int s = uf.size(i);
    for(int i = 0;i < s/2;i++){
      ans += up * 2;up--;
      ans -= low * 2;low++;
    }
  }
  cout << ans << endl;
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)solve();
    return 0;
}