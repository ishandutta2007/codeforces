#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int fpow(int x, int y) {
  int ret = 1;
  while(y) {
    if(y & 1) ret = (1LL * ret * x) % mod;
    x = (1LL * x * x) % mod;
    y >>= 1;
  }
  return ret;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  cout << fpow((fpow(2, m) - 1 + mod) % mod, n) << endl;

  return 0;
}