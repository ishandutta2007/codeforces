#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int to[sz], pr[sz], si[sz], cyq=0;
bool us[sz];
vector <int> cy[sz];
int find_se(int v)
{
    if(v!=pr[v]) pr[v]=find_se(pr[v]);
    return pr[v];
}
void merge(int u, int v)
{
    u=find_se(u), v=find_se(v);
    if(u!=v)
    {
        if(si[v]>si[u]) swap(u, v);
        si[u]+=si[v];
        pr[v]=u;
    }
}
void pr_cy(vector <int> &ve)
{
    printf("%d\n", ve.size());
    for(int a=0; a<ve.size(); a++) printf("%d ", ve[a]+1);
    printf("\n");
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, s;
    cin>>n>>s;
    map <int, int> q;
    map <int, set <int> > se;
    int ar[n], n2=0;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        q[ar[a]]++;
    }
    for(auto it=q.begin(); it!=q.end(); it++)
    {
        for(int a=0; a<(*it).second; a++)
        {
            se[(*it).first].insert(n2), n2++;
        }
    }
    for(int a=0; a<n; a++)
    {
        if(se[ar[a]].find(a)!=se[ar[a]].end())
        {
            se[ar[a]].erase(a), ar[a]=-1;
        }
        else s--;
    }
    if(s>=0)
    {
        for(int a=0; a<n; a++)
        {
            if(ar[a]!=-1)
            {
                to[a]=*(se[ar[a]].begin());
                se[ar[a]].erase(se[ar[a]].begin());
            }
        }
        map <int, vector <int> > sp;
        for(int a=0; a<n; a++) if(ar[a]!=-1) sp[ar[a]].push_back(a);
        for(int a=0; a<n; a++)
        {
            pr[a]=a, si[a]=1;
        }
        for(int a=0; a<n; a++)
        {
            if(ar[a]!=-1 and us[a]==0)
            {
                us[a]=1;
                int cu=to[a];
                while(us[cu]==0)
                {
                    merge(a, cu), us[cu]=1, cu=to[cu];
                }
            }
        }
        for(auto it=sp.begin(); it!=sp.end(); it++)
        {
            vector <int> &ve=(*it).second;
            for(int a=1; a<ve.size(); a++)
            {
                int u=find_se(ve[0]), v=find_se(ve[a]);

                if(u!=v)
                {
                    swap(to[ve[0]], to[ve[a]]);
                    merge(u, v);
                }
            }
        }
        for(int a=0; a<n; a++) us[a]=0;
        for(int a=0; a<n; a++)
        {
            if(ar[a]!=-1 and us[a]==0)
            {
                int cu=a;
                while(us[cu]==0)
                {
                    cy[cyq].push_back(cu), us[cu]=1, cu=to[cu];
                }
                cyq++;
            }
        }
        int yk=0;
        vector <int> cy1, cy2;
        if(s>=2 and cyq>=2)
        {
            while(s and yk<cyq)
            {
                for(int b=0; b<cy[yk].size(); b++) cy1.push_back(cy[yk][b]);
                cy2.push_back(cy[yk][0]);
                s--, yk++;
            }
            reverse(cy2.begin(), cy2.end());
        }

        int an=cyq-yk;
        if(cy1.size()) an+=2;
        cout<<an<<"\n";
        if(cy1.size())
        {
            pr_cy(cy1), pr_cy(cy2);
        }
        while(yk<cyq)
        {
            pr_cy(cy[yk]), yk++;
        }
    }
    else cout<<-1;
}