#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAX = 1<<17;

char s[MAX];
long long rje[2], dp[2][2][2][MAX]; //poc paran, dulj paran, a ili b

int main()
{
    int i, l, tmpdulj, j, k, ii;

    scanf("%s", s+1);
    l = strlen(s+1);

    for (i=1; i<=l; i++) {
        dp[i%2][1][s[i]-'a'][i] = 1;
        rje[1]++;
        for (j=0; j<2; j++)
            for (k=0; k<2; k++)
                for (ii=0; ii<2; ii++) {
                    tmpdulj = k;
                    if (s[i]-'a' != ii)
                        tmpdulj = (tmpdulj + 1) % 2;
                    dp[j][tmpdulj][s[i]-'a'][i] += dp[j][k][ii][i-1];
                    if (tmpdulj % 2)
                        rje[(i-j+1)%2] += dp[j][k][ii][i-1];
                }
    }

    printf("%I64d %I64d\n", rje[0], rje[1]);

    return 0;
}