#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector <int> sp[n];
    int nu[n];
    for(int a=0; a<n; a++) sp[a].push_back(a), nu[a]=a;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        u=nu[u], v=nu[v];
        if(sp[u].size()<sp[v].size()) swap(u, v);
        while(sp[v].size())
        {
            int x=sp[v].back();
            nu[x]=u, sp[u].push_back(x);
            sp[v].pop_back();
        }
    }
    int rt=nu[0];
    for(int a=0; a<n; a++) printf("%d ", sp[rt][a]+1);
}