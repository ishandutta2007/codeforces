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
#define N 200005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
LL c[N],v[N],loc[N];
int main()
{
    LL n,k,s,T,i,flag,lim;
    LL l,r,mid,t;
    cin>>n>>k>>s>>T;
    for(i=1;i<=n;i++)
        scanf("%I64d%I64d",&c[i],&v[i]);
    for(i=1;i<=k;i++)
        scanf("%I64d",&loc[i]);
    sort(loc+1,loc+1+k);
    l=0,r=INF+1;
    loc[0]=0,loc[k+1]=s;
    while(l<=r)
    {
        mid=(l+r)>>1;
        flag=1;
        t=0;
        for(i=1;i<=k+1;i++)
        {
            if(mid<loc[i]-loc[i-1])
            {
                flag=0;
                break;
            }
            if(mid>=(loc[i]-loc[i-1])*2)
                t+=(loc[i]-loc[i-1]);
            else t+=(loc[i]-loc[i-1])*3-mid;
        }
        if(flag==1&&t<=T)
        {
            lim=mid;
            r=mid-1;

        }
        else l=mid+1;
    }
    //debug(lim);
    int ans=INF+1;
    for(i=1;i<=n;i++)
        if(v[i]>=lim&&c[i]<=ans)
            ans=c[i];
    if(ans==INF+1)
        ans=-1;
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/