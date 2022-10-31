#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 100100;

int p[2][MAX], dp[305][MAX], ind[MAX];
vector <int> V[MAX];

int main()
{
    int vel[2], i, j, poce, e1, rj=0;
    vector <int> :: iterator it;

    scanf("%d%d%d%d", &vel[0], &vel[1], &poce, &e1);

    for (i=0; i<2; i++)
        for (j=1; j<=vel[i]; j++)
            scanf("%d", &p[i][j]);

    for (i=1; i<=vel[0]; i++)
        V[p[0][i]].push_back(i);

    memset(dp, -1, sizeof dp);

    dp[0][0] = 0;

    for (i=1; i<=vel[1]; i++) {
        for (j=0; j<304; j++) {
            if (dp[j][i-1] != -1) {
                it = lower_bound(V[p[1][i]].begin(), V[p[1][i]].end(), dp[j][i-1]+1);
                if (it != V[p[1][i]].end()) {
                    if (dp[j+1][i] == -1 || *it < dp[j+1][i]) {
                        dp[j+1][i] = *it;
                        if ((j+1) * e1 + i + *it <= poce)
                            rj = max(rj, j+1);
                    }
                }
            }
            if (dp[j][i] == -1 || (dp[j][i] > dp[j][i-1] && dp[j][i-1] != -1))
                dp[j][i] = dp[j][i-1];
        }
    }

    printf("%d\n", rj);

    return 0;
}