#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
 
  
  int n; cin >> n;
  vector<bool> pattern(n, false);
  int best = 0, kc = 1;
 
  for (int k = 1; k <= n; ++k) {
    vector<bool> pat(n, false);
    int have = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (i % k != k - 1) {
        pat[i] = 1;
        have += 1;
      }
    }
    have -= k - 1;
    cerr << k << ": " << have << endl;
    if (best < have) {
      best = have;
      pattern = pat;
      kc = k;
    }
  }
 
  for (int i = 0; i < n; ++i) {
    cerr << pattern[i];
  }  
  cerr << endl;
 
  int k = kc;
  vector<bool> now(n, false);
  while (true) {
    int now_sz = 0;
    for (int i = 0; i < n; ++i)
      if (now[i]) now_sz += 1;
    if (now_sz >= best) {
      cout << 0 << endl;
      return 0;
    }
    vector<int> out;
    for (int i = 0; i < n; ++i) {
      if (!now[i] && pattern[i]) {
        out.push_back(i);
        now[i] = true;
        if (out.size() == k) break;
      }
    }
    assert(out.size() == k);
    cout << out.size() << ' ';
    for (auto x : out) 
      cout << x + 1 << " ";
    cout << endl;
 
    int ret; cin >> ret;
    assert(ret != -1);
    --ret;
    for (int i = ret; i < ret + k; ++i) 
      now[i % n] = false;
  }
  
  return 0;
}