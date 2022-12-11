#include <cstdio>
#include <algorithm>
static const int MAXN = 200007;

struct request {
    int id;
    int t, d;
    long long finish;
} req[MAXN];
inline bool operator < (request lhs, request rhs)
{
    return lhs.t < rhs.t;
}

int n, b;
int q[MAXN], qhead = 0, qtail = 0;
long long ans[MAXN];

int main()
{
    scanf("%d%d", &n, &b);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &req[i].t, &req[i].d);
        req[i].id = i;
    }
    std::sort(req, req + n);

    for (int i = 0; i < n; ++i) {
        int now = req[i].t;
        while (qtail < qhead && req[q[qtail]].finish <= now) ++qtail;
        if (qhead == qtail) {
            req[i].finish = (long long)now + req[i].d;
            q[qhead++] = i;
        } else if (qhead - qtail <= b) {
            req[i].finish = req[q[qhead - 1]].finish + req[i].d;
            q[qhead++] = i;
        } else {
            req[i].finish = -1;
        }
    }

    for (int i = 0; i < n; ++i) ans[req[i].id] = req[i].finish;
    printf("%I64d", ans[0]);
    for (int i = 1; i < n; ++i) printf(" %I64d", ans[i]);
    putchar('\n');

    return 0;
}