#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 500100;

int p[55], dp[55][MAX];
vector <int> V;

int main()
{
    int n, d, i, j, tmp;
    vector <int> :: iterator it;

    scanf("%d%d", &n, &d);

    for (i=0; i<n; i++)
        scanf("%d", &p[i]);

    dp[0][0] = 1;

    for (i=0; i<n; i++)
        for (j=0; j<MAX; j++)
            if (dp[i][j])
                dp[i+1][j+p[i]] = dp[i+1][j] = 1;

    for (i=0; i<MAX; i++)
        if (dp[n][i])
            V.push_back(i);

    for (tmp=i=0;; i++) {
        it = upper_bound(V.begin(), V.end(), tmp+d);
        if (it == V.end() || *it > tmp + d)
            it--;
        if (it == V.end() || *it == tmp)
            break;
        else
            tmp = *it;
    }

    printf("%d %d\n", tmp, i);

    return 0;
}