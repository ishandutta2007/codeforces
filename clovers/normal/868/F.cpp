//calcO(1)dp
#include<bits/stdc++.h>
using namespace std;
const int N=120000;
int n,k,a[N],t[N],from[N],m;
#define int long long

void init()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
}

int nowl=1,nowr=0,sum=0;
int w(int l,int r)
{
    while(nowr<r) sum+=t[a[++nowr]]++;
    while(nowr>r) sum-=--t[a[nowr--]];
    while(nowl<l) sum-=--t[a[nowl++]];
    while(nowl>l) sum+=t[a[--nowl]]++;
    return sum;
}

int dp[N],pre[N];
void solve(int l,int r,int kl,int kr)
{
    if(l>r) return;
    int mid=(l+r)>>1;
    for(int i=min(kr,mid-1);i>=kl;i--)//i-1 -> mid
    {
        int tmp=w(i+1,mid);
        if(dp[mid]>=pre[i]+tmp) dp[mid]=pre[i]+tmp, from[mid]=i;
    }
    solve(l,mid-1,kl,from[mid]); solve(mid+1,r,from[mid],kr);
}

signed main()
{
    init();
    memset(pre,0x3f,sizeof(pre)); pre[0]=0;
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=k;i++) 
    {
        solve(1,n,0,n-1);
        //for(int i=1;i<=n;i++) cout<<dp[i]<<" "; cout<<endl;
        for(int i=1;i<=n;i++) pre[i]=dp[i];
    }
    printf("%lld\n",dp[n]);
    return 0;
}