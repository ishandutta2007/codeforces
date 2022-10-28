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
#define N 400005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int n;
int dp[N],b[N*2],c[N],z;
map<int,int> mp;
pii p[N];
void add(int w,int x)
{
    for(;x<=z;x+=x&-x)
        c[x]=max(c[x],w);
}

int get(int x)
{
    int ans=0;
    for(;x;x-=x&-x)
        ans=max(ans,c[x]);
    return ans;
}
int main()
{
    int i,ans=1,now;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&p[i].fi,&p[i].se);
        b[i]=p[i].fi+p[i].se;
        b[i+n]=p[i].fi-p[i].se;
    }
    sort(b+1,b+1+n*2);
    z=unique(b+1,b+1+n*2)-(b+1);
    for(i=1;i<=z;i++)
        mp[b[i]]=i;
    sort(p+1,p+1+n);
    for(i=1;i<=n;i++)
    {
        now=get(mp[p[i].fi-p[i].se]);
        dp[i]=now+1;
        add(dp[i],mp[p[i].fi+p[i].se]);
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")