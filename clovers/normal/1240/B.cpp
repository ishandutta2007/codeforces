#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int N=500005;
const int inf=(int)1e9+1;
const ll INF=(ll)5e18;

int n,a[N];
void init()
{
    
}

int dp[N],first[N],lst[N],val[N],t[N],pre[N];
void solve()
{
    int sum=0,ans=0;
    scanf("%d",&n); 
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        if(!t[a[i]]) sum++;
        t[a[i]]=1;
        if(!first[a[i]]) first[a[i]]=i;
        lst[a[i]]=i;
    }
    int now=0;
    for(int i=n;i>=0;i--)
    {
        if(t[i]) pre[now]=i,now=i;
    }
    pre[1]=0;
    for(int i=1;i<=n;i++)
    {
        if(!t[i]) continue;
        dp[i]=1;
        if(first[i]>lst[pre[i]]) dp[i]=max(dp[i],dp[pre[i]]+1);
        ans=max(ans,dp[i]);
        //cout<<i<<" "<<dp[i]<<endl;
    }
    for(int i=1;i<=n;i++) first[i]=0,lst[i]=0,dp[i]=0,t[i]=0;
    printf("%d\n",sum-ans);
}

int main()
{
    int TTT=1; scanf("%d",&TTT);
    while(TTT--){init(); solve();}
    return 0;
}