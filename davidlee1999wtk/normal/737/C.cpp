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
int vis[N],a[N],s[N];
int main()
{
    int n,rt,ans=0,cnt=0,i,sum=0,rel;
    cin>>n>>rt;
    rel=n;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        vis[a[i]]++;
        if(i!=rt&&a[i]==0)
            ans++,cnt++;
        if(i==rt&&a[i]!=0)
        {
            vis[a[i]]--;
            vis[0]++;
            ans++;
        }
    }
    vis[0]=1;
    for(i=n-1;i;i--)
        s[i]=s[i+1]+vis[i];
    if(n==1)
    {
        printf("%d\n",ans);
        return 0;
    }
    for(i=1;i<n;i++)
    {
        if(!vis[i])
            sum++;
        //debug(s[i+1]);
        //debug(sum);
        //debug(ans+((cnt>sum)?0:(sum-cnt))+s[i+1]);
        rel=min(rel,ans+((cnt+s[i+1]>sum)?0:(sum-cnt-s[i+1]))+s[i+1]);
    }
    cout<<rel<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/