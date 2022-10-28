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
map<LL,int> mp;
int main()
{
    LL n,k,a,now=0,pw,ans=0;
    LL inf = 100000000ll*100000000ll;
    int i;
    cin>>n>>k;
    mp[0]=1;
    for(i=1;i<=n;i++)
    {
        scanf("%I64d",&a);
        now+=a;
        for(pw=1;pw<=inf;pw*=k)
        {
            //if(pw>=0)
                ans+=mp[now-pw];
            if(k==1||(k==0&&pw==0)||(pw==-1&&k==-1))
                break;
        }
        mp[now]++;
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*
4 0
1 1 -1 1

5 -1
-1 -1 -1 -1 -1

*/