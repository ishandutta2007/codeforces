#include <iostream>

using namespace std;

int a,b;

int main() {
  ios::sync_with_stdio(0);
  int k = 0;
  cin >> a >> b;
  while(a>0 && b>0 && (a!= 1 || b != 1)) {
    if(a > b) {
      ++b;
      a-=2;
    } else {
      ++a;
      b-=2;
    }
    ++k;
  }
  cout << k << "\n";
  return 0;
}