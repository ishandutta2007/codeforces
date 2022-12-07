#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
main()
{
	//freopen("input.txt", "r", stdin);
    int n, m, k;
    cin>>n>>m>>k;
    int os[k];
    for(int a=0; a<k; a++)
    {
        scanf("%d", &os[a]);
        os[a]--;
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
    int di[2][n];
    for(int i=0; i<2; i++)
    {
        for(int a=0; a<n; a++) di[i][a]=inf;
        queue <int> qu;
        if(i==0)
        {
            qu.push(0), di[i][0]=0;
        }
        else
        {
            qu.push(n-1), di[i][n-1]=0;
        }
        while(qu.size())
        {
            int v=qu.front();
            for(int a=0; a<sv[v].size(); a++)
            {
                int ne=sv[v][a];
                if(di[i][ne]>di[i][v]+1)
                {
                    di[i][ne]=di[i][v]+1;
                    qu.push(ne);
                }
            }
            qu.pop();
        }
    }
    pair <int, int> sp[k];
    multiset <int, greater <int> > se;
    for(int a=0; a<k; a++)
    {
        sp[a]={di[0][os[a]], di[1][os[a]]};
        se.insert(di[1][os[a]]);
    }
    sort(sp, sp+k);

    int an=di[0][n-1], be=0;

    for(int a=0; a+1<k; a++)
    {
        se.erase(se.find(sp[a].second));
        be=max(be, sp[a].first+(*se.begin())+1);
    }
    an=min(an, be);
    cout<<an;
}