#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c, r=0, i;

    scanf("%d%d%d", &a, &b, &c);

    for (i=0; i<3; i++)
        r = max(r, min(min(i, a), min(b, c)) + (a-i) / 3 + (b-i) / 3 + (c-i) / 3);

    printf("%d\n", r);

    return 0;
}