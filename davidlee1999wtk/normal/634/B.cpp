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
int main()
{
    LL s,x;
    int i;
    LL ans=1;
    cin>>s>>x;
    if(s<x)
    {
        cout<<0<<endl;
        return 0;
    }
    if((s-x)%2==1)
    {
        cout<<0<<endl;
        return 0;
    }
    if(((s-x)>>1)&x)
    {
        cout<<0<<endl;
        return 0;
    }
    for(i=0;i<=50;i++)
        if((1ll<<i)&(x))
            ans<<=1;
    if(s==x) ans-=2;
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))