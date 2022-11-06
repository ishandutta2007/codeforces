#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
char num[1010][1010];
int d[1010][1010],v[1010][1010];
int n,m;
queue<pair<int,int> > q;
int go[5][2];
void bfs(int x)
{
    memset(v,0,sizeof(v));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(num[i][j]==x)
            {
                d[i][j]=0;
                v[i][j]=1;
                q.push(make_pair(i,j));
            }
            else
                d[i][j]=inf;
    while(!q.empty())
    {
        int i=q.front().first,j=q.front().second;
    //  if(x==51)
        //  cout<<i<<' '<<j<<endl;
        q.pop();
        for(int k=1;k<=4;k++)
            if(i+go[k][0]>0&&i+go[k][0]<=n&&j+go[k][1]>0&&j+go[k][1]<=m&&v[i+go[k][0]][j+go[k][1]]==0&&num[i][j]!='#')
            {
                v[i+go[k][0]][j+go[k][1]]=1;
                d[i+go[k][0]][j+go[k][1]]=d[i][j]+1;
                q.push(make_pair(i+go[k][0],j+go[k][1]));
            }
    }
}
int nowd[5][1010][1010];
int main()
{
    go[1][1]=go[2][0]=1;
    go[3][1]=go[4][0]=-1;
    go[1][0]=go[2][1]=go[3][0]=go[4][1]=0;
    cin>>n>>m;
    int n1,d12=inf,d23=inf,d13=inf;
    for(n1=1;n1<=n;n1++)
        scanf("%s",num[n1]+1);
    for(int i=1;i<=3;i++)
    {
        bfs(i+48);
        for(int j=1;j<=n;j++)
            for(int k=1;k<=m;k++)
                nowd[i][j][k]=d[j][k];
    }
    int ans=inf;
    for(int j=1;j<=n;j++)
        for(int k=1;k<=m;k++)
        {
            if(num[j][k]=='1')
            {
                d12=min(d12,nowd[2][j][k]);
                d13=min(d13,nowd[3][j][k]);
            }
            if(num[j][k]=='2')
            {
                d12=min(d12,nowd[1][j][k]);
                d23=min(d23,nowd[3][j][k]);
            }   
            if(num[j][k]=='3')
            {
                d13=min(d13,nowd[1][j][k]);
                d23=min(d23,nowd[2][j][k]);
            }
            if(num[j][k]=='.'&&nowd[1][j][k]<inf&&nowd[2][j][k]<inf&&nowd[3][j][k]<inf)
                ans=min(ans,nowd[1][j][k]+nowd[2][j][k]+nowd[3][j][k]-2);       
        }
    //cout<<nowd[3][1][3]<<endl;
    ans=min(min(d12+d13-2,d12+d23-2),min(ans,d13+d23-2));
    if(ans>=inf/2)
        printf("-1");
    else
        cout<<ans;
}