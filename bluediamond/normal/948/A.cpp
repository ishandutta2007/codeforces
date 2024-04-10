#include <bits/stdc++.h>

using namespace std;

const int nmax=500;
int n,m;
int v[nmax+5][nmax+5];
char s[nmax+5];
bool valid(int r,int c)
{
    if(1<=r && 1<=c && r<=n && c<=m)
        return 1;
    return 0;
}
int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};
int main()
{
    scanf("%d%d\n",&n,&m);
    for(int i=1;i<=n;i++)
    {
        gets(s);
        for(int j=1;j<=m;j++)
        {
            if(s[j-1]=='.')
                v[i][j]=0;
            else
                if(s[j-1]=='S')
                    v[i][j]=1;
                else
                    v[i][j]=2;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(v[i][j]==1)
            {
                for(int k=0;k<4;k++)
                {
                    int rn=i+dr[k];
                    int cn=j+dc[k];
                    if(valid(rn,cn) && v[rn][cn]==2)
                    {
                        cout<<"No";
                        return 0;
                    }
                }
            }
        }
    cout<<"Yes\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(v[i][j]==0)
                cout<<"D";
            else
                if(v[i][j]==1)
                    cout<<"S";
                else
                    cout<<"W";
        }
        cout<<"\n";
    }
    return 0;
}
/**
0 = nimic
S = 1 =oaie
2 = lup

**/