#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    long long white = 0, black = 0;
    for (int i = 0; i < n; ++i) {
        white += a[i] / 2;
        black += a[i] - a[i] / 2;
        swap(white, black);
    }
    cout << min(white, black) << endl;
    return 0;
}