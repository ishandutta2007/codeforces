#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int x = 4;
    if (n % 2) {
        x = 9;
    }
    cout << x + n << " " << x << "\n";
    return 0;
}