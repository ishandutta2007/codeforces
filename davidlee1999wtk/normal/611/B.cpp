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
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
unsigned long long x;
int main()
{
    LL a,b,k;
    int i,j,ans=0;
    cin>>a>>b;
    for(i=2;i<=61;i++)
    {
        k=(1ll<<i)-1;
        for(j=0;j<i-1;j++)
            if((k^(1ll<<j))>=a&&(k^(1ll<<j))<=b)
            {
                //debug(i);
                //debug(j);
                //debug((k^(1<<j)));
                ans++;
            }
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))