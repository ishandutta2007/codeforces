#include <stdio.h>

int main()
{
    int n, i, j, cur_zeroes, tot_zeroes = 0;
    char ch;
    char rmvd[100008] = { 0 };
    int rmvd_top = -1;
    unsigned char one_appeared, is_beautiful;
    scanf("%d", &n); getchar();
    for (i = 0; i < n; ++i) {
        is_beautiful = 1;
        one_appeared = 0;
        cur_zeroes = 0;
        while ((ch = getchar()) != ' ' && ch != '\n' && ch != EOF) {
            if (!is_beautiful) {
                rmvd[rmvd_top++] = ch - '0';
            } else if (ch == '0') {
                if (one_appeared) ++cur_zeroes;
            } else if (ch == '1') {
                if (one_appeared) {
                    rmvd[0] = 1;
                    rmvd[cur_zeroes + 1] = 1;
                    rmvd_top = cur_zeroes + 2;
                    is_beautiful = 0;
                } else {
                    one_appeared = 1;
                }
            } else {
                if (one_appeared) {
                    rmvd[0] = 1;
                    rmvd[cur_zeroes + 1] = ch - '0';
                    rmvd_top = cur_zeroes + 2;
                } else {
                    rmvd[0] = ch - '0';
                    rmvd_top = 1;
                }
                is_beautiful = 0;
            }
        }
        if (is_beautiful && !one_appeared) {
            puts("0"); return 0;
        }
        if (is_beautiful) tot_zeroes += cur_zeroes;
    }
    if (rmvd_top != -1) {
        for (i = 0; i < rmvd_top; ++i) putchar('0' + rmvd[i]);
    } else putchar('1');
    for (i = 0; i < tot_zeroes; ++i) putchar('0');
    return 0;
}