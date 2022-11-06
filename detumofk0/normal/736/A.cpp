#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen("inp", "r")) freopen("inp", "r", stdin);

    long long n; cin >> n;
    long long f[90];
    f[0] = 1;
    f[1] = 2;
    for(int i = 0; i < 90; ++i) {
        if(i >= 2) f[i] = f[i - 1] + f[i - 2];
        if(f[i] > n) {
            cout << i - 1 << endl;
            return 0;
        }
    }

    return 0;
}