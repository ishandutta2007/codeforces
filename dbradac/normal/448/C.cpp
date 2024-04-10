#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int MAX = 5010;

int p[MAX];

int Rek(int l, int r)
{
    int i, ind, rje=-MAX, minn;

    if (l > r)
        return 0;

    for (i=l; i<=r; i++) {
        if (i == l || p[i] < minn) {
            minn = p[i];
            ind = i;
        }
    }

    rje = r - l + 1;

    for (i=l; i<=r; i++)
        p[i] -= minn;

    rje = min(rje, minn + Rek(l, ind-1) + Rek(ind+1, r));

    return rje;
}

int main()
{
    int i, n;

    scanf("%d", &n);

    for (i=0; i<n; i++)
        scanf("%d", &p[i]);

    printf("%d\n", Rek(0, n-1));

    return 0;
}