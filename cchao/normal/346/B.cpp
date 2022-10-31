#include <cstdio>
#include <cstring>
#include <iostream>

char a[110], b[110], x[110];
int d[110][110][110], la, lb, lx, f[110];

int dp(int i, int j, int k) {
    if(i >= la || j >= lb) return 0;
    int &ans = d[i][j][k];
    if(ans >= 0) return ans;
    ans = std::max(dp(i, j+1, k), dp(i+1, j, k));
    if(a[i] == b[j]) {
        while(k && x[k] != a[i]) k = f[k];
        if(x[k] == a[i]) ++k;
        if(k < lx) ans = std::max(ans, dp(i+1, j+1, k) + 1);
    }
    return ans;
}

void print(int i, int j, int k) {
    if(i >= la || j >= lb) return;
    if(d[i][j][k] == d[i][j+1][k]) print(i, j+1, k);
    else if(d[i][j][k] == d[i+1][j][k]) print(i+1, j, k);
    else if(a[i] == b[j]) {
        while(k && x[k] != a[i]) k = f[k];
        if(x[k] == a[i]) ++k;
        if(k < lx) {
            putchar(a[i]);
            print(i+1, j+1, k);
        }
    }
}

int main() {
    scanf("%s%s%s", a, b, x);
    la = strlen(a), lb = strlen(b), lx = strlen(x);
    f[0] = f[1] = 0;
    for(int i = 1; i < lx; ++i) {
        int j = f[i];
        while(j && x[i] != x[j]) j = f[j];
        f[i+1] = x[i] == x[j] ? j + 1 : 0;
    }
    memset(d, -1, sizeof d);
    if(dp(0, 0, 0)) { 
        print(0, 0, 0); puts("");
    }
    else puts("0");
    return 0;
}