#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, sz2=110;
int d[sz][sz2];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k, s;
    cin>>n>>m>>k>>s;
    int co[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &co[a]), co[a]--;
    }
    vector <int> sv[n];
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    for(int i=0; i<k; i++)
    {
        queue <int> qu;
        bool us[n];
        for(int a=0; a<n; a++)
        {
            if(co[a]==i)
            {
                us[a]=1, qu.push(a);
            }
            else us[a]=0;
        }
        int le=0;
        while(qu.size())
        {
            int q=qu.size();
            for(int a=0; a<q; a++)
            {
                int v=qu.front();
                d[v][i]=le;
                for(int b=0; b<sv[v].size(); b++)
                {
                    int ne=sv[v][b];
                    if(us[ne]==0)
                    {
                        us[ne]=1, qu.push(ne);
                    }
                }
                qu.pop();
            }
            le++;
        }
    }
    for(int a=0; a<n; a++)
    {
        long long su=0;
        sort(d[a], d[a]+k);
        for(int b=0; b<s; b++) su+=d[a][b];
        printf("%lld ", su);
    }
}