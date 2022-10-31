#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k; cin >> n >> k;

    long long ne = n / 2, no = n - n / 2;
    if(k <= no) cout << 1LL + 2LL * (k - 1) << endl;
    else {
        k -= no;
        cout << 2LL + 2LL * (k - 1) << endl;
    }

    return 0;
}