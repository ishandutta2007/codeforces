#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <queue>
using namespace std;

const int sz = 161;

void pmat(char a[sz][sz], int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

typedef pair<int, int> pii;

int n, m;
int a[sz], b[sz], d[sz];

vector<pii> vp;

// void zomm(char a[sz][sz], char b[sz][sz], char c[sz][sz]) {
//     bitset<sz> A[sz], B[sz];
//     for (int i = 0; i < sz; ++i) {
//         for (int j = 0; j < sz; ++j) {
//             A[i][j] = (a[i][j] != 0);
//         }
//     }
//     for (int i = 0; i < sz; ++i) {
//         for (int j = 0; j < sz; ++j) {
//             B[i][j] = (b[j][i] != 0);
//         }
//     }
//     for (int i = 0; i < sz; ++i) {
//         for (int j = 0; j < sz; ++j) {
//             c[i][j] = (A[i] & B[j]).any();
//         }
//     }
// }

// N ^ 2
void zomm(char a[sz][sz], char b[sz][sz], char c[sz][sz]) {
    long long A[sz][4], B[sz][4];
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            if (a[i][j]) {
                A[i][j / 60] |= (1LL << (j % 60));
            }
        }
    }
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            if (b[j][i]) {
                B[i][j / 60] |= (1LL << (j % 60));
            }
        }
    }
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            unsigned long long l = 0;
            for (int k = 0; k <= 3; ++k) {
                if (A[i][k] & B[j][k]) {
                    l = 1;
                }
            }
            if (l != 0) {
                c[i][j] = 1;
            } else {
                c[i][j] = 0;
            }
        }
    }
}


// N ^ 2 log
void mpow(char s[sz][sz], long long st, char r[sz][sz]) {
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            r[i][j] = 0;
        }
        if (i >= 1 && i <= n) {
            r[i][i] = 1;
        }
    }
    while (st) {
        if (st & 1) {
            zomm(s, r, r);
        }
        st /= 2;
        zomm(s, s, s);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &a[i], &b[i], &d[i]);
        vp.push_back(make_pair(d[i], i));
    }

    sort(vp.begin(), vp.end());

    char mat[sz][sz];
    char em[sz][sz];
    memset(em, 0, sizeof(em));
    int i = 0;
    memset(mat, 0, sizeof(mat));
    for (int j = 1; j <= n; ++j) {
        mat[j][j] = 1;
    }
    long long di = 0;
    long long bs = (1LL << 62);
    for (; i < m; ++i) {
        char m2[sz][sz];
        char r[sz][sz];
        queue<int> r1;
        long long ds[sz];
        memset(ds, -1, sizeof(ds));
        for (int j = 1; j <= n; ++j) {
            if (mat[1][j]) {
                r1.push(j);
                ds[j] = 0;
            }
        }
        while (r1.size()) {
            int v = r1.front();
            r1.pop();
            for (int j = 1; j <= n; ++j) {
                if (ds[j] == -1 && em[v][j]) {
                    ds[j] = ds[v] + 1;
                    r1.push(j);
                }
            }
        }
        if (ds[n] != -1) {
            bs = min(bs, di + ds[n]);
        }

        // didn't quite work. add edges
        memcpy(r, em, sizeof(r));
        mpow(r, vp[i].first - di, m2);
        zomm(mat, m2, mat);
        int j = vp[i].second;
        em[a[j]][b[j]] = 1;
        di = vp[i].first;
    }
        char m2[sz][sz];
        memcpy(m2, mat, sizeof(m2));
        queue<int> r1;
        long long ds[sz];
        memset(ds, -1, sizeof(ds));
        for (int j = 1; j <= n; ++j) {
            if (m2[1][j]) {
                r1.push(j);
                ds[j] = 0;
            }
        }
        while (r1.size()) {
            int v = r1.front();
            r1.pop();
            for (int j = 1; j <= n; ++j) {
                if (ds[j] == -1 && em[v][j]) {
                    ds[j] = ds[v] + 1;
                    r1.push(j);
                }
            }
        }
        if (ds[n] != -1) {
            bs = min(bs, di + ds[n]);
        }

    if (bs == (1LL << 62)) {
        printf("Impossible\n");
    } else {
        printf("%d\n", (int) bs);
    }

    return 0;
}