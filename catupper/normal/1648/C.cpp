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

const Int MOD = 998244353;
const Int LINF = (1LL << 60);
const int INF = (1000000007);
const Real EPS = 1e-10;
const long double PI = 3.141592653589793238462643383279502884L;

Int modpow(Int x, Int p){
  if(p == 0)return 1;
  if(p % 2 == 1)return x * modpow(x, p-1) % MOD;
  auto ans = modpow(x, p / 2);
  return ans * ans % MOD;
}

Int inv(Int x){
  return modpow(x, MOD-2);
}

Int bit[220000];
void add(int x, int val){
  x++;
  while(x < 220000){
    bit[x] += val;
    x += x & -x;
  }
}
Int get(int x){
  x++;
  Int ans = 0;
  while(x){
    ans += bit[x];
    x -= x & -x;
  }
  return ans;
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> s(n), t(m);
    for(auto &e:s)cin >> e;
    for(auto &e:t)cin >> e;

    vector<int> scnt(220000, 0);
    Int prod = 1;
    Int dorp = 1;
    int S = s.size();
    for(auto c:s)scnt[c]++;
    for(int i = 0;i < 220000;i++){
      if(scnt[i])add(i, scnt[i]);
      for(int j = 1;j <= scnt[i];j++)dorp = dorp * j % MOD;
    }
    for(int i = 1;i <= S;i++){
      prod = prod * i % MOD;      
    }

    prod = prod * inv(dorp) % MOD;
    Int ans = 0;
    for(auto c:t){
      ans += prod * get(c-1) % MOD * inv(S) % MOD;
      prod = prod * scnt[c] % MOD * inv(S) % MOD;     
      if(scnt[c] == 0)break;
      S--;
      scnt[c]--;
      add(c, -1);
    }
    if(S == 0 && n != m)ans++;
    ans %= MOD;
    cout << ans << endl;
    
    return 0;
}