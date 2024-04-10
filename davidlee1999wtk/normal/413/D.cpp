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
#define N 2005
#define K 13
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int n,k;
int dp[N][1024+1];
int a[N];

int get_next(int x,int y)
{
    if((x&1)&&(y==2))
    {
        if(x>=(1<<k))
            return 1<<k;
        else return y;
    }
    else
    {
        x+=y;
        if(x>=(1<<k))
            return 1<<k;
        return x;
    }
}

inline void upd(int &x,int y)
{
    x+=y;
    if(x>=P)
        x-=P;
}

int main()
{
    int i,s,t;
    cin>>n>>k;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    k--;
    dp[0][0]=1;
    for(i=1;i<=n;i++)
    {
        if(a[i]==2)
        {
            for(s=0;s<=(1<<k);s++)
            {
                t=get_next(s,1);
                upd(dp[i][t],dp[i-1][s]);
            }
        }
        else if(a[i]==4)
        {
            for(s=0;s<=(1<<k);s++)
            {
                t=get_next(s,2);
                upd(dp[i][t],dp[i-1][s]);
            }
        }
        else
        {
            for(s=0;s<=(1<<k);s++)
            {
                t=get_next(s,1);
                upd(dp[i][t],dp[i-1][s]);

                t=get_next(s,2);
                upd(dp[i][t],dp[i-1][s]);
            }
        }
    }
    cout<<dp[n][1<<k]<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/