#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int SIZE = 1 << 20;
char s[SIZE];
void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        if(i < k) {
            putchar('a');
        } else {
            putchar('a' + (i + 1 - k) % 3);
        }
    }
    puts("");
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}