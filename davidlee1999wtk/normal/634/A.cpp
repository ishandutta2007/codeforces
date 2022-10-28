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
#define N 400005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int a[N],b[N];
int main()
{
    int n,i,j,loc,flag;
    cin>>n;
    flag=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i-flag]);
        if(flag==0&&a[i]==0)
            flag=1;
    }
    flag=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&b[i-flag]);
        if(flag==0&&b[i]==0)
            flag=1;
    }
    flag=1;
    n--;
    for(i=1;i<=n;i++)
    {
        //debug(a[i]);
        //debug(b[i]);
        b[i+n]=b[i];
    }
    for(i=1;i<=n;i++)
        if(b[i]==a[1])
            loc=i;
    //debug(loc);
    for(i=1,j=loc;i<=n;i++,j++)
    {
        //debug(a[i]);
        //debug(b[j]);
        if(a[i]!=b[j])
            flag=0;
    }
    if(flag==1)
        printf("YES\n");
    else printf("NO\n");
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))