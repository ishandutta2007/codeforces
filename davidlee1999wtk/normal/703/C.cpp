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
double x[N],y[N];
double eps=1e-11;
double dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    else if(x<0) return -1;
    else return 1;
}
int main()
{
    int n,i,flag=1;
    double w,v,u,ans=0;
    cin>>n>>w>>v>>u;
    for(i=1;i<=n;i++)
    {
        scanf("%lf%lf",&x[i],&y[i]);
        if(dcmp(y[i]/u-x[i]/v)>0)
            flag=0;
        ans=max(ans,x[i]/v+(w-y[i])/u);
    }
    ans=max(ans,w/u);
    if(flag==1)
        ans=w/u;
    printf("%.12f\n",ans);
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++