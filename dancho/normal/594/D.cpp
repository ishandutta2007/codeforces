#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int mod = 1000000007;

struct query {
    int l, id;
};

int fd[1 << 20];
int la[1 << 20];

int n;
int a[1 << 18];

vector<query> qu[1 << 18];

long long it[1 << 19];
long long out[1 << 18];

void it_mul(int nd, int nl, int nr, int le, int ri, long long m) {
    if (le <= nl && nr <= ri) {
        it[nd] *= m;
        if (it[nd] >= mod) {
            it[nd] %= mod;
        }
        return;
    }
    if (le > nr || nl > ri) {
        return;
    }
    it_mul(nd * 2, nl, (nl + nr) / 2, le, ri, m);
    it_mul(nd * 2 + 1, (nl + nr) / 2 + 1, nr, le, ri, m);
}

void it_mul(int le, int ri, long long m) {
    if (le <= ri) {
        // printf("MUL %d %d %lld\n", le, ri, m);
        it_mul(1, 0, (1 << 18) - 1, le, ri, m);
    }
}

long long it_get(int pos) {
    int p = pos;
    long long res = 1;
    pos = pos + (1 << 18);
    while (pos) {
        res *= it[pos];
        if (res >= mod) {
            res %= mod;
        }
        pos /= 2;
    }
    // printf("GET %d %lld\n", p, res);
    return res;
}

void poke(int i, int p) {
    it_mul(0, la[p], p);
    it_mul(la[p] + 1, i, p - 1);

    la[p] = i;
}

int main() {
    memset(fd, 0, sizeof(fd));
    for (int i = 2; i < (1 << 20); ++i) {
        if (fd[i] == 0) {
            for (int j = i + i; j < (1 << 20); j += i) {
                if (fd[j] == 0) {
                    fd[j] = i;
                }
            }
        }
    }

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        --l; --r;
        query qq;
        qq.id = i;
        qq.l = l;
        qu[r].push_back(qq);
    }

    for (int i = 0; i < (1 << 19); ++i) {
        it[i] = 1;
    }
    memset(la, -1, sizeof(la));
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        while (fd[x]) {
            poke(i, fd[x]);
            x /= fd[x];
        }
        if (x != 1) {
            poke(i, x);
        }
        for (int j = 0; j < (int) qu[i].size(); ++j) {
            out[qu[i][j].id] = it_get(qu[i][j].l);
        }
    }

    for (int i = 0; i < q; ++i) {
        printf("%lld\n", out[i]);
    }

    return 0;
}