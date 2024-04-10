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
#define N 505
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int sum[N][N],h[505][505],s[N][N];
char mp[N][N];
int main()
{
    int H,w,i,j,q,r1,c1,r2,c2,ans;
    cin>>H>>w;
    for(i=1;i<=H;i++)
        scanf("%s",mp[i]+1);
    for(i=1;i<=H;i++)
    {
        for(j=1;j<=w;j++)
        {
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
            h[i][j]=h[i-1][j]+h[i][j-1]-h[i-1][j-1];
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
            if(mp[i][j]=='.')
            {
                if(mp[i+1][j]=='.')
                {
                    s[i][j]++;
                    sum[i][j]++;
                }
                if(mp[i][j+1]=='.')
                {
                    h[i][j]++;
                    sum[i][j]++;
                }
            }
        }
    }
    cin>>q;
    while(q--)
    {
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        ans=0;
        if(r2>r1&&c2>c1)
            ans+=sum[r2-1][c2-1]-sum[r1-1][c2-1]-sum[r2-1][c1-1]+sum[r1-1][c1-1];
        //debug(ans);
        if(c2>c1)
            ans+=h[r2][c2-1]-h[r2][c1-1]-h[r2-1][c2-1]+h[r2-1][c1-1];
        //debug(ans);
        if(r2>r1)
            ans+=s[r2-1][c2]-s[r1-1][c2]-s[r2-1][c2-1]+s[r1-1][c2-1];
        printf("%d\n",ans);
    }
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))