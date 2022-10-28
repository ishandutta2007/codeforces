#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define N 4000005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
LL dp[N], sum, c[N];
int main()
{
    int n, P, d;
    cin >> n >> P;
    //dp[1] = 1;
    sum = 0;
    int i, j, nj;

    for(i=1;i<=n;i++)
    {
        sum = (sum + c[i])%P;
        dp[i] = (sum + P) % P;
        if(i == 1)
            dp[i] = 1;
        for(j=2;i*j <= n; j++)
        {
            c[i*j] += dp[i];
            if((i+1)*(j) <= n)
                c[(i+1)*(j)]-= dp[i];
        }
        sum = (sum + dp[i]) % P;
    }
    cout<<dp[n]<<endl;
    return 0;
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);