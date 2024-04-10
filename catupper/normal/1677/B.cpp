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
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<int> cnt(n*m);
  vector<int> ans(n*m);
  vector<int> ans2(n*m);
  vector<int> ok(m, 0);
  for(int i = 0;i < n * m;i++){
    cnt[i] = s[i] - '0';
    if(cnt[i] == 1 && ok[i % m] == 0){
      ok[i % m] = 1;
      ans[i]++;
    }
    if(i)cnt[i] += cnt[i-1];
  }
  for(int i = 1;i < n*m;i++){
    ans[i] += ans[i-1];
  }
  for(int i = 0;i < n*m;i++){
    int to = i;
    int from = max(0, to - m + 1);
    int c = cnt[to] - (from > 0 ? cnt[from-1]: 0);
    if(c>0)
      ans2[i]++;
  }
  for(int i = m;i < n*m;i++){
    ans2[i] += ans2[i - m];
  }

  for(int i = 0;i < n*m;i++)cout << ans[i] + ans2[i] << " ";cout << endl;
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