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
#define N 100005
#define P 1000000007
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
char s[N];
int sum[N];
int main()
{
    int i,n,k,m=0,l=1,r,mid,ans,mx,L,R;
    cin>>n>>k;
    r=n;
    scanf("%s",s+1);
    for(i=1;i<=n;i++)
        if(s[i]=='0')
        {
            m++;
            sum[i]=sum[i-1]+1;
        }
        else sum[i]=sum[i-1];
    while(l<=r)
    {
        mid=(l+r)>>1;
        mx=1;
        for(i=1;i<=n;i++)
            if(s[i]=='0')
            {
                L=max(1,i-mid);
                R=min(n,i+mid);
                mx=max(mx,sum[R]-sum[L-1]);
            }
        //mx=max(mx,now);
        if(mx>=k+1)
            r=mid-1,ans=mid;
        else l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))