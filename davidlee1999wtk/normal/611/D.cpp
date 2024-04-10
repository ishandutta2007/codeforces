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
#define N 5005
#define MN 5005
#define P 1000000007
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int dp[N][N],a[N];
char s[N];
int sa[2][MN*2],rk[2][MN*2],he[MN],st[21][MN],v[MN];
int n,k,p=1;
void calc(int *sa,int *SA,int *rk,int *RK)
{
    int i;
    for(i=1;i<=n;i++) v[rk[sa[i]]]=i;

    for(i=n;i;i--)
        if(sa[i]>k)
            SA[v[rk[sa[i]-k]]--]=sa[i]-k;
    for(i=n-k+1;i<=n;i++)
        SA[v[rk[i]]--]=i;
    for(i=1;i<=n;i++)
        RK[SA[i]]=RK[SA[i-1]]+(rk[SA[i]]!=rk[SA[i-1]]||rk[SA[i]+k]!=rk[SA[i-1]+k]);
}
void get_H()
{
    int i,j,k=0;
    for(i=1;i<=n;i++)
    {
        if(k) k--;
        j=sa[p][rk[p][i]-1];
        //debug(i);
        //debug(j);
        while(a[i+k]==a[j+k]) k++;
        //debug(k);
        he[rk[p][i]]=k;
    }
}
void get_ST()
{
    int i,j;
    int m;
    m=(int)(log(n+0.5)/log(2.0));
    for(i=1;i<=n;i++) st[0][i]=he[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n-(1<<i)+1;j++)
            st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
int lg[N];
inline int rmq(int l,int r)
{
    if(l>=r) swap(l,r);
    l+=1;
    int m=lg[r-l+1];
    return  min(st[m][l],st[m][r-(1<<m)+1]);
}

inline void upd(int &x,int y)
{
    x+=y;
    if(x>=P) x-=P;
}

bool op[N][N];
int main()
{
    int i,j,len,t;
    cin>>n;
    //if(n>20) while(1);
    lg[1]=0,k=2;
    for(i=2;i<=n;i++)
    {
        if(i==k)
            lg[i]=lg[i-1]+1,k<<=1;
        else lg[i]=lg[i-1];
    }
    //debug(lg[5]);
    scanf("%s",s+1);
    a[0]=-1;
    for(i=1;i<=n;i++)
        a[i]=s[i]-48;
    a[n+1]=-2;
    for(i=1;i<=n;i++) v[a[i]]++;
    for(i=0;i<=256;i++) v[i]+=v[i-1];
    for(i=1;i<=n;i++)
        sa[p][v[a[i]]--]=i;
    for(i=1;i<=n;i++)
        rk[p][sa[p][i]]=rk[p][sa[p][i-1]]+(a[sa[p][i]]!=a[sa[p][i-1]]);
    k=1;
    while(k<n)
    {
        calc(sa[p],sa[p^1],rk[p],rk[p^1]);
        p^=1; k<<=1;
    }
    get_H();
    get_ST();
    /*
    for(i=1;i<=n;i++)
        debug(sa[p][i]);
    for(i=1;i<=n;i++)
        debug(rk[p][i]);
    for(i=1;i<n;i++)
        debug(he[i]);
    */
    for(i=1;i<=n;i++)
        for(j=i;j<=n;j++)
        {
            len=j-i+1;
            if(j+len<=n)
            {
                t=rmq(rk[p][i],rk[p][j+1]);

                if(t>=len)
                    op[j][i]=0;
                else if(rk[p][i]>rk[p][j+1])
                    op[j][i]=0;
                else op[j][i]=1;
                /*
                if(i==1&&j==2)
                {
                    debug(i);
                    debug(j);
                    debug(t);
                    debug(op[j][i]);
                }*/
            }
        }
    dp[0][0]=1;
    for(i=1;i<=n;i++)
        for(j=0;j<i;j++)
        {
            upd(dp[i][j],dp[i-1][j]);
            /*
            if(dp[i][j]!=0)
            {
                debug(i);
                debug(j);
                debug(dp[i][j]);
            }*/
            if(a[j+1]!=0)
            {
                if(op[i][j+1]==1&&i+i-j<=n)
                    upd(dp[i+i-j][i],dp[i][j]);
                else if(i+i-j+1<=n)
                    upd(dp[i+i-j+1][i],dp[i][j]);
            }
        }
    int ans=0;
    for(j=0;j<n;j++)
        if(a[j+1]!=0)
            upd(ans,dp[n][j]);
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))
/*
9
111333111

4
1113
*/