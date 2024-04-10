#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a == c && b != d) {
        int t = b - d;
        printf("%d %d %d %d\n", a + t, b, c + t, d);
    }
    else if(b == d && a != c) {
        int t = a - c;
        printf("%d %d %d %d\n", a, b + t, c, d + t);
    }
    else if(abs(a - c) == abs(b - d)) {
        printf("%d %d %d %d\n", a, d, c, b);
    }
    else puts("-1");
    return 0;
}