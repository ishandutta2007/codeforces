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
#define N 2000005
#define P 1000000007
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int dp[N],fmp[N];
pii h[N];
char s[N];
int main()
{
    int n,k,m,i,x,y;
    LL sum;
    cin>>n>>k;
    for(i=1;i<=k;i++)
        h[i].fi=0,h[i].se=i;
    scanf("%s",s+1);
    m=strlen(s+1);
    sum=1;
    for(i=1;i<=m;i++)
    {
        dp[i]=sum;
        s[i]-=96;
        sum=(sum+dp[i]-dp[h[s[i]].fi]+P)%P;
        h[s[i]].fi=i;
    }
    sort(h+1,h+1+k);
    for(i=1;i<=k;i++)
        fmp[i]=h[i].se;
    for(i=1;i<=n;i++)
    {
        x=h[(i-1)%k+1].se;
        y=(i-1)%k+1;
        //debug(dp[h[x].fi]);
        //debug(x);
        //debug(fmp[x]);
        dp[i+m]=sum;
        sum=((LL)sum+dp[i+m]-dp[h[y].fi]+P)%P;

        h[y].fi=i+m;
    }
    cout<<sum<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))