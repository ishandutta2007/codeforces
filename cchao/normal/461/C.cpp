#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 10;
int a[maxn]={}, n, q, b[maxn];
inline int lb(int x) { return x & -x; }
void add(int x, int v) { for(; x <= n; x += lb(x)) a[x] += v; }
int sum(int x) { int r = 0; for(; x >= 1; x -= lb(x)) r += a[x]; return r; }

int main() {
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; ++i) { b[i] = 1; add(i, 1); }
    bool rev = false;
    int x = 1, l = n;
    while(q--) {
        int op, a1, a2;
        scanf("%d%d", &op, &a1);
        if(op == 1) {
            if(a1 > l / 2) { a1 = l - a1; rev = !rev; }
            int d = rev ? -1 : 1;
            l -= a1; if(d == 1) x += a1;
            int i = d == 1 ? x : x + l - 1;
            int j = i - d;
            while(a1--) {
                b[i] += b[j];
                add(i, b[j]);
                i += d; j -= d;
            }
        }
        else {
            scanf("%d", &a2); a2--;
            if(rev) a1 = l - a1 - 1, a2 = l - a2 - 1;
            if(a1 > a2) swap(a1, a2);
            a1 += x; a2 += x;
            int ans = sum(a2) - sum(a1-1);
            printf("%d\n", ans);
        }
    }
    return 0;
}