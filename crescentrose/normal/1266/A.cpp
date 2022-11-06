#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
char s[10000];
int even, all;
int main() {
    scanf("%d", &n);
    while (n --) {
        scanf("%s", s);
        int len = strlen(s);
        bool have_zero = 0;
        all = even = 0;
        for (int i = 0; i < len; i ++)
            if (s[i] == '0' && !have_zero)
                have_zero = 1;
            else {
                if ((s[i] - '0') % 2 == 0) even = 1;
                all += s[i] - '0';
            }
        if (all == 0) {
            printf("red\n");
        }else
            have_zero && even && all %3 == 0?printf("red\n") :printf("cyan\n");
    }
    return 0;
}