#include<bits/stdc++.h>
using namespace std;
#define pa pair<int,int>
const int N=1e3+5;
char Map[N][N];
int spe[10],cnt[10],n,m;
struct node
{
    int x,y,round;
};
int xmov[]={1,0,-1,0};
int ymov[]={0,1,0,-1};
queue<node>Q[10];
int main()
{
    int num;
    scanf("%d%d%d",&n,&m,&num);
    for(int i=1;i<=num;i++)
        scanf("%d",&spe[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",Map[i]+1);
        for(int j=1;j<=m;j++)
        {
            if('1'<=Map[i][j]&&Map[i][j]<='9')
                Q[Map[i][j]-'0'].push({i,j,0}),cnt[Map[i][j]-'0']++;
        }
    }
    int End=1;
    for(int round=1;End;round++)
    {
        End=0;
        for(int i=1;i<=num;i++)
        {
            while(!Q[i].empty()&&Q[i].front().round<round*spe[i])
            {
                node u=Q[i].front();
                Q[i].pop();
                for(int j=0;j<4;j++)
                {
                    int nx=u.x+xmov[j];
                    int ny=u.y+ymov[j];
                    if(Map[nx][ny]=='.')
                    {
                        Q[i].push({nx,ny,u.round+1}),Map[nx][ny]='#',cnt[i]++;
                        /*for(int i=1;i<=n;i++)
                            for(int j=1;j<=m;j++)
                                printf("%c%c",Map[i][j],j==m?'\n':' ');*/
                    }
                }
            }
            End|=Q[i].size();
        }
    }

    for(int i=1;i<=num;i++)
        printf("%d%c",cnt[i],i==num?'\n':' ');
    return 0;
}