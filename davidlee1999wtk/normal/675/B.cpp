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
int a[5];
int main()
{
    int n,i,x,mn,mx;
    LL ans=0;
    cin>>n;
    for(i=1;i<=4;i++)
        scanf("%d",&a[i]);
    mn=min(min(a[1]+a[2],a[1]+a[3]),min(a[2]+a[4],a[3]+a[4]));
    mx=max(max(a[1]+a[2],a[1]+a[3]),max(a[2]+a[4],a[3]+a[4]));
    x=mx-mn;
    ans=max(0ll,(LL)(n-x)*n);
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++