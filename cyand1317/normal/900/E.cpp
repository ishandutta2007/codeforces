#include <cstdio>
#include <algorithm>
#include <utility>
static const int MAXN = 1e5 + 4;

static int n, m;
static char s[MAXN];

static int a[MAXN], b[MAXN];
static int pfx[MAXN];

struct state {
    int a1, r1, a2, r2;
    state() : a1(0), r1(0), a2(-1), r2(0) { }
    inline void update(int a, int r) {
        if (a > a1) {
            a2 = a1;
            r2 = r1;
            a1 = a;
            r1 = r;
        } else if (a > a2) {
            if (a == a1) {
                r1 = std::min(r1, r);
            } else {
                a2 = a;
                r2 = r;
            }
        }
    }
    inline int get_ans() { return r1; }
};

static state f[MAXN];

int main()
{
    scanf("%d%s%d", &n, s, &m);

    pfx[0] = 0;
    for (int i = 0; i < n; ++i) pfx[i + 1] = pfx[i] + (s[i] == '?');

    a[0] = (s[0] == 'a' || s[0] == '?');
    b[0] = (s[0] == 'b' || s[0] == '?');
    a[1] = (s[1] == 'a' || s[1] == '?');
    b[1] = (s[1] == 'b' || s[1] == '?');
    for (int i = 2; i < n; ++i) {
        a[i] = (s[i] == 'a' || s[i] == '?') ? (a[i - 2] + 1) : 0;
        b[i] = (s[i] == 'b' || s[i] == '?') ? (b[i - 2] + 1) : 0;
    }

    for (int i = m; i <= n; ++i) {
        f[i] = f[i - 1];
        if ((m % 2 == 0 && b[i - 1] >= m / 2 && a[i - 2] >= m / 2) ||
            (m % 2 == 1 && a[i - 1] >= m / 2 + 1 && (m == 1 || b[i - 2] >= m / 2)))
        {
            f[i].update(f[i - m].a1 + 1, f[i - m].r1 + pfx[i] - pfx[i - m]);
            f[i].update(f[i - m].a2 + 1, f[i - m].r2 + pfx[i] - pfx[i - m]);
        }
    }

    printf("%d\n", f[n].get_ans());

    return 0;
}