#include <iostream>

using namespace std;

int n,m;

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  if(m&1) {
    cout << m/2+1 << "\n";
  } else {
    cout << (n-m)/2+1 << "\n";
  }
  return 0;
}