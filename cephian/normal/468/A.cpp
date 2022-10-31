#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  if(n < 4) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  if(n&1) {
    cout << "5 - 3 = 2\n";
    cout << "2 + 1 = 3\n";
    cout << "2 * 3 = 6\n";
    cout << "6 * 4 = 24\n";
  } else {
    cout << "1 * 2 = 2\n";
    cout << "2 * 3 = 6\n";
    cout << "6 * 4 = 24\n";
  }
  for(int i = n-1; i > 4 + (n&1); i-=2) {
    cout << i+1 << " - " << i << " = 1\n";
    cout << "24 * 1 = 24\n";
  }
  return 0;
}