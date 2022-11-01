#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, mod = 1e9 + 7;

bitset< N > bs;

long long powmod(long long b, long long p, long long m) {
  long long ret = 1;
  while(p > 0) {
    if(p & 1)
      ret = (ret * b) % m;
    b = (b*b) % m;
    p >>= 1;
  }
  return ret;
}

int n;
map< int , int > mp;

int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    int x;
    scanf("%d", &x);
    mp[x]++;
  }
  long long dv = 1, ans = 1;
  bool mid = false;
  for(auto it = mp.begin(); it != mp.end(); it++) {
    if((it->second & 1) && !mid) {
      dv = (dv*((it->second + 1)/2)) % (mod-1);
      mid = true;
    }
    else
      dv = (dv*(it->second + 1)) % (mod-1);
  }
  for(auto it = mp.begin(); it != mp.end(); it++) {
    if(mid)
      ans = (ans * powmod(it->first, it->second, mod)) % mod;
    else
      ans = (ans * powmod(it->first, it->second / 2, mod)) % mod;
  }
  ans = powmod(ans, dv, mod);
  cout << ans << endl;
  return 0;
}