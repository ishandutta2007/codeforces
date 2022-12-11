// Let's try this without editorials (_)
#include <cstdio>
#include <cmath>
typedef long long int64;
static const int MAXR = 1e7 + 3;
static const int MAXR_SQRT = 3165;  //(int)(sqrt(MAXR) + 3);
static const int LOGR_SQRT = 24;

int n, l, r;
bool coprime[MAXR_SQRT][MAXR_SQRT] = {{ false }};
int coprime_pfx[MAXR_SQRT][MAXR_SQRT] = {{ 0 }};

int t[LOGR_SQRT];
void stern_brocot(int n)
{
    //static int max = 0; if (max < n) printf("%d\n", max = n);
    for (t[n + 1] = t[n] + t[n - 1]; t[n + 1] < MAXR_SQRT; t[n + 1] += t[n]) {
        coprime[t[n]][t[n + 1]] = coprime[t[n + 1]][t[n]] = true;
        stern_brocot(n + 1);
    }
}

void preprocess_coprimality()
{
    t[0] = t[1] = 1; stern_brocot(1);
    /*printf("    | "); for (int i = 1; i <= 10; ++i) printf("%d%c", i, i == 10 ? '\n' : ' ');
    for (int i = 1; i <= 10; ++i) {
        printf(" %2d | ", i);
        for (int j = 1; j <= 10; ++j) printf("%d%c", coprime[i][j], j == 10 ? '\n' : ' ');
    }*/
    for (int i = 0; i < MAXR_SQRT; ++i) {
        coprime_pfx[i][0] = 0;
        for (int j = 0; j < MAXR_SQRT; ++j)
            coprime_pfx[i][j] = coprime_pfx[i][j - 1] + coprime[i][j];
    }
}

int main()
{
    preprocess_coprimality();
    scanf("%d%d%d", &n, &l, &r);

    if (n == 1) { printf("%d\n", r - l + 1); return 0; }
    else if (n == 2) { printf("%I64d\n", (int64)(r - l + 1) * (r - l)); return 0; }

    // Let d = q/p (q > p, gcd(p, q) = 1)
    // A[1] = a * p^(n-1), A[n] = a * q^(n-1)
    // Fix a and go on
    int64 ans = 0;
    int64 last = 0;
    int last_ceil = -1, last_floor = -1;
    for (int a = 1; a <= r; ++a) {
        // A[1] >= l and A[n] <= r
        // Therefore p^(n-1) >= ceil(l/a), q^(n-1) <= floor(r/a)
        int cur_ceil = (int)ceil(pow((double)l / a, 1.0 / (n - 1)) - 1e-8),
            cur_floor = (int)floor(pow((double)r / a, 1.0 / (n - 1)) + 1e-8);
        // Since only ceil(l/a) and floor(r/a) are involved, we can skip several values
        if (cur_ceil == last_ceil && cur_floor == last_floor) {
            ans += last; continue;
        }
        // The following will happen at most ~2 R times
        // Count the number of pairs (p, q) where ceil <= p < q <= floor and gcd(p, q) = 1
        // ceil and floor will be at most R since n >= 3
        last = 0;
        for (int p = cur_ceil; p <= cur_floor; ++p)
            last += coprime_pfx[p][cur_floor] - coprime_pfx[p][p];
        ans += last;
        last_ceil = cur_ceil, last_floor = cur_floor;
    }

    printf("%I64d\n", ans * 2);
    return 0;
}