#include <iostream>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0);

  ll n,k;
  cin >> n >> k;
  cout << (n/k+1)*k << "\n";

  return 0;
}