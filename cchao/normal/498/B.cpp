#include <bits/stdc++.h>
using namespace std;

inline int ri() {
    char c;
    while(!isdigit(c = getchar())) ;
    int r = 0;
    do {
        r = (r << 3) + (r << 1) + (c - '0');
    } while(isdigit(c = getchar()));
    return r;
}

int n, s, p[5010], t[5010];
double dp[5010][5010] = {{}}, pss[110][5010];

int main() {
    n = ri();
    s = ri();
    for(register int i = n; i >= 1; --i) {
        p[i] = ri();
        t[i] = ri();
    }

    for(register int i = 0; i <= 100; ++i) {
        pss[i][0] = 1;
        for(register int j = 1; j <= 5000; ++j)
            pss[i][j] = pss[i][j-1] * i / 100.0;
    }

    for(register int i = 1; i <= n; ++i) {
        register double sum = 0;
        register double pa = p[i] / 100.0;
        register double pb = 1 - pa;
        double *ps = pss[100 - p[i]];
        for(register int j = 1; j <= s; ++j) {
            sum *= pb;
            if(j > t[i]) sum -= (dp[i - 1][j - t[i] - 1] + 1) * ps[t[i]];
            if(j >= t[i]) sum += (dp[i - 1][j - t[i]] + 1) * ps[t[i] - 1] * pb;
            sum += (dp[i - 1][j - 1] + 1) * pa;
            dp[i][j] = sum;
        }
    }
    printf("%.12f\n", dp[n][s]);
    return 0;
}