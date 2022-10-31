#include <iostream>

using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  ll k = (n*(n-1)*(n-2)*(n-3)*(n-4));
  cout << (k/120)*k << "\n";

  return 0;
}