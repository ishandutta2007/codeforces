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
#define N 25
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int a[N][N],b[N][N];
int main()
{
    int n,m,x,y,i,j,k,flag,rel=0,tx,ty;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]),b[i][j]=a[i][j];
    for(x=1;x<=m;x++)
        for(y=x;y<=m;y++)
        {
            tx=x,ty=y;
            if(x==y) x=y=0;
            flag=1;
            for(i=1;i<=n;i++)
                for(j=1;j<=m;j++)
                    b[i][j]=a[i][j];
            for(i=1;i<=n;i++)
            {
                flag=1;
                swap(b[i][x],b[i][y]);
                for(j=1;j<=m;j++)
                {
                    //if(j!=x&&j!=y)
                        if(b[i][j]!=j)
                            if(flag==1)
                            {
                                //debug(i);
                                //debug(j);
                                for(k=1;k<=m;k++)
                                    if(b[i][k]==j)
                                        swap(b[i][k],b[i][j]);
                                flag=2;
                            }
                            else if(flag==2)
                            {
                                flag=0;
                                break;
                            }
                }
                if(flag==0) break;
            }

            for(i=1;i<=n;i++)
                for(j=1;j<=m;j++)
                    if(b[i][j]!=j)
                        flag=0;
            if(flag)
            {
                printf("YES\n");
                return 0;
            }
            x=tx,y=ty;
        }
    printf("NO\n");
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/