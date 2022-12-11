#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ll n;
  cin >> n;
  
  ll a = 0;
  ll b = 1e8;
  
  while (a + 1 < b) {
    ll c = (a + b)/2;
    if (c*(c + 1)/2 < n) a = c;
    else b = c;
  }
  
  n -= a*(a + 1)/2;
  
  cout << n << endl;
}