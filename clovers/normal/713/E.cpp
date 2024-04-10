#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,a[N],tmp[N];
int dp[N],MAXX;

void init()
{
    scanf("%d",&m); scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]); sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) tmp[i]=a[i]; int tot=0;
    int mx=0,id=0; tmp[n+1]=m+tmp[1];
    for(int i=1;i<=n;i++) if(tmp[i+1]-tmp[i]-1>mx) mx=tmp[i+1]-tmp[i]-1,id=i;
    for(int i=id+1;i<=n;i++) a[++tot]=tmp[i];
    for(int i=1;i<=id;i++) a[++tot]=tmp[i];
    for(int i=n;i>=1;i--) 
    {
        a[i]-=a[1];
        if(a[i]<0) a[i]+=m;
    }
    MAXX=mx;
}

bool check(int x)
{
    int fin;
    memset(dp,0,sizeof(dp));
    for(int s=1;s<=2;s++)
    {
        if(s==1) fin=m-x-1,dp[1]=0;
        else fin=min(m-1,m-1+a[2]-x),dp[2]=max(a[2],x);
        for(int i=s+1;i<=n;i++)
        {
            dp[i]=dp[i-1];
            if(dp[i-1]>=a[i]-1) dp[i]=max(a[i]+x,dp[i]);
            if(dp[i-1]>=a[i]-x-1) dp[i]=max(dp[i],a[i]);
            if(i!=s+1&&a[i]-x-1<=dp[i-2]) dp[i]=max(dp[i],a[i-1]+x);
        }
        //cout<<x<<" "<<s<<" "<<dp[n]<<" "<<fin<<endl;
        if(dp[n]>=fin) return 1;
    }
    return 0;   
}

int main()
{
    init();
    if(n==1)
    {
        printf("%d\n",m-1);
        return 0;
    }
    int l=MAXX/2,r=m,mid,best=-1;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid)) r=mid-1,best=mid;
        else l=mid+1;
    }
    printf("%d\n",best);
    return 0;
}