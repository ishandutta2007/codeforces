#include <bits/stdc++.h>

using namespace std;

long long n, m, a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> a >> b;
    long long x = n % m, y = (m - n % m) % m;
    cout << min(x * b, y * a) << endl;
    return 0;
}