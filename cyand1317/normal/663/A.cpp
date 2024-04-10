#include <cstdio>
static const int MAXL = 106;

int n, l = 0;
bool isplus[MAXL];
int ct[2] = { 0, 0 };
int pos[MAXL], neg[MAXL];

int main()
{
    char ch;
    isplus[0] = true;
    while ((ch = getchar()) == '?') {
        getchar();
        isplus[++l] = (getchar() == '+');
        getchar();
    }
    n = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9')
        n = n * 10 + ch - '0';

    for (int i = 0; i < l; ++i) ++ct[isplus[i]];
    if (ct[1] * n - ct[0] < n || ct[1] - ct[0] * n > n) {
        puts("Impossible");
    } else {
        puts("Possible");
        int cur = ct[1] * n - ct[0], t1 = 0, t2 = 0;
        for (int i = 0; i < ct[0]; ++i) neg[i] = 1;
        for (int i = 0; i < ct[1]; ++i) pos[i] = n;
        while (cur > n) {
            if (t1 < ct[0]) {
                if (++neg[t1] == n) ++t1;
            } else {
                if (--pos[t2] == 1) ++t2;
            }
            --cur;
        }
        printf("%d", pos[0]);
        t1 = 0, t2 = 1;
        for (int i = 1; i < l; ++i) {
            printf(" %c %d",
                isplus[i] ? '+' : '-',
                isplus[i] ? pos[t2++] : neg[t1++]);
        }
        printf(" = %d\n", n);
    }
    return 0;
}