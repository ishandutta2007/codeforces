#include <cstdio>
#include <cstring>

int main()
{
    int a, b;
    int m;
    scanf("%d %d", &a, &b);
    if (a > b)
        m = a;
    else
        m = b;

    char ans[32];
    if (m == 1)
        strcpy(ans, "1/1");
    else if (m == 2)
        strcpy(ans, "5/6");
    else if (m == 3)
        strcpy(ans, "2/3");
    else if (m == 4)
        strcpy(ans, "1/2");
    else if (m == 5)
        strcpy(ans, "1/3");
    else if (m == 6)
        strcpy(ans, "1/6");
    printf("%s\n", ans);
    return 0;
}