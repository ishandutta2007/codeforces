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
int main()
{
    LL a,b,c,d,n,x,y,z,k,i;
    cin>>a>>b>>c>>d;
    for(n=1;n<=1000000;n++)
        if(n*(n-1)/2==(a+b+c+d))
            break;
    if(n==1000001)
    {
        printf("Impossible\n");
        return 0;
    }
    for(x=1;x<=1000000;x++)
        if(x*(x-1)/2==a)
            break;
    if(a==0&&d>=a&&b+c==0) x=0;
    if(x==1000001)
    {
        printf("Impossible\n");
        return 0;
    }


    for(y=1;y<=1000000;y++)
        if(y*(y-1)/2==d)
            break;
    if(d==0&&d<a&&b+c==0) y=0;
    if(y==1000001)
    {
        printf("Impossible\n");
        return 0;
    }
    //debug(x);
    //debug(y);
    //debug(n);
    if(x+y!=n)
    {
        printf("Impossible\n");
        return 0;
    }
    z=0;
    while(c>=x&&x)
    {
        z++;
        c-=x;
    }
    k=z+x-c+1;
    if(z>y||(z==y&&c))
    {
        printf("Impossible\n");
        return 0;
    }
    for(i=1;i<=n;i++)
    {
        if(i<=z)
            printf("1");
        else if(i>z&&i<k)
            printf("0");
        else if(i==k)
            printf("1");
        else if(i>k&&i<=z+x+1)
            printf("0");
        else printf("1");
    }
    cout<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/