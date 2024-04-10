#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1000100, LOG = 20;

int lca[LOG][MAX], dub[MAX];

int Udalj(int a, int b)
{
    int i, l=0, raz;

    if (dub[a] > dub[b])
        swap(a, b);

    l = raz = dub[b] - dub[a];

    /*int da=0;
    if (max(a, b) == 12 && min(a, b) == 10)
        da= 1;*/

    for (i=0; raz; raz>>=1, i++)
        if (raz & 1)
            b = lca[i][b];

    if (a == b)
        return l;

    for (i=LOG-1; i>=0; i--) {
        if (lca[i][a] != lca[i][b]) {
            /*if (da)
                printf("LLLLLLL %d %d %d %d\n", a, b, i, 1 << (i+1));*/
            a = lca[i][a];
            b = lca[i][b];
            l += 1 << (i+1);
        }
    }

    return l + 2;
}

int main()
{
    int n, q, i, j, najdublji=1, najdub=1, najdalji=2, tmp;

    n = 4;
    dub[1] = dub[2] = dub[3] = 1;

    scanf("%d", &q);

    for (i=0; i<q; i++, n+=2) {
        scanf("%d", &tmp); tmp--;
        lca[0][n] = lca[0][n+1] = tmp;
        for (j=1; j<LOG; j++)
            lca[j][n] = lca[j][n+1] = lca[j-1][lca[j-1][n]];
        dub[n] = dub[n+1] = dub[tmp] + 1;
        if (dub[n] > najdub) {
            if (Udalj(najdublji, n) > Udalj(najdalji, n))
                najdalji = najdublji;
            najdub = dub[n];
            najdublji = n;
        }
        else {
            /*if (tmp == 4)
                printf("AAAAAAAS %d %d %d %d\n", n+1, najdublji+1, Udalj(n, najdublji), Udalj(najdublji, najdalji));*/
            if (Udalj(n, najdublji) > Udalj(najdublji, najdalji)) {
                najdalji = n;
            }
        }
        printf("%d\n", Udalj(najdublji, najdalji));
    }

    /*for (i=0; i<5; i++)
        printf("LCA %d %d\n", lca[i][12], lca[i][10]);*/

    return 0;
}