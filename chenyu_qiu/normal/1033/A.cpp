#include<cstring>
#include<math.h>
#include<iostream>
#include <climits>
#include <queue>

using namespace std;
typedef long long LL;

const int N = 1010;
bool g[N][N];
int n;
bool bfs(int x1,int y1,int x2,int y2)
{
    queue<pair<int,int>> q;
    q.push({x1,y1});
    int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    g[x1][y1]=true;
    while(q.size())
    {
        /*
        for (int i = n; i >= 1; i -- )
        {
            for (int j = 1; j <= n; j ++ )
            {
                cout<<g[j][i];
            }
            puts("");
        }
        puts("");
        */
        int x=q.front().first,y=q.front().second;
        //cout<<x<<"  "<<y<<endl;
        q.pop();
        for (int i = 0; i < 8; i ++ )
        {
            int tx=x+dx[i],ty=y+dy[i];
            //cout<<tx<<" !!  "<<ty<<endl;
            if(tx==x2&&ty==y2)return true;
            if(tx<1||tx>n||ty<1||ty>n)continue;
            if(g[tx][ty])continue;
            g[tx][ty]=true;
            q.push({tx,ty});
        }
    }
    return false;

}
int main()
{
	int x1,y1,x2,y2,x3,y3;
	scanf("%d%d%d%d%d%d%d",&n,&x1,&y1,&x2,&y2,&x3,&y3);
	g[x1][y1]=true;
	int l=x1,r=x1,u=y1,d=y1;
	while(u<=n||d>=1||l>=1||r<=n)
    {
        if(u<=n)g[x1][u]=true;
        if(d>=1)g[x1][d]=true;
        if(l>=1)g[l][y1]=true;
        if(r<=n)g[r][y1]=true;
        
        if(u<=n&&l>=1)g[l][u]=true;
        if(u<=n&&r<=n)g[r][u]=true;
        if(d>=1&&l>=1)g[l][d]=true;
        if(d>=1&&r<=n)g[r][d]=true;
        u++;
        d--;
        r++;
        l--;
    }
    if(bfs(x2,y2,x3,y3))puts("YES");
    else puts("NO");
	return 0;
}