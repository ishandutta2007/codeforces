#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, r=0, ost=0;

    scanf("%d%d", &n, &k);

    for (; n;) {
        r += n;
        ost += n;
        n = 0;
        n = ost / k;
        ost %= k;
    }

    printf("%d\n", r);

    return 0;
}