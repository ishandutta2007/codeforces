#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
void solve() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        if(n % 2 == 1) {
            if(n == 1) { puts("0"); }
            else if(n == 3) { puts("2"); }
            else puts("3");
        } else {
            if(n == 2) { puts("1"); }
            else { puts("2"); }
        }
    }
}
int main() {
    solve();
    return 0;
}