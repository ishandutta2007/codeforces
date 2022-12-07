#include <bits/stdc++.h>
using namespace std;
const int sz=5e3+10;
vector <int> sv[sz];
int to[sz];
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
bool feed(int v)
{
    for(int a=0; a<sz; a++) us[a]=0;
    return kuhn(v);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int p[n], c[n];
    for(int a=0; a<n; a++) cin>>p[a];
    for(int a=0; a<n; a++)
    {
        cin>>c[a];
        c[a]--;
        sv[p[a]].push_back(c[a]);
    }
    for(int a=0; a<m; a++) to[a]=-1;
    int an=0;
    while(feed(an)) an++;
    int d;
    cin>>d;
    for(int a=0; a<d; a++)
    {
        int i;
        cin>>i;
        i--;
        for(int b=0; b<sv[p[i]].size(); b++)
        {
            if(sv[p[i]][b]==c[i])
            {
                sv[p[i]].erase(sv[p[i]].begin()+b);
                break;
            }
        }
        if(to[c[i]]==p[i])
        {
            to[c[i]]=-1;
            while(feed(p[i])==0 and an>p[i])
            {
                for(int b=0; b<m; b++) if(to[b]==an-1) to[b]=-1;
                an--;
            }
        }
        cout<<an<<"\n";
    }
}