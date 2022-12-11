#include <cstdio>
static const int MAXN = 104;
static const int MAXLEN = 104;

int n, s_len = 0, w_len[MAXN] = { 0 };
char w[MAXN][MAXLEN], rep, s[MAXLEN];
bool change[MAXLEN] = { false };
inline char upper_case(const char ch) {
    if (ch >= 'a' && ch <= 'z') return ch - 32; else return ch;
}

inline bool cmp_strings(int w_idx, int s_pos) {
    for (int i = 0; i < w_len[w_idx]; ++i)
        if (w[w_idx][i] != upper_case(s[s_pos + i])) return false;
    return true;
}

int main()
{
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; ++i)
        while ((w[i][w_len[i]] = upper_case(getchar())) != '\n') ++w_len[i];
    while ((s[s_len] = getchar()) != '\n') ++s_len;
    rep = getchar();

    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= s_len - w_len[i]; ++j) if (cmp_strings(i, j)) {
            //printf("Match with word #%d at position %d [%d-%d]\n", i, j, j, j + w_len[i] - 1);
            for (int k = 0; k < w_len[i]; ++k) change[j + k] = true;
        }

    for (int i = 0; i < s_len; ++i) if (change[i]) {
        if (s[i] == rep || s[i] == rep - 32) {
            s[i] = (s[i] == rep ? 'a' : 'A');
            if (rep == 'a') s[i]++;
        } else {
            s[i] = (s[i] >= 'a' ? rep : rep - 32);
        }
    }

    puts(s);
    return 0;
}