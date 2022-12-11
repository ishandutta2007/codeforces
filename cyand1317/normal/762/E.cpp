#include <cstdio>
#include <algorithm>
#include <map>
typedef long long int64;
static const int INF = 0x7fffffff;
static const int MAXN = 1e5 + 9;
static const int MAXF = 1e4;

int n, k;
struct bstation {
    int id, pos, rg, freq;
    static inline bool cmp_freq(const bstation &lhs, const bstation &rhs) {
        return lhs.freq < rhs.freq;
    }
    static inline bool cmp_rg_r(const bstation &lhs, const bstation &rhs) {
        return lhs.rg > rhs.rg;
    }
} bs[MAXN];
std::map<int, int> coord_discrete;

struct fwk {
    int t[MAXN];
    inline void add(int pos, int inc) { for (; pos < MAXN; pos += (pos & -pos)) t[pos] += inc; }
    inline int sum(int rg) { int ans = 0; for (; rg; rg -= (rg & -rg)) ans += t[rg]; return ans; }
    inline int sum(int lf, int rg) { return sum(rg) - sum(lf - 1); }
} t1 = {{ 0 }}, t2 = {{ 0 }};

bool in_loc[MAXN] = { false };
int in[MAXN] = { 0 };
inline void add(const int id) { in_loc[id] = true; in[bs[id].id] = 2; }
inline void remove(const int id) { in_loc[id] = false; in[bs[id].id] = 0; }
inline void stablize(const int id) { in[bs[id].id] = 1; }
bstation cur[MAXN]; int cur_ct;
inline int64 solve() {
    cur_ct = 0;
    for (int i = 0; i < n; ++i) if (in_loc[i]) cur[cur_ct++] = bs[i];
    std::sort(cur, cur + cur_ct, bstation::cmp_rg_r);
    int64 ans = 0;
    for (int i = 0; i < cur_ct; ++i) {
        std::map<int, int>::iterator
            rg_upper = coord_discrete.upper_bound(cur[i].pos + cur[i].rg),
            rg_lower = coord_discrete.lower_bound(cur[i].pos - cur[i].rg);
        --rg_upper;
        ans += t2.sum(rg_lower->second, rg_upper->second);
        if (in[cur[i].id] == 2) {
            ans += t1.sum(rg_lower->second, rg_upper->second);
            t2.add(coord_discrete[cur[i].pos], +1);
        } else {
            t1.add(coord_discrete[cur[i].pos], +1);
        }
    }
    for (int i = 0; i < cur_ct; ++i) {
        if (in[cur[i].id] == 2)
            t2.add(coord_discrete[cur[i].pos], -1);
        else t1.add(coord_discrete[cur[i].pos], -1);
    }
    return ans;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        bs[i].id = i;
        scanf("%d%d%d", &bs[i].pos, &bs[i].rg, &bs[i].freq);
        coord_discrete[bs[i].pos] = 114514;
    }
    std::sort(bs, bs + n, bstation::cmp_freq);
    coord_discrete[-INF] = coord_discrete[+INF] = 114514;
    int ct = 0;
    for (std::map<int, int>::iterator i = coord_discrete.begin(); i != coord_discrete.end(); ++i)
        i->second = ++ct;

    int tail = 0, head = 0;
    int64 ans = 0;
    for (int f = 1; f <= MAXF; ++f) {
        int last_head = head;
        while (head < n && bs[head].freq == f) add(head++);
        while (tail < head && bs[tail].freq < f - k) remove(tail++);
        ans += solve();
        for (; last_head < head; ++last_head) stablize(last_head);
    }

    printf("%I64d\n", ans);
    return 0;
}