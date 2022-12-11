#include <cstdio>
#include <cstdlib>
typedef long long int64;
static const int MAXN = 50;
static const int MAXK = 300;
static const int LAYERS = 37;

int64 t;
int r1[MAXK], c1[MAXK], r2[MAXK], c2[MAXK], k = 0;

inline void add_wall(int R1, int C1, int R2, int C2, bool flip = false) {
    if (flip) r1[k] = R1, c1[k] = C1, r2[k] = R2, c2[k] = C2;
    else r1[k] = C1, c1[k] = R1, r2[k] = C2, c2[k] = R2;
    ++k;
}

int main()
{
    srand(114514);
    scanf("%I64d", &t);

    int n = 2, m = 2;
    for (int pow = 0; t > 0; t /= 3, ++pow) {
        ++n, ++m;
        if (pow >= 1) {
            add_wall(3 + pow, pow, 3 + pow, pow + 1);
            add_wall(pow, 3 + pow, pow + 1, 3 + pow);
            if (pow >= 3) {
                add_wall(3 + pow, pow - 2, 3 + pow, pow - 1);
                add_wall(pow - 2, 3 + pow, pow - 1, 3 + pow);
            }
        }
        bool qwq = rand() & 1;
        switch (t % 3) {
            case 0: add_wall(3 + pow, pow + 1, 4 + pow, pow + 1, qwq);
            case 1: add_wall(pow + 1, 3 + pow, pow + 1, 4 + pow, qwq);
            case 2: default: break;
        }
    }
    ++n, ++m;
    if (n > 5) {
        add_wall(n, m - 5, n, m - 4);
        add_wall(n - 5, m, n - 4, m);
    }
    add_wall(n - 1, m - 2, n, m - 2);
    add_wall(n - 1, m - 1, n, m - 1);
    add_wall(n - 2, m - 1, n - 2, m);
    add_wall(n - 1, m - 1, n - 1, m);

    printf("%d %d\n%d\n", n, m, k);
    for (int i = 0; i < k; ++i) printf("%d %d %d %d\n", r1[i], c1[i], r2[i], c2[i]);

    return 0;
}