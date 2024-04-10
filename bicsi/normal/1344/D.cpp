#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include <bits/stdc++.h>
#define int long long 
 
using namespace std;
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n; cin >> n;
  long long need; cin >> need;
  vector<int> a(n);
  long long sa = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sa += a[i];
  }
 
  const long long kInf = 4e18;
  auto chk = [&](long long m, vector<int>& b) {
    b.assign(n, 0);
    for (int i = 0; i < n; ++i) {
      if (m > a[i] - 1) continue;
      if (m == a[i] - 1) {
        b[i] = 1;
        continue;
      }
      
      long long bi = -1; int adv = 1;
      for (long long step = 1; step; adv ? step *= 2 : step /= 2) {
          bi += step;
          if (bi >= a[i] || -3 * bi * bi - 3 * bi + a[i] - 1 < m)
            bi -= step, adv = 0;
      }
      b[i] = bi + 1;
    }
    long long chk = 0;
    for (int i = 0; i < n; ++i)
      chk += b[i];
    return chk;
  };
  
  vector<int> sol;  
  long long b = -kInf, e = kInf;
  long long ans = kInf;
  while (b <= e) {
    long long m = (b + e) / 2;
    long long have = chk(m, sol);
    // cerr << m << ": " << have << endl;
    if (have >= need) {
      ans = m;
      b = m + 1;
    } else e = m - 1;
  }
  // cerr << "CBIN: " << ans << endl;
  
  assert(chk(ans, sol) >= need);
  vector<int> true_sol;
  long long have = chk(ans + 1, true_sol);
  assert(have < need);
  need -= have;
  // cerr << "need: " << need << endl;
  // for (int i = 0; i < n; ++i) cerr << sol[i] << " " << true_sol[i] << endl;
  for (int i = 0; i < n; ++i) {
    sol[i] -= true_sol[i];
    assert(sol[i] >= 0);
    int take = min((long long)sol[i], need);
    need -= take;
    true_sol[i] += take;
  }
  assert(need == 0);
 
  for (int i = 0; i < n; ++i)
    cout << true_sol[i] << " ";
  cout << endl;
 
  return 0;
}