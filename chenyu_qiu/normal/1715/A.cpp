#include<bits/stdc++.h>

using namespace std;

int T, n, m;
int main() {
    for (cin >> T; T--;) {
        cin >> n >> m;
        if(n == m&&m == 1) {
            puts("0");
            continue;
        }
        if(n == 1) {
            printf("%d\n", m);
            continue;
        }
        if(m == 0) {
            printf("%d\n", n);
            continue;
        }
        printf("%d\n", n + m + min(n, m) - 2);
    }
    return 0;
}