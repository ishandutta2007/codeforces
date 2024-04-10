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
#define N 200005
#define P 1000000007
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
map<int,int> mpx,mpy;
map<pii,int> mp;
pii p[N];
int main()
{
    int n,i;
    LL ans=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&p[i].fi,&p[i].se);
        ans+=mpx[p[i].fi];
        mpx[p[i].fi]++;
        ans+=mpy[p[i].se];
        mpy[p[i].se]++;
        ans-=mp[p[i]];
        mp[p[i]]++;
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))