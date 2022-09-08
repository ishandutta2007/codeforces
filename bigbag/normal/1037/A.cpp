#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

long long n, ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    long long st = 0;
    while (n > 0) {
        ++ans;
        long long x = st + 1;
        n -= x;
        st += x;
    }
    cout << ans << endl;
    return 0;
}