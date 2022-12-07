#include <bits/stdc++.h>
using namespace std;
const int sz=310;
int n, m, us[sz][sz], pr[sz*sz], si[sz*sz];
vector <int> st[sz][sz];

bool comp(pair <int, int> a, pair <int, int> b)
{
    return st[a.first][a.second].back()>st[b.first][b.second].back();
}
int find_pr(int v)
{
    if(pr[v]!=v) pr[v]=find_pr(pr[v]);
    return pr[v];
}
int go[4][2]={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int ins(int x, int y)
{
    int re=1;
    us[x][y]=1;
    for(int i=0; i<4; i++)
    {
        int nx=x+go[i][0], ny=y+go[i][1];
        if(nx>=0 and nx<n and ny>=0 and ny<m and us[nx][ny])
        {
            int u=find_pr(x*m+y), v=find_pr(nx*m+ny);
            if(u!=v)
            {
                re--;
                if(si[u]<si[v]) swap(u, v);
                si[u]+=si[v], pr[v]=u;
            }
        }
    }
    return re;
}
void clean()
{
    int nu=0;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            us[a][b]=0, pr[nu]=nu, si[nu]=1, nu++;
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>n>>m>>q;
    int sp[n*m+q][3];
    for(int a=0; a<n*m; a++)
    {
        sp[a][0]=a/m, sp[a][1]=a%m, sp[a][2]=0;
        st[a/m][a%m].push_back(a);
    }
    for(int a=n*m; a<n*m+q; a++)
    {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        x--, y--;
        sp[a][0]=x, sp[a][1]=y, sp[a][2]=c;
        st[x][y].push_back(a);
    }
    for(int a=0; a<n*m; a++)
    {
        st[a/m][a%m].push_back(n*m+q);
        reverse(st[a/m][a%m].begin(), st[a/m][a%m].end());
    }

    int yk=0, add[n*m+q+1];
    for(int a=0; a<=n*m+q; a++) add[a]=0;
    while(yk<n*m+q)
    {
        int lg=yk;
        vector <pair <int, int> > ve;
        clean();
        while(yk<n*m+q and sp[yk][2]==sp[lg][2])
        {
            int x=sp[yk][0], y=sp[yk][1];
            st[x][y].pop_back();
            if(!us[x][y])
            {
                add[yk]+=ins(x, y);
                ve.push_back({x, y});
            }
            yk++;
        }
        sort(ve.begin(), ve.end(), comp);
        clean();
        for(int a=0; a<ve.size(); a++)
        {
            int x=ve[a].first, y=ve[a].second;
            add[st[x][y].back()]-=ins(x, y);
        }
    }
    int an=0;
    for(int a=0; a<n*m+q; a++)
    {
        an+=add[a];
        if(a>=n*m) printf("%d\n", an);
    }
}