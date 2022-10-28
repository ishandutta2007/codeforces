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
#include<functional>
#include<sstream>
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
LL a[N],dp_min[N],dp_max[N];
int main()
{
    int n,i;
    LL val;
    LL ans=0;
    cin>>n;

    for(i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        if(i>=2)
        {
            val=abs(a[i]-a[i-1]);
            dp_max[i]=max(val,val-dp_min[i-1]);
            dp_min[i]=min(val,val-dp_max[i-1]);
            ans=max(ans,dp_max[i]);
        }
    }
    cout<<ans<<endl;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/