#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c, d, e, f, n;

    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &n);

    if ((int) ((a+b+c+4) / 5) + (int) ((d+e+f+9) / 10) > n)
        printf("NO\n");
    else
        printf("YES\n");

    return 0;
}