#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int x,y;

int main() {
  cin >> n >> m;
  x = 2*n;
  y = 3*m;
  for(int i = 6; i <= min(x,y); i += 6) {
    if(2+x < 3+y) x += 2;
    else y += 3;
  }
  cout << max(x,y) << "\n";
  return 0;
}