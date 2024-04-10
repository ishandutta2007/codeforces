#include <bits/stdc++.h>
using namespace std;
int go[4][2]={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m, k;
bool ok(int x, int y)
{
    return (x>=0 and x<n and y>=0 and y<m);
}
const int sz=1e6+100;
pair <int, int> qu[sz];
main()
{
	//freopen("input.txt", "r", stdin);
	cin>>n>>m>>k;
	vector <pair <int, int> > sv[k], rsv[k];
	int fi[n][m];
	for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            scanf("%d", &fi[a][b]);
            fi[a][b]--;
            rsv[fi[a][b]].push_back({a, b});
        }
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            for(int i=0; i<4; i++)
            {
                int x=a+go[i][0], y=b+go[i][1];
                if(ok(x, y))
                {
                    sv[fi[a][b]].push_back({x, y});
                }
            }
        }
    }
    int q;
    cin>>q;
    int sp[q][4], an[q];
    for(int a=0; a<q; a++)
    {
        for(int i=0; i<4; i++) scanf("%d", &sp[a][i]), sp[a][i]--;
        an[a]=abs(sp[a][0]-sp[a][2])+abs(sp[a][1]-sp[a][3]);
    }
    for(int a=0; a<k; a++)
    {
        int di[2][n][m], di2[2][k];
        for(int i=0; i<2; i++)
        {
            for(int b=0; b<n; b++) for(int c=0; c<m; c++) di[i][b][c]=-1;
            for(int b=0; b<k; b++) di2[i][b]=-1;
            di2[i][a]=0;
            int l=0, r=1;
            qu[l]={a, -1};
            while(l<r)
            {
                int x=qu[l].first, y=qu[l].second;
                if(y==-1)
                {
                    vector <pair <int, int> > &ne=i ? rsv[x] : sv[x];
                    for(int b=0; b<ne.size(); b++)
                    {
                        int nx=ne[b].first, ny=ne[b].second;
                        if(di[i][nx][ny]==-1)
                        {
                            di[i][nx][ny]=di2[i][x]+1;
                            qu[r++]={nx, ny};
                        }
                    }
                }
                else
                {
                    for(int j=0; j<4; j++)
                    {
                        int nx=x+go[j][0], ny=y+go[j][1];
                        if(ok(nx, ny))
                        {
                            if(di[i][nx][ny]==-1)
                            {
                                di[i][nx][ny]=di[i][x][y]+1;
                                qu[r++]={nx, ny};
                            }
                            if(i and di2[i][fi[nx][ny]]==-1)
                            {
                                di2[i][fi[nx][ny]]=di[i][x][y]+1;
                                qu[r++]={fi[nx][ny], -1};
                            }
                        }
                    }
                    if(i==0 and di2[i][fi[x][y]]==-1)
                    {
                        di2[i][fi[x][y]]=di[i][x][y]+1;
                        qu[r++]={fi[x][y], -1};
                    }
                }
                l++;
            }
        }
        for(int b=0; b<q; b++)
        {
            int x1=sp[b][0], y1=sp[b][1], x2=sp[b][2], y2=sp[b][3];

            an[b]=min(an[b], di[1][x1][y1]+min(di[0][x2][y2], di2[0][fi[x2][y2]]));
        }
    }
    for(int a=0; a<q; a++) printf("%d\n", an[a]);
}