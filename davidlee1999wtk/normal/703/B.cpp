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
#define N 100005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
LL c[N],sum,sum2,ans;
bool vis[N];
int main()
{
    int n,k,x,i;
    cin>>n>>k;
    for(i=1;i<=n;i++)
        scanf("%I64d",&c[i]),sum+=c[i];
    for(i=1;i<=k;i++)
    {
        scanf("%d",&x);
        vis[x]=1;
        sum2+=c[x];
    }
    c[0]=c[n];
    c[n+1]=c[1];
    vis[0]=vis[n];
    vis[n+1]=vis[1];
    for(i=1;i<=n;i++)
    {
        if(vis[i])
            ans+=c[i]*(sum-c[i]);
        else
            ans+=c[i]*(sum2+c[i-1]*(1-vis[i-1])+c[i+1]*(1-vis[i+1]));
    }
    cout<<ans/2<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++