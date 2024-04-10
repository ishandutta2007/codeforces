#include <iostream>

using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  cout << !(n&1)+1 << "\n";
  return 0;
}