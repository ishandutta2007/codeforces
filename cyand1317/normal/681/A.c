#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    char handle[32]; int bef, aft;
    do {
        scanf("%s%d%d", handle, &bef, &aft);
        if (bef >= 2400 && bef < aft) {
            puts("YES");
            return 0;
        }
    } while (--n);
    puts("NO");
    return 0;
}