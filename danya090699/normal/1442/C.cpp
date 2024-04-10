#include <bits/stdc++.h>
using namespace std;
const int inf=1e9, mod=998244353;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector <int> sv[2][n];
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[0][u].push_back(v);
        sv[1][v].push_back(u);
    }
    int di[n][20];
    for(int a=0; a<n; a++) for(int i=0; i<20; i++) di[a][i]=-1;
    di[0][0]=0;
    queue <pair <int, int> > qu;
    qu.push({0, 0});
    while(qu.size())
    {
        int v=qu.front().first, q=qu.front().second;
        //cout<<v<<" "<<q<<"\n";
        for(int i=0; i<2; i++)
        {
            if(q+i<20)
            {
                int j=(q&1)^i;
                for(int a=0; a<sv[j][v].size(); a++)
                {
                    int ne=sv[j][v][a];
                    if(di[ne][q+i]==-1)
                    {
                        di[ne][q+i]=di[v][q]+1;
                        qu.push({ne, q+i});
                    }
                }
            }
        }
        qu.pop();
    }
    int an=inf;
    for(int i=0; i<20; i++)
    {
        //cout<<di[n-1][i]<<" ";
        if(di[n-1][i]!=-1) an=min(an, (1<<i)-1+di[n-1][i]);
    }
    if(an==inf)
    {
        pair <int, int> di[n][2];
        for(int a=0; a<n*2; a++) for(int i=0; i<2; i++) di[a][i]={inf, inf};
        di[0][0]={0, 0};
        set <pair <pair <int, int>, pair <int, int> > > se;
        se.insert({{0, 0}, {0, 0}});
        while(se.size())
        {
            int v=(*se.begin()).second.first, i=(*se.begin()).second.second;
            //cout<<di[v][i].first+j, di[v][i].second+1<<"\n";
            se.erase(se.begin());
            for(int j=0; j<2; j++)
            {
                int i2=i^j;
                pair <int, int> va={di[v][i].first+j, di[v][i].second+1};

                for(int a=0; a<sv[i2][v].size(); a++)
                {
                    int ne=sv[i2][v][a];
                    if(di[ne][i2]>va)
                    {
                        se.erase({di[ne][i2], {ne, i2}});
                        di[ne][i2]=va;
                        se.insert({di[ne][i2], {ne, i2}});
                    }
                }
            }
        }
        pair <int, int> be=min(di[n-1][0], di[n-1][1]);
        int x=1;
        for(int a=0; a<be.first; a++) x=2*x%mod;
        x--;
        if(x<0) x+=mod;
        an=(x+be.second)%mod;
    }
    cout<<an;
}