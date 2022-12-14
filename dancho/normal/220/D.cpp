#include <ctime>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int mod = 1000000007;

int gcd(int a, int b) {
    while(b) a %= b, std::swap(a, b);
    return a;
}

int w, h;

int gc[4020][4020];
int co[4020][4020];

int main() {
    scanf("%d %d", &w, &h);
    long long n = (w + 1) * (h + 1);
    long long tot = (((n * (n - 1)) % mod) * (n - 2)) % mod;
    // printf("TOT %lld\n", tot);
    long long cl = clock();
    for (int i = 1; i < 4010; ++i) {
        for (int j = 1; j < 4010; ++j) {
            if (i > j) {
                gc[i][j] = gc[j][i];
            // } if (!pr[i]) {
            //     if (j % i == 0) {
            //         gc[i][j] = i;
            //     } else {
            //         gc[i][j] = 1;
            //     }
            } else {
                gc[i][j] = gcd(j, i);
            }
        }
    }

    // printf("r1 finished: %lf\n", (double) (clock() - cl) / CLOCKS_PER_SEC);
    memset(co, 0, sizeof(co));
    for (int i = 1; i < 4010; ++i) {
        for (int j = 1; j < 4010; ++j) {
            co[i][j] = gc[i][j] - 1 + co[i][j - 1] + co[i - 1][j] - co[i - 1][j - 1];
        }
    }
    // printf("PC finished: %lf\n", (double) (clock() - cl) / CLOCKS_PER_SEC);
    for (int i = 0; i <= w; ++i) {
        for (int j = 0; j <= h; ++j) {
            long long li;
            li = co[i][j];
            // if (li)
                // printf("LIa %d %d -> %lld\n", i, j, li);
            li += co[w - i][j];
            // if (li)
                // printf("LIb %d %d -> %lld\n", i, j, li);
            li += (j) * (j - 1) / 2;
            // if (li)
                // printf("LIc %d %d -> %lld\n", i, j, li);
            li += (i) * (i - 1) / 2;
            // if (li)
                // printf("LId %d %d -> %lld\n", i, j, li);
            if (li >= mod) {
                li %= mod;
            }
            tot = tot - 6LL * li;
            while (tot < 0) {
                tot += mod;
            }
            if (tot >= mod) {
                tot %= mod;
            }
            // Remove odd x1*y2 - x2*y1
            //
            // 3 odd, 1 even -> 4 ways
            long long evi = i / 2 + (w - i) / 2;
            long long oddi = w - evi;
            long long evj = j / 2;
            long long oddj = j - evj;
            ++evi;
            // ++evj;
            // printf("OP %d %d -> %lld %lld ; %lld %lld\n", i, j, evi, oddi, evj, oddj);

            long long oddf = 0;
            long long p;
            long long q;
            p = oddi * oddj;
            if (p >= mod) {
                p %= mod;
            }
            q = oddi * evj;
            if (q >= mod) {
                q %= mod;
            }
            oddf += p * q;
            q = oddj * evi;
            if (q >= mod) {
                q %= mod;
            }
            oddf += p * q;

            q = evj * evi;
            if (q >= mod) {
                q %= mod;
            }
            oddf += p * q;
            oddf *= 6;
            if (oddf >= mod) {
                oddf %= mod;
            }
            // printf("ODD faces %lld\n", oddf);
            tot -= oddf;
            if (tot < 0) {
                tot += mod;
            }

            // Odd to the right & odd top
            //
            oddi = i - i / 2;
            // printf("ODDR %lld %lld %lld\n", oddi, oddj, (long long) w + 1);
            p = oddi * oddj;
            if (p >= mod) {
                p %= mod;
            }
            q = p * 6LL * (w + 1);
            if (q >= mod) {
                q %= mod;
            }
            tot -= q;
            if (tot < 0) {
                tot += mod;
            }
            tot %= mod;
        }
    }
    printf("%lld\n", tot);
    return 0;
}