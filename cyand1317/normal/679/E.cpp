#include <cstdio>
#include <algorithm>
typedef long long int64;
static const int MAXN = 100005;
static const int MAXQ = 100005;
static const int QUQ_SZ = 12;

int n, q;
int t[MAXN];
int64 quq[QUQ_SZ];

namespace sgt {

static const int MAXN = ::MAXN * 2;
int sz = 0;
int l[MAXN], r[MAXN], lch[MAXN], rch[MAXN];
unsigned char pow[MAXN]; int64 val[MAXN], atag[MAXN], itag[MAXN];

// int64...
// mdzz... (`)
inline void refine_pow(int idx, int64 orig_val) {
    int p = std::lower_bound(quq, quq + QUQ_SZ, orig_val) - &quq[0];
    pow[idx] = p;
    val[idx] = quq[p] - orig_val;
}
inline void refine_pow(int idx) {
    refine_pow(idx, quq[pow[idx]] - val[idx]);
}
inline void apply_atag(int idx, int64 V) {
    refine_pow(idx, V);
    itag[idx] = 0; atag[idx] = V;
}
inline void apply_itag(int idx, int64 V) {
    val[idx] -= V; //refine_pow(idx);
    if (atag[idx] != 0) atag[idx] += V; else itag[idx] += V;
}
inline void push(int idx) {
    if (lch[idx] == -1) return;
    if (atag[idx] != 0) {
        apply_atag(lch[idx], atag[idx]);
        apply_atag(rch[idx], atag[idx]);
    }
    if (itag[idx] != 0) {
        apply_itag(lch[idx], itag[idx]);
        apply_itag(rch[idx], itag[idx]);
    }
    atag[idx] = itag[idx] = 0;
}
inline void update(int idx) {
    val[idx] = std::min(val[lch[idx]], val[rch[idx]]);
}

inline int build(int L, int R) {
    int idx = sz++;
    l[idx] = L, r[idx] = R;
    if (L == R) {
        refine_pow(idx, t[L]);
        lch[idx] = rch[idx] = -1;
    } else {
        int M = (L + R) >> 1;
        lch[idx] = build(L, M);
        rch[idx] = build(M + 1, R);
        update(idx);
    }
    atag[idx] = itag[idx] = 0;
    return idx;
}
inline void build(int n) {
    build(0, n - 1);
}

int QL, QR, QV;
int64 query(int idx) {
    push(idx);
    if (lch[idx] == -1) return quq[pow[idx]] - val[idx];
    if (r[lch[idx]] >= QL) return query(lch[idx]); else return query(rch[idx]);
}
inline int64 query_elm(int P) {
    QL = P; return query(0);
}

void print() {
    for (int i = 0; i < sz; ++i) {
        printf("[%d] | [%d,%d] Lch=%d Rch=%d Pow=%lld Val=%lld",
            i, l[i], r[i], lch[i], rch[i], quq[pow[i]], val[i]);
        if (atag[i]) printf(" Atag=%lld", atag[i]);
        if (itag[i]) printf(" Itag=%lld", itag[i]);
        putchar('\n');
    }
}

int QTY;
void modify(int idx) {
    push(idx);
    //printf("%d [%d,%d] Lch=%d Rch=%d\n", idx, l[idx], r[idx], lch[idx], rch[idx]);
    if (l[idx] >= QL && r[idx] <= QR) {
        (QTY == 1 ? apply_atag : apply_itag)(idx, QV); return;
    }
    if (r[lch[idx]] >= QL) modify(lch[idx]);
    if (l[rch[idx]] <= QR) modify(rch[idx]);
    update(idx);
}
bool handle_quqs(int idx) {
    push(idx);
    if (val[idx] < 0) {
        if (lch[idx] == -1) {
            refine_pow(idx);
        } else {
            handle_quqs(lch[idx]);
            handle_quqs(rch[idx]);
            update(idx);
        }
    }
    return val[idx] == 0;
}
inline void assign(int L, int R, int V) {
    QL = L, QR = R, QV = V, QTY = 1; modify(0);
}
inline void increase(int L, int R, int V) {
    QL = L, QR = R, QV = V, QTY = 2; do modify(0); while (handle_quqs(0));
}

}

int main()
{
    quq[0] = 1;
    for (int i = 1; i < QUQ_SZ; ++i) quq[i] = quq[i - 1] * 42;

    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) scanf("%d", &t[i]);
    sgt::build(n);

    int ty, arg1, arg2, arg3;
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &ty, &arg1);
        if (ty != 1) scanf("%d%d", &arg2, &arg3);
        switch (ty) {
            case 1: printf("%I64d\n", sgt::query_elm(arg1 - 1)); break;
            case 2: sgt::assign(arg1 - 1, arg2 - 1, arg3); break;
            case 3: sgt::increase(arg1 - 1, arg2 - 1, arg3); break;
            default: puts(" (`)  "); break;
        }
    }

    return 0;
}