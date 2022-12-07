#include <bits/stdc++.h>
using namespace std;
const int sz=1e3+10, inf=1e9;
int cx[sz], cy[sz], go[sz][sz], ve[sz][sz];

struct ot
{
    int x1, y1, x2, y2;
};

int n1=2, n2=2, to[sz];
vector <int> sv[sz];
bool us[sz];
bool kuhn(int v)
{
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(to[ne]==-1)
        {
            to[ne]=v;
            return true;
        }
        else
        {
            if(us[to[ne]]==0)
            {
                if(kuhn(to[ne]))
                {
                    to[ne]=v;
                    return true;
                }
            }
        }
    }
    return false;
}
vector <int> sv2[sz*2];
bool us2[sz*2], in[sz*2];
void dfs2(int v)
{
    us2[v]=1;
    for(int a=0; a<sv2[v].size(); a++)
    {
        int ne=sv2[v][a];
        if(us2[ne]==0) dfs2(ne);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n][2];
    map <int, int> mx, my;
    for(int a=0; a<n; a++)
    {
        cin>>ar[a][0]>>ar[a][1];
        mx[ar[a][0]]=0, my[ar[a][1]]=0;
    }
    int qx=0, qy=0;
    for(auto it=mx.begin(); it!=mx.end(); it++) cx[qx]=(*it).first, (*it).second=qx, qx++;
    for(auto it=my.begin(); it!=my.end(); it++) cy[qy]=(*it).first, (*it).second=qy, qy++;
    for(int a=0; a<n; a++)
    {
        int x=mx[ar[a][0]], y=my[ar[a][1]];
        go[y][x]=1, ve[y][x]=1;
    }
    for(int a=0; a<qy; a++)
    {
        vector <int> sp;
        for(int b=0; b<qx; b++) if(go[a][b]) sp.push_back(b);
        for(int b=0; b+1<sp.size(); b++)
        {
            if(sp[b]+1<sp[b+1])
            {
                for(int c=sp[b]+1; c<sp[b+1]; c++) go[a][c]=n1;
                n1++;
            }
        }
    }
    for(int a=0; a<qx; a++)
    {
        vector <int> sp;
        for(int b=0; b<qy; b++) if(ve[b][a]) sp.push_back(b);
        for(int b=0; b+1<sp.size(); b++)
        {
            if(sp[b]+1<sp[b+1])
            {
                for(int c=sp[b]+1; c<sp[b+1]; c++) ve[c][a]=n2;
                n2++;
            }
        }
    }
    for(int a=0; a<qy; a++)
    {
        for(int b=0; b<qx; b++)
        {
            if(go[a][b]>1 and ve[a][b]>1) sv[go[a][b]].push_back(ve[a][b]);
        }
    }

    for(int a=0; a<n2; a++) to[a]=-1;
    for(int a=0; a<n1; a++)
    {
        for(int b=0; b<n1; b++) us[b]=0;
        kuhn(a);
    }

    for(int a=0; a<n1; a++)
    {
        for(int b=0; b<sv[a].size(); b++)
        {
            int u=a, v=sv[a][b];
            if(to[v]==u) sv2[v+n1].push_back(u), in[u]=1;
            else sv2[u].push_back(v+n1);
        }
    }

    bool ok[n1+n2];
    for(int a=0; a<n1; a++) if(us2[a]==0 and in[a]==0) dfs2(a);

    for(int a=0; a<n1+n2; a++)
    {
        ok[a]=1;
        if(a<n1 and us2[a]==0) ok[a]=0;
        if(a>=n1 and us2[a]) ok[a]=0;
    }
    ok[0]=0, ok[n1]=0;

    vector <ot> an;
    for(int a=0; a<qy; a++)
    {
        int yk=0;
        while(yk<qx)
        {
            if(ok[go[a][yk]])
            {
                int x1=cx[yk], y1=cy[a];
                while(yk<qx)
                {
                    if(ok[go[a][yk]]) yk++;
                    else break;
                }
                int x2=cx[yk-1], y2=cy[a];
                an.push_back({x1, y1, x2, y2});
            }
            else yk++;
        }
    }
    cout<<an.size()<<"\n";
    for(int a=0; a<an.size(); a++) cout<<an[a].x1<<" "<<an[a].y1<<" "<<an[a].x2<<" "<<an[a].y2<<"\n";

    an.clear();
    for(int a=0; a<qx; a++)
    {
        int yk=0;
        while(yk<qy)
        {
            if(ok[ve[yk][a]+n1])
            {
                int x1=cx[a], y1=cy[yk];
                while(yk<qy)
                {
                    if(ok[ve[yk][a]+n1]) yk++;
                    else break;
                }
                int x2=cx[a], y2=cy[yk-1];
                an.push_back({x1, y1, x2, y2});
            }
            else yk++;
        }
    }
    cout<<an.size()<<"\n";
    for(int a=0; a<an.size(); a++) cout<<an[a].x1<<" "<<an[a].y1<<" "<<an[a].x2<<" "<<an[a].y2<<"\n";
}