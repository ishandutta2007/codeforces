#include <cstdio>

int main()
{
    int max_len_outside = 0, ct_inside = 0;
    int n;
    char ch;
    scanf("%d", &n); getchar();

    bool in_prs = false;
    int cur_len = 0, last_isalpha = false;
    for (int i = 0; i <= n; ++i) {
        ch = (i == n ? '_' : getchar());
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            if (last_isalpha) ++cur_len;
            else {  // A whole new word (what?)
                cur_len = 1; last_isalpha = true;
            }
        } else {    // Boundaries
            if (last_isalpha) {
                // The end of the word (?)
                if (in_prs) ++ct_inside;//, printf("%d %c\n", i, ch);
                else if (max_len_outside < cur_len) max_len_outside = cur_len;
                cur_len = 0; last_isalpha = false;
            }
        }
        if (ch == '(') in_prs = true;
        else if (ch == ')') in_prs = false;
    }

    printf("%d %d\n", max_len_outside, ct_inside);
    return 0;
}