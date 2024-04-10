#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, an=0;
    cin>>n>>m;
    set <int> sv[n];
    int ar[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        ar[a]--;
    }
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].insert(v);
    }
    vector <int> sp;
    for(int a=n-2; a>=0; a--)
    {
        int v=ar[a];
        if(sv[v].count(ar[n-1]))
        {
            bool ok=1;
            if(sp.size()<=sv[v].size())
            {
                for(int b=0; b<sp.size(); b++) if(sv[v].count(sp[b])==0) ok=0;
            }
            else ok=0;

            if(ok) an++;
            else sp.push_back(v);
        }
        else sp.push_back(v);
    }
    cout<<an;
}