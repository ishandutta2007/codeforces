#include <cstdio>
#include <cstring>
typedef long long int64;
static const int MAXLEN = 1000 * 10 + 5;

int a, b;
int64 c = 0;
int mapped[128];
char d[MAXLEN] = { 0 };

const char *ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
const char *tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const char *hdds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};

int main()
{
    memset(mapped, -1, sizeof mapped);
    for (int i = 0; i <= 9; ++i) mapped['0' + i] = i;
    for (int i = 0; i < 26; ++i) mapped['A' + i] = 10 + i;

    //if (scanf("%d%d", &a, &b) == 1) b = -1; getchar();
    char ch;
    scanf("%d", &a); getchar();
    if ((ch = getchar()) == 'R') { b = -1; getchar(); }
    else { b = ch - '0'; while ((ch = getchar()) >= '0' && ch <= '9') b = b * 10 + ch - '0'; }
    while (mapped[ch = getchar()] != -1) c = c * a + mapped[ch];

    if (b == -1) {
        // Roman numbers > <
        // We have LeetCode #12
        for (int i = 0; i < c / 1000; ++i) putchar('M');
        printf("%s%s%s\n", hdds[c / 100 % 10], tens[c / 10 % 10], ones[c % 10]);
    } else if (c == 0) {
        puts("0");
    } else {
        int len;
        for (len = 0; c > 0; ++len) {
            d[len] = c % b; c /= b;
        }
        for (int i = len - 1; i >= 0; --i)
            putchar(d[i] >= 10 ? d[i] - 10 + 'A' : d[i] + '0');
        putchar('\n');
    }

    return 0;
}