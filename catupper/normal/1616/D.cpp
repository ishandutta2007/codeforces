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

struct min_bit{
  int n;
  vector<Int> bit;
  min_bit(int n):n(n),bit(n+1, INF){
  }
  void set(int pos, Int val){
    pos++;
    while(pos <= n){
      bit[pos] = min(bit[pos], val);
      pos += pos & -pos;
    }
  }
  Int get(int pos){
    pos++;
    Int res = LINF;
    while(pos){
      res = min(res, bit[pos]);
      pos -= pos & -pos;
    }
    return res;
  }  
};
  

void solve(){
  Int n, x;
  cin >> n;
  vector<Int> a(n+1);
  for(int i = 1;i <= n;i++)
    cin >> a[i];

  
  for(int i = 1;i <= n;i++)
    a[i] += a[i-1];
  cin >> x;
  for(Int i = 1;i <= n;i++)a[i] -= x*i;

  vector<Int> vals = a;
  vals.push_back(-LINF);
  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());
  for(auto &e:a)
    e = lower_bound(vals.begin(), vals.end(), e) - vals.begin();
  
  vector<int> ban(n);

  min_bit mb(vals.size());
  mb.set(0, n+1);
  for(int l = n-1;l >= 0;l--){
    ban[l] = mb.get(a[l]-1)-1;
    mb.set(a[l+1], l+1);
  }
  int ans = n;

  int l = 0;
  while(l < n){
    int r = l + 1;
    int banmin = ban[l];
    while(r < n && r < banmin){
      banmin = min(banmin, ban[r]);
      r++;
    }
    if(r != n)ans--;
    l = r + 1;
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