#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int SIZE = 101;
int a[SIZE];
bool check(int n) {
    for(int i = 1; i <= n; i++) {
        if(a[i] == i) { return 0; }
    }
    return 1;
}
void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        a[i] = i;
    }
    while(1) {
        random_shuffle(a + 1, a + n + 1);
        if(check(n)) { break; }
    }
    for(int i = 1; i <= n; i++) {
        if(i > 1) { printf(" ");}
        printf("%d", a[i]);
    }
    puts("");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}