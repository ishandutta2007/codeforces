#include <bits/stdc++.h>
using namespace std;
int us[8][8], an[1500][4], q=0;
void mov(int x, int y, int nx, int ny)
{
    us[x][y]=0, us[nx][ny]=1;
    an[q][0]=x, an[q][1]=y, an[q][2]=nx, an[q][3]=ny, q++;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int k;
    cin>>k;
    int ar[k][2];
    for(int a=0; a<k; a++)
    {
        char sy;
        cin>>sy;
        ar[a][1]=sy-'a';
        cin>>sy;
        ar[a][0]=sy-'1';
        us[ar[a][0]][ar[a][1]]=1;
    }
    for(int a=0; a<k; a++)
    {
        int tx=a/8, ty=a%8;
        for(int b=a; b<64; b++)
        {
            int sx=b/8, sy=b%8;
            if(us[sx][sy])
            {
                int pr[8][8][2];
                for(int c=0; c<8; c++) for(int d=0; d<8; d++) pr[c][d][0]=-1;
                pr[sx][sy][0]=sx;
                queue <pair <int, int> > qu;
                qu.push({sx, sy});
                while(qu.size())
                {
                    int x=qu.front().first, y=qu.front().second;
                    for(int dx=-1; dx<=1; dx++)
                    {
                        for(int dy=-1; dy<=1; dy++)
                        {
                            if(dx!=0 and dy!=0)
                            {
                                int nx=x+dx, ny=y+2*dy;
                                if(nx>=0 and nx<8 and ny>=0 and ny<8)
                                {
                                    if(pr[nx][ny][0]==-1)
                                    {
                                        qu.push({nx, ny});
                                        pr[nx][ny][0]=x, pr[nx][ny][1]=y;
                                    }
                                }
                                nx=x+2*dx, ny=y+dy;
                                if(nx>=0 and nx<8 and ny>=0 and ny<8)
                                {
                                    if(pr[nx][ny][0]==-1)
                                    {
                                        qu.push({nx, ny});
                                        pr[nx][ny][0]=x, pr[nx][ny][1]=y;
                                    }
                                }
                            }
                        }
                    }
                    qu.pop();
                }
                vector <pair <int, int> > sp;
                while(sx!=tx or sy!=ty)
                {
                    sp.push_back({tx, ty});
                    int x=pr[tx][ty][0], y=pr[tx][ty][1];
                    tx=x, ty=y;
                }
                sp.push_back({tx, ty});
                reverse(sp.begin(), sp.end());
                int yk=0;
                while(yk+1<sp.size())
                {
                    int yk2=yk+1;
                    while(us[sp[yk2].first][sp[yk2].second]) yk2++;

                    for(int c=yk2-1; c>=yk; c--)
                    {
                        mov(sp[c].first, sp[c].second, sp[c+1].first, sp[c+1].second);
                    }
                    yk=yk2;
                }
                sp.clear();
                break;
            }
        }
    }
    cout<<q<<"\n";
    for(int a=0; a<q; a++)
    {
        char sy='a'+an[a][1];
        cout<<sy;
        sy='1'+an[a][0];
        cout<<sy<<"-";
        sy='a'+an[a][3];
        cout<<sy;
        sy='1'+an[a][2];
        cout<<sy<<"\n";
    }
}