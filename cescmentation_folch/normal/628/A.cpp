#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, b,p;
  cin >> n >> b >> p;
  int t = n*p;
  int w = 0;
  
  while (n > 1) {
    int k = 2;
    while (2*k <= n) k *= 2;
    w += b*k + k/2;
    n -= k/2;
  }
  
  cout << w << ' '  << t << endl;
}