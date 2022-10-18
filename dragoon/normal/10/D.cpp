#include<stdio.h>
#include<utility>
using namespace std;

typedef pair<int,int> PII;

#define MAX(A,B) ((A)>(B)?(A):(B))

int dp[506][506];
int prev[504][504];
int a[503],b[503];
int ans, i, j, k, m, n;
PII p[504][504],s;

int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);

    scanf("%d",&m);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);

    for(i=1;i<=n;i++)
    {
        prev[i][0] = 0;

        for(j=1;j<=m;j++)
            if(a[i]==b[j]) dp[i][j]=1, prev[i][j] = j;
            else prev[i][j] = prev[i][j-1];
    }

    ans = 0;
    for(i=n;i>=1;i--)
        for(j=m;j>=1;j--)
            if(a[i]==b[j])
            { 
                for(k=0;k<i;k++) if(a[k]<a[i])
                {
                    if(prev[k][j-1]==0) continue;

                    if( dp[i][j]+1 > dp[k][ prev[k][j-1] ])
                    {
                        dp[k][ prev[k][j-1] ] = dp[i][j]+1;
                        p[k][ prev[k][j-1] ] = PII(i,j);
                    }
                }
    
                if(ans < dp[i][j])
                {
                    ans = dp[i][j];
                    s = PII(i,j);
                }

            }

    printf("%d\n",ans);

    
    while(dp[s.first][s.second])
    {
        if(ans!=dp[s.first][s.second]) printf(" ");
        printf("%d",a[s.first]);
        if(dp[s.first][s.second]==1) break;
        s = p[s.first][s.second];
    }

    printf("\n");

    return 0;
}