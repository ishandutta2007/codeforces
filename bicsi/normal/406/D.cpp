#include<bits/stdc++.h>
using namespace std;

int64_t X[200000], Y[200000];
int ST[200000], ste;

int Parent[20][200000], D[200000];

int64_t det(int a, int b, int c) {
    return (X[b] - X[a]) * (Y[c] - Y[b]) - (X[c] - X[b]) * (Y[b] - Y[a]);
}

int pl(int node, int lev) {
    for(int i=0; (1<<i)<=lev; i++)
        if(lev & (1 << i))
            node = Parent[i][node];
    return node;
}

int lca(int a, int b) {
    if(D[a] > D[b]) a = pl(a, D[a] - D[b]);
    else            b = pl(b, D[b] - D[a]);

    if(a == b) return a;

    int i;
    for(i=0; (1<<i)<=D[a]; i++);
    for(i--; i>=0; i--) {
        if(Parent[i][a] != Parent[i][b])
            a = Parent[i][a],
            b = Parent[i][b];
    }

    return Parent[0][a];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    int n, m, a, b;

    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%I64d %I64d", &X[i], &Y[i]);

    for(int i=n; i; i--) {
        while(ste >= 2 && det(i, ST[ste], ST[ste-1]) > 0)
            ste--;

        for(int j=0, node=ST[ste]; node; node=Parent[j++][node])
            Parent[j][i] = node;
        D[i] = D[ST[ste]] + 1;

        ST[++ste] = i;
    }

    scanf("%d", &m);
    while(m--) {
        scanf("%d %d", &a, &b);
        printf("%d ", lca(a, b));
    }


    return 0;
}