#include<bits/stdc++.h>
int solve() {
    int a, b;
    scanf("%d%d", &a, &b);
    if(a == b) return 0;
    if(a < b) {
        if((b - a) % 2) return 1;
        else return 2;
    }
    else {
        if((a - b) % 2) return 2;
        return 1;
    }
}
int main() {
    int T;
    scanf("%d", &T);
    for(int cs = 1; cs <= T; cs++) {
        printf("%d\n", solve());
    }
    return 0;
}