#include <bits/stdc++.h>
#define iter vector <int>::iterator
using namespace std;
const int sz=1e3;
bool us[sz];
int n, pr[sz], tin[sz], timer=0;
vector <int> ve[2];
int que(int v, iter l, iter r)
{
    int k=r-l+(v!=-1);
    if(k==0) return 0;

    cout<<"? "<<k<<"\n";
    for(l; l<r; l++) printf("%d ", (*l)+1);
    if(v!=-1) cout<<v+1<<" ";
    cout<<"\n";

    int q;
    cin>>q;
    return q;
}
int find_u(int v, vector <int> sp)
{
    int q1=que(-1, sp.begin(), sp.end()), q2=que(v, sp.begin(), sp.end());
    if(q1==q2) return -1;

    int l=0, r=sp.size()-1;
    while(l<r)
    {
        int mid=(l+r)>>1;
        int q1=que(-1, sp.begin()+l, sp.begin()+mid+1), q2=que(v, sp.begin()+l, sp.begin()+mid+1);
        if(q1==q2) l=mid+1;
        else r=mid;
    }
    return sp[l];
}
void dfs(int v, int h)
{
    us[v]=1, tin[v]=timer, timer++, ve[h].push_back(v);
    while(1)
    {
        vector <int> sp;
        for(int a=0; a<n; a++) if(us[a]==0) sp.push_back(a);

        int ne=find_u(v, sp);
        if(ne==-1) break;
        pr[ne]=v, dfs(ne, h^1);
    }
}
int main()
{
    cin>>n;
    pr[0]=0, dfs(0, 0);
    int v=-1, u=-1;
    for(int i=0; i<2; i++)
    {
        for(int a=0; a<ve[i].size(); a++)
        {
            vector <int> sp;
            for(int b=0; b<ve[i].size(); b++) if(b!=a) sp.push_back(ve[i][b]);
            u=find_u(ve[i][a], sp);
            if(u!=-1)
            {
                v=ve[i][a];
                break;
            }
        }
        if(v!=-1) break;
    }
    if(v==-1)
    {
        cout<<"Y "<<ve[0].size()<<"\n";
        for(int a=0; a<ve[0].size(); a++) cout<<ve[0][a]+1<<" ";
        cout<<"\n";
    }
    else
    {
        if(tin[u]>tin[v]) swap(u, v);
        vector <int> cy, sp;
        while(tin[v]>tin[u])
        {
            cy.push_back(v), v=pr[v];
        }
        cy.push_back(v);
        while(u!=v)
        {
            sp.push_back(u), u=pr[u];
        }
        reverse(sp.begin(), sp.end());
        cout<<"N "<<cy.size()+sp.size()<<"\n";
        for(int a=0; a<cy.size(); a++) cout<<cy[a]+1<<" ";
        for(int a=0; a<sp.size(); a++) cout<<sp[a]+1<<" ";
        cout<<"\n";
    }
}