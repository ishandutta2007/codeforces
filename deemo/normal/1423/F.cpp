#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    long long sm = 0;
    long long sm2= 0;
    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        sm += y;
        sm2 += 1ll * x * y;
    }
    if (sm > n)
        cout << "-1\n";
    else if (sm < n)
        cout << "1\n";
    else {
        long long tmp = 1ll*n*(n-1) / 2;
        
        if (tmp % n == sm2 % n)
            cout << "1\n";
        else
            cout << "-1\n";
    }
    return 0;
}