#include<bits/stdc++.h>
using namespace std;
const int nmax=100;
struct data
{
    int nod,val;
};
vector<data>v[nmax+5];
int n,m;
int dp[nmax+5][nmax+5][30];
void slove(int poz1,int poz2,int c)
{
    bool gasit=0,ok=0;
    for(int i=0;i<v[poz1].size();i++)
    {
        if(v[poz1][i].val>=c)
        {
            gasit=1;
            if(dp[poz2][v[poz1][i].nod][v[poz1][i].val]==-1)
                slove(poz2,v[poz1][i].nod,v[poz1][i].val);
            if(dp[poz2][v[poz1][i].nod][v[poz1][i].val]==0)
                ok=1;
        }
    }
    if(gasit==0 or ok==0)
    {
        dp[poz1][poz2][c]=0;
        return;
    }
    dp[poz1][poz2][c]=1;
}
int main()
{
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        char ch;
        cin>>a>>b;
        cin.get();
        ch=cin.get();
        v[a].push_back({b,ch-'a'});
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=0;k<26;k++)
                dp[i][j][k]=-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            slove(i,j,0);
            if(dp[i][j][0]==1)
                cout<<"A";
            else
                cout<<"B";
        }
        cout<<"\n";
    }
    return 0;
}
/**
dp[poz1][poz2][c] = cine castiga daca ...


BABBB
BBBBB
AABBB
AAABA
AAAAB



BABBB
BBBBB
AABBB
AAABA
AAAAB
**/