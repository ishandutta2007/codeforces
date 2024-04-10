#include <cstdio>
#include <cstring>
static const int MAXN = 10004;

int n, k;
char a[MAXN] = { 0 }, ans_a[MAXN], cur_a[MAXN];
int ct[10] = { 0 };
int mov[10];

int main()
{
    scanf("%d%d", &n, &k); getchar();
    for (int i = 0; i < n; ++i) ct[a[i] = getchar() - '0']++;

    int ans = 0x7fffffff, ans_d = -1;
    int cur, equal_ct;
    for (int d = 0; d < 10; ++d) {
        equal_ct = ct[d];
        cur = 0;
        for (int i = 0; i < 10; ++i) mov[i] = 0;
        if (equal_ct < k) for (int i = 1; i < 10; ++i) {
            if (d + i <= 9) {
                equal_ct += ct[d + i]; cur += i * ct[d + i];
                mov[d + i] = ct[d + i];
                if (equal_ct >= k) {
                    mov[d + i] -= (equal_ct - k);
                    cur -= i * (equal_ct - k); break;
                }
            }
            if (d - i >= 0) {
                equal_ct += ct[d - i]; cur += i * ct[d - i];
                mov[d - i] = ct[d - i];
                if (equal_ct >= k) {
                    mov[d - i] -= (equal_ct - k);
                    cur -= i * (equal_ct - k); break;
                }
            }
        }
        memcpy(cur_a, a, sizeof a);
        for (int i = 0; i < n; ++i) if (a[i] > d && mov[a[i]] > 0) {
            cur_a[i] = d; --mov[a[i]];
        }
        for (int i = n - 1; i >= 0; --i) if (a[i] < d && mov[a[i]] > 0) {
            cur_a[i] = d; --mov[a[i]];
        }
        if (ans > cur) {
            ans = cur;
            memcpy(ans_a, cur_a, sizeof a);
        } else if (ans == cur && strcmp(ans_a, cur_a) > 0) {
            memcpy(ans_a, cur_a, sizeof a);
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; ++i) putchar('0' + ans_a[i]);
    putchar('\n');

    return 0;
}