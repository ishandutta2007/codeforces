#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main(){
    int n;
    cin >> n;
    cout << 2 << '\n';
    for (int i = 2; i <= n; i++) {
         cout << (i * (i + 1) * (i + 1) - (i)) + 1 << '\n';
    }
}