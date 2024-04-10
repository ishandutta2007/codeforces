#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int mn = 0x7fffffff;
  for(int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    mn = min(t, mn);
  }
  if(mn == 1) cout << "-1\n";
  else cout << "1\n";
}