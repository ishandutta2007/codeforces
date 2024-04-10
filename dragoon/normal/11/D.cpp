#pragma warning(disable:4786)
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<set>
#include<stdlib.h>
#include<sstream>
#include<functional>
#include<queue>
#include<stack>
using namespace std;

#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define ABS(A) ((A)>0?(A):(-(A)))
#define S(X) ((X)*(X))

typedef pair<int,int> PII;

//int dr[]={-1,0,1,0};
//int dc[]={0,1,0,-1};
//int dr[]={-2,-2,-1,1,2,2,1,-1};
//int dc[]={-1,1,2,2,1,-1,-2,-2};

typedef __int64 LL;
//#define I64d "%I64d"
//typedef long long LL;
//#define I64d "%lld"

char mark[1<<19][20];
LL dp[1<<19][20];
int w[23][23];
int n;

LL DP(int mask, int end,int start)
{
    LL &ret = dp[mask][end];
    int i;

    if(mark[mask][end]) return ret;
    mark[mask][end]=1;

    ret=0;

    if(w[end][start]) ret=1;

    for(i=start+1;i<n;i++)
        if( !(mask & (1<<i)) && w[end][i] )
        {
            ret+=DP(mask|(1<<i),i,start);
        }

    return ret;
}

int main() 
{
    int i,j,k,m,a,b;
    LL cnt;

    scanf("%d%d",&n,&m);

    for(i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        a--;
        b--;
        w[b][a]=w[a][b]=1;
    }

    if(n<=2)
    {
        printf("%d\n",0);
        return 0;
    }

    cnt=0;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            for(k=i+1;k<n;k++) if(j!=k && w[i][j] && w[j][k])
                cnt+=DP((1<<i)|(1<<j)|(1<<k),k,i);

    cnt>>=1;
    printf("%I64d\n",cnt);

    return 0;
}