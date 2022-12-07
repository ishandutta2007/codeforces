#include <bits/stdc++.h>
using namespace std;
const int sz=1e3+10;
int n, m, x[2], y[2], st=0, di[2][sz][sz], pr[2][sz][sz][2];
void go(int i, int nx, int ny)
{
    cout<<nx<<" "<<ny<<endl;
    x[i]=nx, y[i]=ny;
    if(x[i]==x[i^1] and y[i]==y[i^1]) exit(0);
}
void way(vector <pair <int, int> > &sp, int x, int y, int i)
{
    while(di[i][x][y])
    {
        int nx=pr[i][x][y][0], ny=pr[i][x][y][1];
        x=nx, y=ny;
        sp.push_back({x, y});
    }
}
main()
{
    //ifstream in("input.txt");
    cin>>n>>m>>x[0]>>y[0]>>x[1]>>y[1];
    if((x[0]+y[0])%2==(x[1]+y[1])%2) st=1;

    for(int i=0; i<2; i++)
    {
        for(int a=1; a<=n; a++) for(int b=1; b<=m; b++) di[i][a][b]=1e9;
        queue <pair <int, int> > qu;
        qu.push({n/2+i, m/2});
        di[i][n/2+i][m/2]=0;
        while(qu.size())
        {
            int cx=qu.front().first, cy=qu.front().second;
            for(int a=0; a<2; a++)
            {
                for(int b=0; b<2; b++)
                {
                    for(int c=0; c<2; c++)
                    {
                        int dx=1, dy=2;
                        if(a) swap(dx, dy);
                        if(b) dx=-dx;
                        if(c) dy=-dy;
                        int nx=cx+dx, ny=cy+dy;
                        if(nx>0 and nx<=n and ny>0 and ny<=m)
                        {
                            if(di[i][nx][ny]>di[i][cx][cy]+1)
                            {
                                di[i][nx][ny]=di[i][cx][cy]+1;
                                pr[i][nx][ny][0]=cx;
                                pr[i][nx][ny][1]=cy;
                                qu.push({nx, ny});
                            }
                        }
                    }
                }
            }
            qu.pop();
        }
    }
    int ds=di[st][x[st]][y[st]], dw=di[st^1][x[st^1]][y[st^1]];
    if(ds<dw or (ds==dw and st==0))
    {
        if(st==0) cout<<"WHITE"<<endl;
        else
        {
            cout<<"BLACK"<<endl;
            cin>>x[st^1]>>y[st^1];
        }
        vector <pair <int, int> > sp;
        way(sp, x[st], y[st], st);
        for(int a=0; a+1<sp.size(); a++)
        {
            go(st, sp[a].first, sp[a].second);
            cin>>x[st^1]>>y[st^1];
        }
        go(st, n/2+st, m/2);
    }
    else if(di[st^1][x[st]][y[st]]>di[st^1][x[st^1]][y[st^1]]+1)
    {
        if(st) cout<<"WHITE"<<endl;
        else
        {
            cout<<"BLACK"<<endl;
            cin>>x[st]>>y[st];
        }
        vector <pair <int, int> > sp;
        way(sp, x[st^1], y[st^1], st^1);
        for(int a=0; a+1<sp.size(); a++)
        {
            go(st^1, sp[a].first, sp[a].second);
            cin>>x[st]>>y[st];
        }
        go(st^1, n/2+(st^1), m/2);
    }
    else
    {
        if(st==0) cout<<"WHITE"<<endl;
        else
        {
            cout<<"BLACK"<<endl;
            cin>>x[st^1]>>y[st^1];
        }
        vector <pair <int, int> > sp;
        way(sp, x[st], y[st], st^1);
        for(int a=0; a<sp.size(); a++)
        {
            go(st, sp[a].first, sp[a].second);
            cin>>x[st^1]>>y[st^1];
        }
        int dx=abs(x[0]-x[1]), dy=abs(y[0]-y[1]);
        if((dx==1 and dy==2) or (dx==2 and dy==1)) go(st, x[st^1], y[st^1]);
        int k=1;
        if(st) k=-1;

        go(st, x[st]+2*k, y[st]-1*k);
        cin>>x[st^1]>>y[st^1];
        go(st, x[st]-2*k, y[st]-1*k);
        cin>>x[st^1]>>y[st^1];
        go(st, x[st]-1*k, y[st]+2*k);
    }
}