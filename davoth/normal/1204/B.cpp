#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n,l,r;
    cin >> n >> l >> r;
    long long mx=pow(2,r)-1+(n-r)*pow(2,r-1),mn=pow(2,l)-1+(n-l);
    cout << mn << ' ' << mx;
    return 0;
}