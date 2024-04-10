#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    int sum = 0, t;
    while(n--) {
        cin >> t;
        sum += t;
    }
    cout << (abs(sum) + x - 1) / x << endl;
    return 0;
}