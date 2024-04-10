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
#define N 505
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
LL a[N][N];
int main()
{
    int n,i,j,x,y;
    LL s=0,sum=0;
    cin>>n;
    if(n==1)
        printf("1\n");
    else
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                scanf("%I64d",&a[i][j]);
                if(a[i][j]==0)
                    x=i,y=j;
            }
        for(i=1;i<=n;i++)
            if(x!=i)
            {
                for(j=1;j<=n;j++)
                    sum+=a[i][j];
                break;
            }
        i=x;
        for(j=1;j<=n;j++)
            s+=a[i][j];
        a[x][y]=sum-s;
        //debug(a[x][y]);
        if(a[x][y]<=0)
        {
            printf("-1\n");
            return 0;
        }
        for(i=1;i<=n;i++)
        {
            s=0;
            for(j=1;j<=n;j++)
                s+=a[i][j];
            if(s!=sum)
            {
                printf("-1\n");
                return 0;
            }
        }
        for(j=1;j<=n;j++)
        {
            s=0;
            for(i=1;i<=n;i++)
                s+=a[i][j];
            if(s!=sum)
            {
                printf("-1\n");
                return 0;
            }
        }
        s=0;
        for(i=1;i<=n;i++)
            s+=a[i][i];
        if(s!=sum)
        {
            printf("-1\n");
            return 0;
        }
        s=0;
        for(i=1;i<=n;i++)
            s+=a[i][n-i+1];
        if(s!=sum)
        {
            printf("-1\n");
            return 0;
        }
        printf("%I64d",a[x][y]);
    }
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/