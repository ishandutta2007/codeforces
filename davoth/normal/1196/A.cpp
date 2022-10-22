#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        long long a[3];
        cin >> a[0] >> a[1] >> a[2];
        cout << (a[0] + a[1] + a[2])/2 << '\n';
    }
    return 0;
}