#include <cstdio>
#include <set>
#include <utility>

static const int MAXN = 200002;
typedef std::pair<int, int> handshake;
#define id second
#define num first
#define handshake_create std::make_pair
#define handshake_query(_q) (std::make_pair(_q, 0))

int main()
{
    int n, a;
    scanf("%d", &n);
    std::set<handshake> hs;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        hs.insert(handshake_create(a, i + 1));
    }

    int last = 0, seq[MAXN], seqtop = 0;
    do {
        std::set<handshake>::iterator p = hs.lower_bound(handshake_query(last));
        while ((p == hs.end() || p->num != last) && last >= 0)
            p = hs.lower_bound(handshake_query(last -= 3));
        if (last < 0) break;
        seq[seqtop++] = p->id;
        hs.erase(p);
        ++last;
    } while (!hs.empty());
    if (hs.empty()) {
        printf("Possible\n%d", seq[0]);
        for (int i = 1; i < n; ++i) printf(" %d", seq[i]);
        putchar('\n');
    } else {
        puts("Impossible");
    }
    return 0;
}