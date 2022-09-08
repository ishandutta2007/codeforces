#include <bits/stdc++.h>

using namespace std;

long long w1, h1, w2, h2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> w1 >> h1 >> w2 >> h2;
    cout << w1 + w2 + 2 * (h1 + h2) + w1 - w2 + 4 << endl;
    return 0;
}