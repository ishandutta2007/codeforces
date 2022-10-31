#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAX = 82000, POL = MAX/2;

char s[4010];
int sum[MAX], pref[MAX], p[4010];

int Ok(int x)
{
    return x >= 0 && x < MAX;
}

int main()
{
    int n, br, i, j;
    ll rje=0;

    scanf("%d%s", &br, s);
    n = strlen(s);

    for (i=0; i<n; i++)
        p[i+1] = s[i] - '0';

    for (i=1; i<=n; i++)
        pref[i] = pref[i-1] + p[i];

    for (i=1; i<=n; i++)
        for (j=i; j<=n; j++)
            sum[pref[j]-pref[i-1]+POL]++;

    if (!br) {
        //printf("%d\n", sum[POL]);
        for (i=0; i<MAX; i++)
            rje += (ll) sum[i] * sum[POL];
        rje = rje * 2 - (ll) sum[POL] * sum[POL];
    }
    else
        for (i=0; i<MAX; i++)
            if (i != POL && !(br % (i-POL)) && Ok(br / (i-POL) + POL))
                rje += (ll) sum[i] * sum[br / (i-POL) + POL];

    printf("%I64d\n", rje);

    return 0;
}