#include <cstdio>
using namespace std;
const int nmax=2000;
int n,m,k;
int v[nmax+5][nmax+5];
int row[nmax+5][nmax+5];
int col[nmax+5][nmax+5];
char ch;
int ans;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("\n");
        for(int j=1;j<=m;j++)
        {
            scanf("%c",&ch);
            if(ch=='*')
                v[i][j]=1;
        }
    }
    if(k==1)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                ans+=1-v[i][j];
        printf("%d",ans);
        return 0;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            row[i][j]=row[i-1][j]+v[i][j];
    for(int j=1;j<=m;j++)
        for(int i=1;i<=n;i++)
            col[i][j]=col[i][j-1]+v[i][j];
    for(int i=0;i+k<=n;i++)
        for(int j=1;j<=m;j++)
            if(row[i][j]==row[i+k][j])
                ans++;
    for(int j=0;j+k<=m;j++)
        for(int i=1;i<=n;i++)
            if(col[i][j]==col[i][j+k])
                ans++;
    printf("%d",ans);
    return 0;
}
/**

**/