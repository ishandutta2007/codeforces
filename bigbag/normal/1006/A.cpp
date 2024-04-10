#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int n, x;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    while (n--) {
        cin >> x;
        if (x % 2 == 0) {
            --x;
        }
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}