#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

const int MAX = 31623, MOD = 1000000007;

typedef long long ll;

map <int, int> M;
int sito[MAX], prosti[MAX], dp[505][MAX];

int main()
{
    int i, j, ind=0, n, tmp, r=1;
    map <int, int> :: iterator it;

    for (i=2; i<MAX; i++) {
        if (!sito[i]) {
            prosti[ind++] = i;
            for (j=i; j<MAX; j+=i)
                sito[j] = 1;
        }
    }

    scanf("%d", &n);

    for (i=0; i<n; i++) {
        scanf("%d", &tmp);
        for (j=0; j<ind; j++)
            for (; !(tmp%prosti[j]); tmp/=prosti[j])
                M[j]++;
        if (tmp > 1)
            M[tmp]++;
    }

    dp[0][0] = 1;

    for (i=1; i<=n; i++)
        for (j=0; j<MAX; j++) {
            dp[i][j] = dp[i-1][j];
            if (j)
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
        }

    for (it=M.begin(); it!=M.end(); it++)
        r = (int) (((ll) r * dp[n][it->second]) % MOD);

    printf("%d\n", r);

    return 0;
}