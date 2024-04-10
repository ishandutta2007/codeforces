#include <stdio.h>

int n;
int a_last, a_cur;

int main()
{
    scanf("%d", &n);
    a_last = a_cur = -1;
    do {
        a_last = a_cur;
        scanf("%d", &a_cur);
    } while (--n);

    if (a_last == -1)
        puts(a_cur == 15 ? "DOWN" : (a_cur == 0 ? "UP" : "-1"));
    else if (a_last < a_cur)
        puts(a_cur == 15 ? "DOWN" : "UP");
    else
        puts(a_cur == 0 ? "UP" : "DOWN");

    return 0;
}