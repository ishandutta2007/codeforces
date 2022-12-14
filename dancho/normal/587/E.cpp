#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const unsigned mask = (1LL << 31) - 1;

struct Elem {
    unsigned red;
    unsigned orig;
};

inline unsigned lsb(unsigned x) {
    return (x & (-x));
}

bool cmpU(unsigned a, unsigned b) {
    return lsb(a) < lsb(b);
}

bool cmp(Elem a, Elem b) {
    return lsb(a.red) < lsb(b.red);
}

struct GaussSet {
    unsigned x;
    vector<unsigned> base;
    vector<int> orig;
    // vector<Elem> base;
    // vector<int> rest;
    int even;

    void build(const vector<int> &st) {
        base.clear();
        orig.clear();
        x = 0;
        even = -1;
        for (int i = 0; i < (int) st.size(); ++i) {
            unsigned e = st[i];
            e ^= (1LL << 31);
            for (int j = 0; j < (int) base.size(); ++j) {
                if (e & base[j] & (-base[j])) {
                    e ^= base[j];
                }
            }
            if ((e & mask) == 0) {
                if (e != 0 || st[i] == 0) {
                    even = st[i];
                }
                // rest.push_back(e.orig);
            } else {
                for (int j = 0; j < (int) base.size(); ++j) {
                    if (e & (-e) & base[j]) {
                        base[j] ^= e;
                    }
                }
                base.push_back(e);
                orig.push_back(st[i]);
                // sort(base.begin(), base.end(), cmpU);
            }
        }
    }

    void upd() {
        if (!x) {
            return;
        }
        vector<int> a = orig;
        for (int i = 0; i < (int) a.size(); ++i) {
            a[i] = a[i] ^ x;
        }
        if (even != -1) {
            a.push_back(even ^ x);
        }
        int fr = a.size();
        build(a);
        int to = base.size() + (even != -1);
    }

    void print() {
        printf("BASE %d %d\n", (int) base.size(), even);
        for (int j = 0; j < (int) base.size(); ++j) {
            printf("EL %u %u\n", (base[j] & mask), orig[j]);
        }
        printf("\n\n");
    }
};

int n, q;

GaussSet tr[1 << 20];
int a[1 << 20];

void merge(GaussSet &tar, const GaussSet &l, const GaussSet &r) {
    vector<int> c = l.orig;
    if (l.even != -1) {
        c.push_back(l.even);
    }
    for (int j = 0; j < (int) r.orig.size(); ++j) {
        c.push_back(r.orig[j]);
    }
    if (r.even != -1) {
        c.push_back(r.even);
    }
    tar.build(c);
}

void build() {
    vector<int> b(1);
    for (int i = (1 << 19) - 1; i > 0; --i) {
        if (i >= (1 << 18)) {
            b[0] = a[i - (1 << 18)];
            tr[i].build(b);
        } else {
            vector<int> c;
            int l, r;
            l = 2 * i;
            r = 2 * i + 1;
            merge(tr[i], tr[l], tr[r]);
        }
    }
}

bool go(GaussSet &tmp, int nd, int nl, int nr, int l, int r) {
    bool ch = false;
    if (tr[nd].x) {
        if (nl != nr) {
            tr[nd * 2].x ^= tr[nd].x;
            tr[nd * 2 + 1].x ^= tr[nd].x;
        }
        tr[nd].upd();
        ch = true;
    }
    if (l > nr || nl > r) {
        return ch;
    }
    if (l <= nl && nr <= r) {
        merge(tmp, tmp, tr[nd]);
        return ch;
    }
    go(tmp, nd * 2, nl, (nl + nr) / 2, l, r);
    go(tmp, nd * 2 + 1, (nl + nr) / 2 + 1, nr, l, r);
    // merge(tr[nd], tr[nd * 2], tr[nd * 2 + 1]);
    return false;
}

void go(GaussSet &tmp, int l, int r) {
    go(tmp, 1, 0, (1 << 18) - 1, l, r);
}

void upd(int nd, int nl, int nr, int l, int r, int k) {
    // if (tr[nd].x) {
    //     if (nl != nr) {
    //         tr[nd * 2].x ^= tr[nd].x;
    //         tr[nd * 2 + 1].x ^= tr[nd].x;
    //     }
    //     tr[nd].upd();
    // }
    if (l <= nl && nr <= r) {
        tr[nd].x ^= k;
    }
    if (tr[nd].x) {
        if (nl != nr) {
            tr[nd * 2].x ^= tr[nd].x;
            tr[nd * 2 + 1].x ^= tr[nd].x;
        }
        tr[nd].upd();
    }
    if (nl > r || l > nr) {
        return;
    }
    if (l <= nl && nr <= r) {
        return;
    }
    upd(nd * 2, nl, (nl + nr) / 2, l, r, k);
    upd(nd * 2 + 1, (nl + nr) / 2 + 1, nr, l, r, k);
    merge(tr[nd], tr[nd * 2], tr[nd * 2 + 1]);
}

void upd(int l, int r, int k) {
    upd(1, 0, (1 << 18) - 1, l, r, k);
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    build();

    for (int i = 0; i < q; ++i) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int l, r, k;
            scanf("%d %d %d", &l, &r, &k);
            --l; --r;
            upd(l, r, k);
        } else if (tp == 2) {
            int l, r;
            scanf("%d %d", &l, &r);
            --l; --r;
            GaussSet tmp;
            tmp.x = 0;
            tmp.even = -1;
            go(tmp, l, r);
            printf("%lld\n", (1LL << tmp.base.size()));
        }
    }
    return 0;
}