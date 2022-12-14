#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int mod = 1000000007;

int n;
// int psz[10000020];
// int pd[10000020][8];

int fd[10000020];
// vector<int> pd[10000020];
char mu[10000020];

// int nor(int x) {
//     // for (int i = 0; i < psz[x]; ++i) {
//     for (int i = 0; i < (int) pd[x].size(); ++i) {
//         long long de = pd[x][i];
//         while (x % (de * de) == 0) {
//             x /= de;
//         }
//     }
//     return x;
// }
// 

int nor(int x) {
    if (x == 1) {
        return 1;
    }
    if (x % ((long long) fd[x] * fd[x]) == 0) {
        return nor(x / fd[x]);
    }
    return fd[x] * nor(x / fd[x]);
}

inline vector<int> gd(int x) {
    vector<int> r;
    while (x > 1) {
        r.push_back(fd[x]);
        x /= fd[x];
    }
    return r;
}

int match[10000020];
int no[10000020];
long long d2[1000020];
long long gc[10000020];

int main() {
    memset(mu, 0, sizeof(mu));
    // memset(psz, 0, sizeof(psz));
    int am = 0;
    for (long long i = 2; i <= 10000000; ++i) {
        // if (i <= 10) {
        //     printf("FD %lld %d %d __ %d %d\n", i, fd[i], (int) mu[i], 6, (int) mu[6]);
        // }
        // if (!psz[i]) {
        //     pd[i][psz[i]++] = i;
        if (!mu[i]) {
            fd[i] = i;
            // pd[i].push_back(i);
            for (int j = i + i; j <= 10000000; j += i) {
                fd[j] = i;
                if ((long long) j % (i * i) == 0) {
                    mu[j] = 1;
                } else if (mu[j] == 0) {
                    mu[j] = 2;
                }
            }
        }
    }
    // printf("A %d\n", am);
    // printf("PC FIN\n");
    long long ans = 0;
    memset(no, 0, sizeof(no));
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        ++no[nor(a)];
        vector<int> de = gd(nor(a));
        for (int ma = 0; ma < (1 << de.size()); ++ma ){
            int di = 1;
            for (int j = 0; j < (int) de.size(); ++j) {
                if (ma & (1 <<j)) {
                    di *= de[j];
                }
            }
            ++match[di];
        }
    }
    d2[0] = 1;
    for (int i = 1; i <= 1000000; ++i) {
        d2[i] = d2[i - 1] * 2;
        if (d2[i] >= mod) {
            d2[i] -= mod;
        }
    }
    memset(gc, 0, sizeof(gc));
    for (int i = 10000000; i >= 2; --i) {
        if (mu[i] == 1) {
            continue;
        }
        gc[i] += d2[match[i]] - 1;
        if (gc[i] >= mod) {
            gc[i] -= mod;
        }

        if (gc[i]) {
            vector<int> ds = gd(i);

            for (int ma = 0; ma + 1 < (1 << ds.size()); ++ma) {
                int di = 1;
                for (int j = 0; j < (int) ds.size(); ++j) {
                    if (ma & (1 << j)) {
                        di *= ds[j];
                    }
                }
                gc[di] += mod - gc[i];
                if (gc[di] >= mod) {
                    gc[di] %= mod;
                }
            }
        }
    }
    for (int i = 2; i <= 10000000; ++i) {
        if (mu[i] == 1) {
            continue;
        }

        long long ncp = 0;

        vector<int> ds = gd(i);
        for (int ma = 1; ma < (1 << ds.size()); ++ma) {
            int di = 1;
            // for (int j = 0; j < psz[i]; ++j) {
            int si = -1;
            for (int j = 0; j < (int) ds.size(); ++j) {
                if (ma & (1 << j)) {
                    di *= ds[j];
                    si = -si;
                }
            }
            ncp += mod + si * match[di];
            if (ncp >= mod) {
                ncp %= mod;
            }
        }
        ans += (long long) gc[i] * ((long long) n - ncp);
        if (ans >= mod) {
            ans %= mod;
        }
    }

    printf("%lld\n", ans);
    return 0;
}