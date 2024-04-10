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
char s[15];
pii zs[15],zx[15];
int main()
{
    int n=8,m=8,i,j,m1=INF,m2=INF;
    for(i=1;i<=n;i++)
    {
        scanf("%s",s+1);
        for(j=1;j<=m;j++)
            if(s[j]=='W')
            {
                if(zs[j].fi==0)
                    zs[j].fi=i,zs[j].se=0;
                zx[j].fi=i,zx[j].se=0;
            }
            else if(s[j]=='B')
            {
                if(zs[j].fi==0)
                    zs[j].fi=i,zs[j].se=1;
                zx[j].fi=i,zx[j].se=1;
            }
    }
    for(j=1;j<=8;j++)
    {
        if(zs[j].fi!=0&&zs[j].se==0)
            m1=min(m1,zs[j].fi-1);
        if(zx[j].fi!=0&&zx[j].se==1)
            m2=min(m2,8-zx[j].fi);
    }
    //debug(m1);
    //debug(m2);
    if(m1<=m2)
        printf("A\n");
    else printf("B\n");
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))