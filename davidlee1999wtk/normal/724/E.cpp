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
#include<iomanip>
#include<deque>
#include<utility>
#define INF 1000000000
#define fi first
#define se second
#define N 10005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
LL dp[2][N];
int p[N],s[N];
void upd(LL &x,LL y)
{
    if(x==-1)
        x=y;
    else if(x>y)
        x=y;
}

int main()
{
    int n,i,j;
    int c;
    LL *f1,*f2,ans=-1;
    cin>>n>>c;
    for(i=1;i<=n;i++)
        scanf("%d",&p[i]);
    for(i=1;i<=n;i++)
        scanf("%d",&s[i]);

    f1=dp[0];
    f2=dp[1];

    memset(dp,-1,sizeof(dp));
    f1[0]=0;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<i;j++)
        {
            //printf("%d ",f1[j]);
            upd(f2[j],f1[j]+p[i]+(LL)j*c);
            upd(f2[j+1],f1[j]+s[i]);
        }
        //debug(i-1);
        swap(f1,f2);
        memset(f2,-1,N*8);
    }
    for(j=0;j<=n;j++)
    {
        //debug(f1[j]);
        upd(ans,f1[j]);
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*
10 1
0 2 1 1 0 2 5 2 5 5
4 0 1 4 2 4 4 5 2 3
*/