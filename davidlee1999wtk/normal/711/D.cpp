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
LL ksm(LL a,LL b)
{
    LL c=1,d=a;
    while(b)
    {
        if(b&1)
            c=(c*d)%P;
        d=(d*d)%P;
        b>>=1;
    }
    return c;
}

int n,a[N],vis[N],dep[N];
int main()
{
    int i,now,sz,cnt=0;
    LL ans=1;
    cin>>n;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            cnt++;
            now=i;
            sz=0;
            do
            {
                dep[now]=sz;
                sz++;
                vis[now]=cnt;
                now=a[now];
            }while(!vis[now]);
            if(vis[now]==cnt)
                ans=ans*(ksm(2,dep[now])+P)%P*(ksm(2,sz-dep[now])-2+P)%P;
            else
                ans=ans*ksm(2,sz)%P;
        }
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/