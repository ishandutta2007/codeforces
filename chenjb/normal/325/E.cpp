#include <cstdio>
#include <cstdlib>
#include <cstring>
 
#define N 500020
 
using namespace std;
 
int n, v[N], q[N], tail;
 
void dfs(int x) {
    if (!v[x*2+1]) {
        v[x*2+1] = 1;
        dfs((x*2+1) % (n/2));
        q[++tail] = (x*2+1) % n;
    }
    if (!v[x*2+0]) {
        v[x*2+0] = 1;
        dfs((x*2+0) % (n/2));
        q[++tail] = (x*2+0) % n;
    }
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
#endif
    while (~scanf("%d", &n)) {
        if (n&1) {
            puts("-1");
            continue;
        }
        memset(v, 0, sizeof(v));
        printf("0");
        dfs(0);
        for (; tail; tail--) printf(" %d", q[tail]);
        puts("");
    }
    return 0;
}