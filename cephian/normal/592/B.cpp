#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

ll get(ll n) {
    if(n == 3) return 1;
    return get(n-1) + 2*n-5;
}

int main() {
    ll n;
    cin >> n;
    cout << get(n) << "\n";

  return 0;
}