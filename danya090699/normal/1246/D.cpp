#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int h[sz];
vector <int> sv[sz], an;
bool comp(int a, int b){return h[a]<h[b];}
void dfs(int v)
{
    h[v]=0;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        dfs(ne), h[v]=max(h[v], h[ne]+1);
    }
    sort(sv[v].begin(), sv[v].end(), comp);
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=1; a<n; a++)
    {
        int pr;
        scanf("%d", &pr);
        sv[pr].push_back(a);
    }
    dfs(0);
    int v=0;
    while(sv[v].size())
    {
        if(sv[v].size()==1) v=sv[v][0];
        else
        {
            int u=sv[v].back();
            sv[v].pop_back();
            an.push_back(u);
            sv[sv[v].back()].push_back(u);
        }
    }
    v=0;
    printf("0 ");
    while(sv[v].size())
    {
        v=sv[v][0];
        printf("%d ", v);
    }
    reverse(an.begin(), an.end());
    cout<<"\n"<<an.size()<<"\n";
    for(int a=0; a<an.size(); a++) printf("%d ", an[a]);
}