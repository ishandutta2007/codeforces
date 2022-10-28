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
#define INF 100000000
#define fi first
#define se second
#define MN 2001005
#define debug(x) cout<<#x<<"="<<x<<endl
using namespace std;
typedef long long LL;
int sa[2][MN*2],rk[2][MN*2],fir[205],he[MN],st[21][MN],v[MN],len[205];
int n,k,p=1;
char a[MN];
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
        while(a[i+k]==a[j+k]) k++;
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
inline int rmq(int l,int r)
{
    if(l>r) swap(l,r);
    l++;
    int m=(int)(log(r-l+1.5)/log(2.0));
    return  min(st[m][l],st[m][r-(1<<m)+1]);
}
bool vis[MN];
int main()
{
    int i,K,j,m,nl,tl,tn,l,r;
    cin>>K>>m;
    scanf("%s",a+1);
    n=strlen(a+1);
    tn=n;
    for(i=1;i<=n;i++) v[a[i]]++;
    for(i=1;i<=256;i++) v[i]+=v[i-1];
    for(i=1;i<=n;i++)
        sa[p][v[a[i]]--]=i;
    for(i=1;i<=n;i++)
        rk[p][sa[p][i]]=rk[p][sa[p][i-1]]+(a[sa[p][i]]!=a[sa[p][i-1]]);
    k=1;
    //cout<<n<<endl;
    while(k<n)
    {
        calc(sa[p],sa[p^1],rk[p],rk[p^1]);
        p^=1; k<<=1;
    }
    get_H();
    get_ST();
    //for(i=1;i<=n;i++)
        //debug(he[i]);
    LL ans=1;
    for(i=1;i<=m;i++)
    {
        scanf("%d",&nl);
        vis[nl]=1;
        if(i!=1)
        {
            l=nl-tl+1;
            //r=tn+1+l;
            r=1;
          // debug(l);
            //debug(r);
            if(rmq(rk[p][l],rk[p][r])<tn-l+1)
            {
                //debug(rk[p][l]);
                //debug(rk[p][r]);
                //debug(rmq(rk[p][l],rk[p][r]));
                printf("0\n");
                return 0;
            }
        }
        tl=nl;
    }
    l=-INF;
    for(i=1;i<=K;i++)
    {
        if(vis[i])
        {
            l=i;
        }
        else
        {
            if(i-l>=tn)
                ans=ans*26%1000000007;
        }
    }
    cout<<ans<<endl;
    return 0;
}