#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=2e5+10;
int w[sz], q[sz], an=0;
vector <int> sv[sz];
int de(int x, int y){return x/y+(x%y>0);}
void dfs(int v)
{
    q[v]=(sv[v].size()) ? 0 : 1;

    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        dfs(ne), w[v]+=w[ne], q[v]+=q[ne];
    }
    an=max(an, de(w[v], q[v]));
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=1; a<n; a++)
    {
        int pr;
        scanf("%lld", &pr);
        pr--, sv[pr].push_back(a);
    }
    for(int a=0; a<n; a++) scanf("%lld", &w[a]);

    dfs(0);
    cout<<an;
}