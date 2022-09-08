#include <bits/stdc++.h>

using namespace std;

int h, l;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> h >> l;
    cout << fixed << setprecision(10) << 0.5l * (1LL * l * l - 1LL * h * h) / h << endl;
    return 0;
}