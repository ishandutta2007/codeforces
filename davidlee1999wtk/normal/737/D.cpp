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
#define N 4005
#define M 67
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int dp[N][M][M];
int a[N],sl[N],sr[N];
void upd(int &x,int y)
{
    if(x<y)
        x=y;
}
int main()
{
    int n,i,j,l,k,mn1,mn2,mn3,mn4,t,ti;
    cin>>n;
    for(i=1;i<=n;i++)
        for(k=1;k<M;k++)
            for(l=0;l<M;l++)
                dp[i][k][l]=-INF;

    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sl[i]=sl[i-1]+a[i];
    }
    for(i=n;i;i--)
        sr[i]=sr[i+1]+a[i];

    for(i=n/2;i>=0;i--)
    {
        for(k=1;k<M;k++)
            for(l=0;l<k;l++)
            {
                j=n-(i+l)+1;
                if(i>=j)
                    dp[i][k][l]=-INF;
                if(j-i-1<k)
                    dp[i][k][l]=sl[i]-sr[j];
                else
                {
                    t=j-i-1;
                    ti=i+k;
                    //mn1=mn2=mn3=mn4=INF;
                    if(ti<j)
                    {
                        if(t>=k+k)
                            mn1=dp[i+k][k][l];
                        else
                            mn1=sl[i+k]-sr[j];

                        if(t>=k+k+1)
                            mn2=dp[i+k][k+1][l+1];
                        else mn2=mn1;
                    }
                    ti++;
                    if(ti<j)///////////////////////////////
                    {
                        if(t>=k+1+k+1)
                            mn3=dp[i+k+1][k+1][l];
                        else
                            mn3=sl[i+k+1]-sr[j];

                        if(t>=k+1+k+2)
                            mn4=dp[i+k+1][k+2][l+1];
                        else mn4=mn3;
                    }
                    else mn3=mn4=-INF;

                    dp[i][k][l]=max(min(mn1,mn2),min(mn3,mn4));
                }
            }
    }
    //debug(dp[3][2][1]);
    //debug(dp[1][1][0]);
    //debug(dp[1][2][1]);
    //debug(dp[1][1][1]);
    cout<<dp[0][1][0]<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*
dp[3][2][1]

dp[3][2][0]

dp[1][1][0]
dp[1][2][1]
dp[1][1][1]=5


7
0 -2 -1 -1 -3 3 2
*/