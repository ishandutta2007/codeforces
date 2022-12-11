#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
typedef long long int64;
static const int64 INF64 = 1LL << 62;

static const int NUM_HEROES = 7;
static const char *heroes[NUM_HEROES] = {
    "Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"
};

int n;
bool g[NUM_HEROES][NUM_HEROES] = {{ false }};
int group_liking[1 << NUM_HEROES] = { 0 };
int64 a, b, c;

inline int hero_id_by_name(const char *s) {
    for (int i = 0; i < NUM_HEROES; ++i)
        if (strcmp(s, heroes[i]) == 0) return i;
    return -1;  // Should not be reached
}

inline int64 xp_difference(int i, int j, int k) {
    int64 ans = std::abs(a / i - b / j);
    ans = std::max(ans, std::abs(a / i - c / k));
    ans = std::max(ans, std::abs(b / j - c / k));
    return ans;
}

int main()
{
    scanf("%d", &n);
    char s1[24], s2[24];
    for (int i = 0; i < n; ++i) {
        scanf("%s%*s%s", s1, s2);
        g[hero_id_by_name(s1)][hero_id_by_name(s2)] = true;
    }
    scanf("%I64d%I64d%I64d", &a, &b, &c);

    for (int mask = 0; mask < (1 << NUM_HEROES); ++mask) {
        for (int i = 0; i < NUM_HEROES; ++i) if ((mask >> i) & 1)
            for (int j = 0; j < NUM_HEROES; ++j) if ((mask >> j) & 1)
                group_liking[mask] += g[i][j];
    }

    int64 best_diff = INF64;
    for (int i = 1; i <= NUM_HEROES - 2; ++i)
        for (int j = 1; j <= NUM_HEROES - 1 - i; ++j) {
            int k = NUM_HEROES - i - j;
            best_diff = std::min(best_diff, xp_difference(i, j, k));
        }

    int best_liking = 0;
    for (int i = 1; i <= NUM_HEROES - 2; ++i)
        for (int j = 1; j <= NUM_HEROES - 1 - i; ++j) {
            int k = 7 - i - j;
            if (xp_difference(i, j, k) == best_diff) {
                static int p[NUM_HEROES];
                for (int u = 0; u < NUM_HEROES; ++u) p[u] = u;
                int cur_liking, mask;
                do {
                    cur_liking = 0;
                    mask = 0; for (int u = 0; u < i; ++u) mask |= (1 << p[u]);
                    cur_liking += group_liking[mask];
                    mask = 0; for (int u = i; u < i + j; ++u) mask |= (1 << p[u]);
                    cur_liking += group_liking[mask];
                    mask = 0; for (int u = i + j; u < NUM_HEROES; ++u) mask |= (1 << p[u]);
                    cur_liking += group_liking[mask];
                    best_liking = std::max(best_liking, cur_liking);
                } while (std::next_permutation(p, p + NUM_HEROES));
            }
        }

    printf("%I64d %d\n", best_diff, best_liking);

    return 0;
}