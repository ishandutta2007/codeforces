#include <bits/stdc++.h>
using namespace std;
map <int, multiset <int> > sv;
vector <int> an;
void dfs(int v)
{
    while(sv[v].size())
    {
        int ne=*sv[v].begin();
        sv[v].erase(sv[v].begin());
        sv[ne].erase(sv[ne].find(v));
        dfs(ne);
    }
    an.push_back(v);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    n--;
    int ar[2][n];
    for(int i=0; i<2; i++) for(int a=0; a<n; a++) scanf("%d", &ar[i][a]);

    bool ok=1;
    for(int a=0; a<n; a++)
    {
        int u=ar[0][a], v=ar[1][a];
        if(u>v) ok=0;
        else sv[u].insert(v), sv[v].insert(u);
    }
    if(ok==0)
    {
        cout<<-1;
        exit(0);
    }
    int nq=0, start;
    for(auto it=sv.begin(); it!=sv.end(); it++)
    {
        if((*it).second.size()&1) nq++, start=(*it).first;
    }
    if(nq==0) start=(*sv.begin()).first;

    if(nq==0 or nq==2)
    {
        dfs(start);
        if(an.size()==n+1)
        {
            for(int a=0; a<an.size(); a++) printf("%d ", an[a]);
        }
        else cout<<-1;
    }
    else cout<<-1;
}