#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int a,b;

int main() {
  cin >> a >> b;
  for(int x = 1; x < a; ++x) {
    int y = sqrt(a*a-x*x);
    if(y*y+x*x!=a*a) continue;
    for(int z = 1; z < b; ++z) {
      int w = sqrt(b*b-z*z);
      if(z*z+w*w!=b*b) continue;
      if(x*w != y*z) continue;
      if(-w == x || z == y) continue;
      cout << "YES\n0 0\n";
      cout << x << " " << y << "\n";
      cout << -w << " " << z << "\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}