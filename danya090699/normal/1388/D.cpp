#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=2e5+10;
vector <int> sv[sz], an, an2;
int va[sz], pr[sz], su=0;
void dfs(int v)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        dfs(ne);
        if(va[ne]>0) va[v]+=va[ne];
    }
    if(va[v]>0) an.push_back(v);
    else an2.push_back(v);
    su+=va[v];
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++) scanf("%lld", &va[a]);
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &pr[a]);
        if(pr[a]!=-1)
        {
            pr[a]--, sv[pr[a]].push_back(a);
        }
    }
    for(int a=0; a<n; a++) if(pr[a]==-1) dfs(a);
    while(an2.size())
    {
        an.push_back(an2.back());
        an2.pop_back();
    }
    cout<<su<<"\n";
    for(int a=0; a<n; a++) printf("%d ", an[a]+1);
}