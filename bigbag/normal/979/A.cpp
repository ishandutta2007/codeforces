#include <bits/stdc++.h>

using namespace std;

long long n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    ++n;
    if (n % 2 == 0) {
        n /= 2;
    }
    cout << n << endl;
    return 0;
}