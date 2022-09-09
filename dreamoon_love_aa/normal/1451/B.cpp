#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
char s[128];
bool good(int l, int r, int n) {
    for(int i = 1; i < l; i++) {
        if(s[i] == s[l]) {
            return 1;
        }
    }
    for(int i = r + 1; i <= n; i++) {
        if(s[i] == s[r]) {
            return 1;
        }
    }
    return 0;
}
void solve() {
    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);
    while(q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        if(good(l, r, n)) { puts("YES"); }
        else { puts("NO"); }
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}