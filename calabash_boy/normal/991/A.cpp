#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c ,n;
    while (cin >> a >> b >> c >> n) {
        if (c > a || c > b) {
            puts("-1");
        }
        else if (n - (a - c) - (b - c)-c > 0) {
            printf("%d\n", n - (a - c) - (b - c)-c);
        }
        else {
            puts("-1");
        }
    }
    return 0;
}