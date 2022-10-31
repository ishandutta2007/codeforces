#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 1<<18, maxnode = maxn * 3;
struct ZKW {
    int n, node[maxnode];
    void init(int n) {
        memset(this, 0, sizeof(ZKW));
        this->n = n;
    }
    void update_node(int i, int j) {
        int lc = i << 1, rc = (i<<1) + 1;
        if(j == 0) node[i] = node[lc] | node[rc];
        else node[i] = node[lc] ^ node[rc];
    }
    void update(int x, int d) {
        x += n - 1;
//      printf("%d is update to %d\n", x, d);
        node[x] = d;
        int f = 0;
        for(x >>= 1; x; x>>= 1, f ^= 1)
            update_node(x, f);
    }
} zkw;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    zkw.init(1<<n);
    int a, b;
    for(int i = 1; i <= zkw.n; ++i) {
        scanf("%d", &b);
        zkw.update(i, b);
    }
    //printf("first %d\n", zkw.node[1]);
    while(m--) {
        scanf("%d%d", &a, &b);
        zkw.update(a, b);
        printf("%d\n", zkw.node[1]);
    }
    return 0;
}