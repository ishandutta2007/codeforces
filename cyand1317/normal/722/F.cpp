#include <cstdio>
#include <utility>
#include <vector>
static const int MAXN = 100005;
static const int MAXM = 100005;
static const int MAXK = 41;
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }

int n, m;
int k[MAXN];
std::vector< std::pair<int, int> > occ[MAXM];
#define seqidx  first
std::pair<int, int> seg[MAXN];
#define seqlen  first
#define seqpos  second
int rg[MAXN];

int main()
{
    scanf("%d%d", &n, &m);
    int seq_elm;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k[i]);
        for (int j = 0; j < k[i]; ++j) {
            scanf("%d", &seq_elm);
            occ[seq_elm].push_back(std::make_pair(i, j));
        }
    }

    for (int x = 1; x <= m; ++x) {
        int ans = 0;
        for (int i = 0, j; i < (int)occ[x].size(); i = j) {
            seg[0] = std::make_pair(k[occ[x][i].seqidx], occ[x][i].seqpos);
            j = i + 1;
            while (j < (int)occ[x].size() && occ[x][j].seqidx == occ[x][j - 1].seqidx + 1) {
                seg[j - i] = std::make_pair(k[occ[x][j].seqidx], occ[x][j].seqpos);
                ++j;
            }
            int seglen = j - i; // **Segment** length and **Sequence** length
            std::pair<int, int> r1, r2;
        #define remval  second
            for (int ww = 0; ww < seglen; ++ww) rg[ww] = seglen;
            for (int cyc = 1; cyc <= MAXK; ++cyc) {
                // r1.seqidx <= r2.seqidx should hold at any moment
                r1 = std::make_pair(seglen, -321);
                r2 = std::make_pair(seglen, -321);
                for (int u = seglen - 1; u >= 0; --u) if (seg[u].seqlen % cyc == 0) {
                    int offset = seg[u].seqpos % cyc;
                    if (offset == r1.remval) {
                        rg[u] = min(rg[u], r2.seqidx);
                        r1.seqidx = u;
                    } else {
                        rg[u] = min(rg[u], r1.seqidx);
                        r2 = r1; r1 = std::make_pair(u, offset);
                    }
                }
            }
        #undef remval
            int min_rg = seglen;
            for (int u = seglen - 1; u >= 0; --u) {
                min_rg = min(min_rg, rg[u]);
                ans = max(ans, min_rg - u);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}