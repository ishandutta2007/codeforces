#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
#define int long long
const int MOD=998244353;
const int N=2005;

void init()
{

}

int n,m,k;
int dp[N][N];
void solve()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    dp[1][0]=m;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
            if(j) dp[i][j]=(dp[i][j]+dp[i-1][j-1]*(m-1)%MOD)%MOD;
        }
    }
    printf("%lld\n",dp[n][k]);
}

signed main()
{
    int TTT=1; //scanf("%d",&TTT);
    while(TTT--){init(); solve();}
    return 0;
}