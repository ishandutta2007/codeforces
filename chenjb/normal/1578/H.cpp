#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
int n,m,r,c;
char s[100][100];
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        scanf("%d%d%d%d",&n,&m,&r,&c);
        for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
        if (s[r][c]=='B'){ puts("0"); continue; }
        int row=0,col=0;
        for(int i=1;i<=n;i++)if (s[i][c]=='B')row=1;
        for(int i=1;i<=m;i++)if (s[r][i]=='B')col=1;
        if (row+col>0){ puts("1"); continue; }
        int flag=0;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if (s[i][j]=='B')flag=1;
        if (flag){ puts("2"); continue; }
        puts("-1");
    }    
    return 0;
}