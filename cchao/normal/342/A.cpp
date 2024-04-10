#include <cstdio>

bool solve(int *c, int *ans) {
    if(c[5] || c[7]) return false;
    while(c[3] > 0) {
        c[3]--;
        if(!c[1] || !c[6]) return false;
        else {
            c[1]--, c[6]--;
            ans[2]++;
        }
    }
    while(c[1] > 0) {
        c[1]--;
        if(!c[2]) return false;
        else {
            c[2]--;
            if(!c[4] && !c[6]) return false;
            if(c[4] > c[6]) { c[4]--; ans[0]++; }
            else {c[6]--; ans[1]++; }
        }
    }
    for(int i = 0; i <= 7; ++i) if(c[i] > 0) return false;
    return true;
}

int main() {
    int n, t, c[10] = {0}; scanf("%d", &n);
    while(n--) {
        scanf("%d", &t);
        c[t]++;
    }
    int ans[4] = {0};
    if(!solve(c, ans)) {
        puts("-1");
    }
    else {
        while(ans[0]--) puts("1 2 4");
        while(ans[1]--) puts("1 2 6");
        while(ans[2]--) puts("1 3 6");
    }
    return 0;
}