#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  //freopen("2.in", "r", stdin);

  int n;
  cin >> n;
  int p = 0x7fffffff;
  int rn = 0;
  int mx = 1;
  for(int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if(a >= p) {
      ++rn;
      mx = max(rn, mx);
    }
    else
      rn = 1;
      p = a;
  }
  cout << mx << "\n";
  return 0;
}