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
#define INF 1000000000
#define N 200005
#define P 1000000007
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
double dp[55][N],F[N],S[N],T[N],G[N];
double *f1,*f2;
int n,k,stk[N],h,t;

double Xie(int j,int k)
{
    return ((f1[j]-F[j]+S[j]*G[j])-(f1[k]-F[k]+S[k]*G[k]))/(S[j]-S[k]);
}

double Get(int j,int i)
{
    return (f1[j]+F[i]-F[j]-S[j]*(G[i]-G[j]));
}

int main()
{
    int i,j;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        scanf("%lf",&T[i]);
        S[i]=S[i-1]+T[i];
        G[i]=G[i-1]+1.0/T[i];
        F[i]=F[i-1]+S[i]/T[i];
        //debug(S[i]);
        //debug(F[i]);
    }
    for(i=1;i<=n;i++)
        dp[1][i]=F[i];
    for(j=2;j<=k;j++)
    {
        f1=dp[j-1];
        f2=dp[j];
        h=1,t=0;
        for(i=j;i<=n;i++)
        {
            //debug(Xie(stk[t],i-1));
            while(h<t&&Xie(stk[t-1],stk[t])>=Xie(stk[t],i-1))
                t--;
            stk[++t]=i-1;
            while(h<t&&Xie(stk[h],stk[h+1])<G[i])
                h++;
            //debug(i);
            //debug(h);
            f2[i]=Get(stk[h],i);
            //debug(f2[i]);
        }
    }
    printf("%.9f\n",dp[k][n]);
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")  //compiler vc++
//#define O2 __attribute__((optimize("-O2")))