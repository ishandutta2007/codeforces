#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll fac(int n) {
    if (n < 3) {
        return n;
    }
    return fac (n - 1) * n;
}
int main(){
    ll a, b;
    cin >> a >> b;
    cout << fac (min (a, b));
}