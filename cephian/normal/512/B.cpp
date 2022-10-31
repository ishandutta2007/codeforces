#include <iostream>
#include <vector>

using namespace std;

int n;
const int INF = 1e9;
int l[305], c[305];
int mask[305];
int dp[305][1<<10];

int solve(int i, int m) {
  int &ans = dp[i][m];
  if(ans != -1) return ans;
  if(i == n) {
    if(m == 0) return 0;
    return INF;
  }
  ans = min(solve(i+1, m), solve(i+1, m & mask[i]) + c[i]);
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> l[i];
  }
  for(int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  int ans = INF;
  for(int i = 0; i < n; ++i) {
    vector<int> pf;
    int a = l[i];
    for(int p = 2; p*p <= a && a != 1; ++p) {
      if(a%p == 0) {
        while(a%p == 0)
          a /= p;
        pf.push_back(p);
      }
    }
    if(a != 1)
      pf.push_back(a);
    for(int j = 0; j < n; ++j) {
      mask[j] = 0;
      for(int k = 0; k < pf.size(); ++k) {
        if(l[j]%pf[k] == 0)
          mask[j] |= (1<<k);
      }
    }
    for(int j = 0; j <= n; ++j)
      for(int k = (1<<pf.size())-1; k>=0; --k)
        dp[j][k] = -1;
    ans = min(ans, solve(0, (1<<pf.size())-1) + c[i]);
  }
  if(ans == INF) cout << "-1\n";
  else cout << ans << "\n";
  return 0;
}