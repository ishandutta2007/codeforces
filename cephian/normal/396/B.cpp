#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
  return (!b)?a:gcd(b,a%b);
}

bool is_prime(int a) {
  int q = sqrt(a);
  for(int i = 2; i <= q; ++i)
    if(a%i == 0)
      return 0;
  return 1;
}

int v(int a) {
  for(int i = a;;--i)
    if(is_prime(i))
      return i;
}

int u(int a) {
  for(int i = a+1;;++i)
    if(is_prime(i))
      return i;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    ll p = v(n+1);
    ll q = u(n+1);
    ll num = p*q-2*q+2*n-2*p+2;
    ll den = 2*p*q;
    ll g = gcd(num,den);
    cout << num/g << "/" << den/g << "\n";
  }
}