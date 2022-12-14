#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int n, m;
long long k;
int p;
long long s[50020];
long long j[50020], v[50020];
map<long long, long long> mp;

set<long long> pr;
set<long long> spr;

long long gets(long long i) {
    if (mp.find(i) != mp.end()) {
        return mp[i];
    }
    return s[i % n];
}

struct mat {
    long long a[2][2];
    
    mat() {
        a[0][0] = 1; a[0][1] = 0;
        a[1][0] = 0; a[1][1] = 1;
    }

    // Mat from M st M * (F[i + 1], F[i]) = (F[i + 2], F[i + 1])
    mat(long long i) {
        a[0][0] = gets(i + 1); a[0][1] = gets(i);
        a[1][0] = 1LL; a[1][1] = 0;
    }

    mat operator*(const mat &o) const {
        mat r;
        r.a[0][0] = a[0][0] * o.a[0][0] + a[0][1] * o.a[1][0];
        if (r.a[0][0] >= p) {
            r.a[0][0] %= p;
        }
        r.a[0][1] = a[0][0] * o.a[0][1] + a[0][1] * o.a[1][1];
        if (r.a[0][1] >= p) {
            r.a[0][1] %= p;
        }
        r.a[1][0] = a[1][0] * o.a[0][0] + a[1][1] * o.a[1][0];
        if (r.a[1][0] >= p) {
            r.a[1][0] %= p;
        }
        r.a[1][1] = a[1][0] * o.a[0][1] + a[1][1] * o.a[1][1];
        if (r.a[1][1] >= p) {
            r.a[1][1] %= p;
        }
        // for (int i = 0; i < 2; ++i) {
        //     for (int j = 0; j < 2; ++j) {
        //         r.a[i][j] = 0;
        //         for (int k = 0; k < 2; ++k) {
        //             r.a[i][j] = (r.a[i][j] + a[i][k] * o.a[k][j]) % p;
        //         }
        //     }
        // }
        return r;
    }

    void dump() {
        printf("MAT %lld %lld ; %lld %lld\n", a[0][0], a[0][1], a[1][0], a[1][1]);
    }
};

mat big;
int sz[512];
mat pc[512];

mat qpow(mat v, long long st) {
    mat r;
    while (st) {
        if (st & 1) {
            r = r * v;
        }
        v = v * v;
        st /= 2;
    }
    return r;
}

int main() {
    scanf("%lld %d", &k, &p);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &s[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%lld %lld", &j[i], &v[i]);
        mp[ j[i] ] = v[i];
        pr.insert(j[i] / n);
        pr.insert((j[i] - 1) / n);
        spr.insert(j[i]);
        spr.insert(j[i] - 1);
    }
    pr.insert(k / n);
    pr.insert((k - 1) / n);
    spr.insert(k);
    spr.insert(k - 1);

    for (int i = 0; i < n; ++i) {
        mat x(i);
        if (i == n - 1) {
            x.a[0][0] = s[0];
        }
        big = x * big;
    }

    int sq = (int) ceil(sqrt(n));
    if (sq <= 0) {
        sq = 1;
    }
    for (int ls = 0; ls * sq < n; ++ls) {
        sz[ls] = 0;
        for (int i = 0; i < sq && ls * sq + i < n; ++i) {
            mat x(ls * sq + i);
            if (ls * sq + i == n - 1) {
                x.a[0][0] = s[0];
            }
            pc[ls] = x * pc[ls];
            sz[ls]++;
        }
    }

    if (k <= 1) {
        printf("%lld\n", k % p);
        return 0;
    }

    long long tm = k - 2;
    pr.insert(tm / n);
    spr.insert(tm);
    mat r;
    long long li = -1;
    while (li < tm) {
        // assume (li + 1) % n == 0
        // At beginning.
        long long in = (li + 1) / n;
        set<long long>::iterator it = pr.lower_bound(in);
        // Can't be pr.end()
        long long lb = *pr.lower_bound(in);
        // Can go large steps until lb - 1;
        r = qpow(big, lb - in) * r;
        li = li + (lb - in) * (long long) n;
        long long ns = *spr.lower_bound(li);
        for (int i = 0; i < n && li < tm;) {
            if (li > ns) {
                ns = *spr.lower_bound(li);
            }
            if (i % sq == 0 && ns - li > sq) {
                r = pc[i / sq] * r;
                li += sz[i / sq];
                i += sz[i / sq];
            } else {
                ++li;
                r = mat(li) * r;
                ++i;
            }
        }
    }
    printf("%lld\n", r.a[0][0] % p);
    return 0;
}