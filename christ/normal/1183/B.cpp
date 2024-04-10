#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    scanf("%i", &q);
    while (q--)
    {
        int n, k;
        scanf("%i%i", &n, &k);
        int mi = INT_MAX, ma = INT_MIN, a;
        for (int x = 0; x < n; x++)
        {
            scanf("%i", &a);
            mi = min(mi, a);
            ma = max(ma, a);
        }
        if (ma - mi > 2 * k)
            printf("-1\n");
        else
            printf("%i\n", mi + k);
    }
}