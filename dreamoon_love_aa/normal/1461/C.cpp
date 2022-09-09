#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int SIZE = 1 << 20;
int a[SIZE];
void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int rr = n;
    while(rr >= 1 && a[rr] == rr) { rr--; }
    double an = 1;
    for(int i = 0; i < m; i++) {
        int r;
        double p;
        scanf("%d%lf", &r, &p);
        if(r >= rr) {
            an *= 1 - p;
        }
    }
    if(rr == 0) puts("1");
    else {
        an = 1 - an;
        printf("%.12f\n", an);
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}