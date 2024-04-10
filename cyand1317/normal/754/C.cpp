#include <cstdio>
#include <cstring>
static const int MAXN = 105;
static const int MAXM = 105;
static const int MAXUSERLEN = 15;
static const int MAXMSGLEN = 128;

int n, m;
char uname[MAXN][MAXUSERLEN];
int sender[MAXM];
char _msg[MAXM][MAXMSGLEN], *msg[MAXM];
bool mentions[MAXM][MAXN];

bool feas[MAXM][MAXN] = {{ false }};
int last[MAXM][MAXN];

inline bool nonword(const char c) {
    return !(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9');
}
inline bool contains_word(char *line, char *wd, int wdlen) {
    char *occ = line;
    while ((occ = strstr(occ, wd)) != NULL) {
        if ((occ == line || nonword(*(occ - 1))) && nonword(*(occ + wdlen))) return true;
        occ++;
    }
    return false;
}

void work()
{
    memset(uname, 0, sizeof uname);
    memset(sender, 0, sizeof sender);
    memset(_msg, 0, sizeof _msg);
    memset(feas, 0, sizeof feas);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%s", uname[i]);
    scanf("%d", &m); getchar();
    for (int i = 0; i < m; ++i) {
        gets(_msg[i]);
        char *occ = strchr(_msg[i], ':');
        *occ = '\0'; msg[i] = occ + 1;
        if (_msg[i][0] == '?') sender[i] = -1;
        else for (int j = 0; j < n; ++j) if (strcmp(_msg[i], uname[j]) == 0) { sender[i] = j; break; }
        //printf("%d - %s\n", sender[i], msg[i]);
    }

    for (int j = 0; j < n; ++j) {
        int unamelen = strlen(uname[j]);
        for (int i = 0; i < m; ++i) {
            // As a whole word... My carelessness T^T
            mentions[i][j] = contains_word(msg[i], uname[j], unamelen);
        }
    }
    //for (int i = 0; i < m; ++i)
    //    for (int j = 0; j < n; ++j) printf("%d%c", mentions[i][j], j == n - 1 ? '\n' : ' ');

    feas[0][n] = true;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) if (!mentions[i][j]) {
            bool valid = false;
            if (sender[i] == -1) {
                for (int k = 0; k <= n; ++k) if (k != j && feas[i][k]) {
                    feas[i + 1][j] = true; last[i + 1][j] = k; break;
                }
            } else if (sender[i] == j) {
                for (int k = 0; k <= n; ++k) if (k != j && feas[i][k]) {
                    feas[i + 1][j] = true; last[i + 1][j] = k; break;
                }
            }
        }
    //for (int i = 0; i <= m; ++i)
    //    for (int j = 0; j < n; ++j) printf("%d%c", feas[i][j], j == n - 1 ? '\n' : ' ');

    bool ans = false; int ans_last = -1;
    for (int i = 0; i < n; ++i) if (feas[m][i]) { ans = true; ans_last = i; }
    if (!ans) { puts("Impossible"); return; }
    for (int i = m - 1; i >= 0; --i) { sender[i] = ans_last; ans_last = last[i + 1][ans_last]; }
    for (int i = 0; i < m; ++i) printf("%s:%s\n", uname[sender[i]], msg[i]);
}

int main()
{
    int t; scanf("%d", &t);
    do work(); while (--t);
    return 0;
}