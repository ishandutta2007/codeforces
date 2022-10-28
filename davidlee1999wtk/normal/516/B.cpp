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
#define INF 100000000
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int n,m,dx[5]={-1,1,0,0},dy[5]={0,0,-1,1},rel;
char mp[2005][2005];
char p[5]={'v','^','>','<'};
queue<pii> q;
inline void check(int x,int y)
{
    int f=0,k;
    for(k=0;k<4;k++)
        if(mp[x+dx[k]][y+dy[k]]=='.')
        {
            //mp[x][y]=mp[x+dx[k]][y+dy[k]]='*';
            //nx=x+dx[k],ny=y+dy[k];
            //sum-=2;
            f++;
            //break;
        }
    rel=f;
}
int main()
{
    int i,j,k,f,sum=0,x,y,tx,ty,nx,ny;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        scanf("%s",mp[i]+1);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(mp[i][j]=='.')
            {
                sum++;
                f=0;
                for(k=0;k<4;k++)
                    if(mp[i+dx[k]][j+dy[k]]=='.')
                        f++;
                if(f==1)
                    q.push(make_pair(i,j));
                else if(f==0)
                {
                    printf("Not unique\n");
                    return 0;
                }
            }
    while(!q.empty())
    {
        x=q.front().fi;
        y=q.front().se;
        q.pop();
        if(mp[x][y]!='.')
            continue;
        f=0;
        for(k=0;k<4;k++)
            if(mp[x+dx[k]][y+dy[k]]=='.')
            {
                mp[x][y]=p[k];
                mp[x+dx[k]][y+dy[k]]=p[k^1];
                nx=x+dx[k],ny=y+dy[k];
                sum-=2;
                f++;
                break;
            }
        if(!f)
        {
            printf("Not unique\n");
            return 0;
        }
        for(k=0;k<4;k++)
        {
            tx=x+dx[k];
            ty=y+dy[k];
            if(mp[tx][ty]=='.')
            {
                check(tx,ty);
                if(rel==1)
                    q.push(make_pair(tx,ty));
                else if(rel==0)
                {
                    printf("Not unique\n");
                    return 0;
                }
            }
        }
        x=nx,y=ny;
        for(k=0;k<4;k++)
        {
            tx=x+dx[k];
            ty=y+dy[k];
            if(mp[tx][ty]=='.')
            {
                check(tx,ty);
                if(rel==1)
                    q.push(make_pair(tx,ty));
                else if(rel==0)
                {
                    printf("Not unique\n");
                    return 0;
                }
            }
        }
    }
    if(sum!=0)
    {
        printf("Not unique\n");
        return 0;
    }
    else
        for(i=1;i<=n;i++)
            printf("%s\n",mp[i]+1);
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);