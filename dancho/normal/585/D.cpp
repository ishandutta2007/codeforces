#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

typedef pair<int, int> pii;

char tp[][4] = {"LM", "LW", "MW"};
int se[4][4] = {{1, 1, 0}, {1, 0, 1}, {0, 1, 1}};

struct sl {
    long long va;
    int ty[32];
};

map<pii, sl> be;

int n;
int d[32][3];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &d[i][j]);
        }
    }
    int ha = n / 2;
    int d3 = 1;
    for (int i = 0; i < ha; ++i) {
        d3 *= 3;
    }
    for (int i = 0; i < d3; ++i) {
        int x[3];
        memset(x, 0, sizeof(x));
        int r = i;
        sl s;
        for (int j = 0; j < ha; ++j) {
            int t = r % 3;
            for (int l = 0; l < 3; ++l) {
                x[l] += se[t][l] * d[j][l];
            }
            s.ty[j] = t;
            r /= 3;
        }
        s.va = x[0];
        // printf("ITER %d -> %d %d %d [%d %d]\n", i, 
        pii k = make_pair(x[1] - x[0], x[2] - x[0]);
        if (be.find(k) == be.end()) {
            be[k] = s;
        } else {
            if (be[k].va < s.va) {
                be[k] = s;
            }
        }
    }
    if (!ha) {
        pii k = make_pair(0, 0);
        sl s;
        s.va = 0;
        be[k] = s;
    }

    int re = n - ha;
    // printf("A %d %d\n", ha, re);
    // printf("BS %d\n", (int) be.size());
    sl ans;
    ans.va = -(1LL << 62);
    d3 = 1;
    for (int i = 0; i < re; ++i) {
        d3 *= 3;
    }
    for (int i = 0; i < d3; ++i) {
        int x[3];
        memset(x, 0, sizeof(x));
        int r = i;
        sl s;
        for (int j = ha; j < n; ++j) {
            int t = r % 3;
            for (int l = 0; l < 3; ++l) {
                x[l] += se[t][l] * d[j][l];
            }
            s.ty[j] = t;
            r /= 3;
        }
        s.va = x[0];
        pii k = make_pair(x[0] - x[1], x[0] - x[2]);
        if (be.find(k) == be.end()) {
        } else {
            sl b = be[k];
            if (b.va + s.va > ans.va) {
                ans.va = b.va + s.va;
                for (int j = 0; j < ha; ++j) {
                    ans.ty[j] = b.ty[j];
                }
                for (int j = ha; j < n; ++j) {
                    ans.ty[j] = s.ty[j];
                }
            }
        }
    }
    if (ans.va != -(1LL << 62)) {
        for (int i = 0; i < n; ++i) {
            printf("%s\n", tp[ans.ty[i]]);
        }
    } else {
        printf("Impossible\n");
    }
    return 0;
}