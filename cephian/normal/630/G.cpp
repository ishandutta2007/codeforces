#include <iostream>
#include <iomanip>

using namespace std;
typedef unsigned long long ll;

ll choose(ll a, ll b) {
  if(b > a) return 0;
  if(b == 0) return 1;
  ll k = choose(a,b-1);
  k *= (a-b+1);
  k /= b;
  return k;
}

int main() {
  ll k;
  cin >> k;
  cout << choose(5+k-1,5)*choose(3+k-1,3) << "\n";
}