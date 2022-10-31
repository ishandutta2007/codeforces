#include <iostream>

using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  if(n%2 == 1) {
    cout << "0";
    return 0;
  }
  int ways = n/4;
  if(n%4 == 0) --ways;
  cout << ways << "\n";
  return 0;
}