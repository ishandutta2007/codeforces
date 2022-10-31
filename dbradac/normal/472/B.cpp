#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1<<11;

int p[MAX];

int main()
{
    int n, i, k, r=0;

    scanf("%d%d", &n, &k);

    for (i=0; i<n; i++) {
        scanf("%d", &p[i]);
        p[i]--;
    }

    sort(p, p+n);

    for (i=n-1; i>=0; i-=k)
        r += 2 * p[i];

    printf("%d\n", r);

    return 0;
}