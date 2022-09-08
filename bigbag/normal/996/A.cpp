#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int n, ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int x : {100, 20, 10, 5, 1}) {
        ans += n / x;
        n %= x;
    }
    cout << ans << endl;
    return 0;
}