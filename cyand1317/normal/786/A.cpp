#include <cstdio>
static const int MAXN = 7005;
static const char *str[] = { "Lose", "Win", "Loop" };

int n, k[2];
int s[2][MAXN];

int f[2][MAXN], win_ct[2][MAXN] = {{ 0 }};
void expand_update(int party, int pos)
{
    if (f[party][pos] == 0) {
        for (int i = 0; i < k[party ^ 1]; ++i) {
            int dest = (pos - s[party ^ 1][i] + n) % n;
            if (f[party ^ 1][dest] == 2) {
                f[party ^ 1][dest] = 1;
                //printf("(%d,%d) updates (%d,%d) with %d\n", party, pos, party ^ 1, dest, 1);
                expand_update(party ^ 1, dest);
            }
        }
    } else {
        for (int i = 0; i < k[party ^ 1]; ++i) {
            int dest = (pos - s[party ^ 1][i] + n) % n;
            if (f[party ^ 1][dest] == 2 && ++win_ct[party ^ 1][dest] == k[party ^ 1]) {
                f[party ^ 1][dest] = 0;
                //printf("(%d,%d) updates (%d,%d) with %d\n", party, pos, party ^ 1, dest, 0);
                expand_update(party ^ 1, dest);
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    scanf("%d", &k[0]); for (int i = 0; i < k[0]; ++i) scanf("%d", &s[0][i]);
    scanf("%d", &k[1]); for (int i = 0; i < k[1]; ++i) scanf("%d", &s[1][i]);

    f[0][0] = f[1][0] = 0;
    for (int i = 1; i < n; ++i) f[0][i] = f[1][i] = 2;
    expand_update(0, 0);
    expand_update(1, 0);
    for (int i = 1; i < n; ++i) printf("%s%c", str[f[0][i]], i == n - 1 ? '\n' : ' ');
    for (int i = 1; i < n; ++i) printf("%s%c", str[f[1][i]], i == n - 1 ? '\n' : ' ');

    return 0;
}