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
#define N 100005
#define P 1000000007
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int dp[10][50];
char s[50][2],t[50][2];
int main()
{
    int i,n,q,j,k;
    cin>>n>>q;
    for(i=1;i<=q;i++)
    {
        scanf("%s",s[i]);
        s[i][0]-=96;
        s[i][1]-=96;
        scanf("%s",t[i]);
        t[i][0]-=96;
    }
    dp[1][1]=1;
    for(i=2;i<=n;i++)
        for(j=1;j<=6;j++)
            for(k=1;k<=q;k++)
                if(t[k][0]==j)
                {
                    //debug(i);
                    //debug(j);
                    //debug(k);
                    //debug(dp[i-1][j]);
                    dp[i][s[k][0]]+=dp[i-1][j];
                }
    int ans=0;
    for(j=1;j<=6;j++)
        ans+=dp[n][j];
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))