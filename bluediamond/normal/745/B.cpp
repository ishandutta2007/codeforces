#include <bits/stdc++.h>

using namespace std;

int n,m;
const int nmax=500;
int v[nmax+5][nmax+5],viz[nmax+5][nmax+5];
int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};
int ST=1e9,DR=-1e9,SUS=1e9,JOS=-1e9;
void dfs(int r,int c)
{
    SUS=min(SUS,r);
    JOS=max(JOS,r);
    ST=min(ST,c);
    DR=max(DR,c);
    viz[r][c]=1;
    for(int i=0;i<4;i++)
    {
        int rn=r+dr[i];
        int cn=c+dc[i];
        if(v[rn][cn]==1 and viz[rn][cn]==0)
            dfs(rn,cn);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin.get();
        for(int j=1;j<=m;j++)
        {
            char ch;
            ch=cin.get();
            if(ch=='X')
                v[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(v[i][j]==1 and viz[i][j]==0)
            {
                dfs(i,j);
            }
    for(int r=SUS;r<=JOS;r++)
        for(int c=ST;c<=DR;c++)
            if(v[r][c]==0)
            {
                cout<<"NO";
                return 0;
            }
    cout<<"YES";
    return 0;
}
/**


**/