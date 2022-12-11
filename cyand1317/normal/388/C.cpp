#include <cstdio>
static const int MAXN = 104;
static const int MAXS = 103;
template <typename T> inline bool upd_max(T &var, const T val) { if (var < val) { var = val; return true; } else return false; }

int n;
int s[MAXN];
int c[MAXN][MAXS];
int odd_used[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &s[i]);
        for (int j = 0; j < s[i]; ++j) scanf("%d", &c[i][j]);
        odd_used[i] = -1;
    }

    bool turn = false;  // false - Ciel (first elm.), true - Jiro (last elm.)
    int score[2] = { 0, 0 };
    while (true) {
        int best = -1, best_idx = -1;
        for (int i = 0; i < n; ++i) if (s[i] % 2 == 1 && odd_used[i] == -1) {
            if (upd_max(best, c[i][s[i] / 2])) best_idx = i;
        }
        if (best == -1) break;
        odd_used[best_idx] = turn;
        score[turn] += best;
        turn ^= 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < s[i] / 2; ++j) score[0] += c[i][j];
        for (int j = (s[i] + 1) / 2; j < s[i]; ++j) score[1] += c[i][j];
    }

    printf("%d %d\n", score[0], score[1]);
    return 0;
}