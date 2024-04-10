#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int n, m;
        cin>>n>>m;
        int ar[n][m];
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<m; b++) scanf("%d", &ar[a][b]);
        }
        vector <pair <int, int> > sp;
        for(int a=0; a<n+m-1; a++)
        {
            sp.push_back({0, 0});
            for(int b=0; b<n; b++)
            {
                int c=a-b;
                if(c>=0 and c<m)
                {
                    if(ar[b][c]==0) sp.back().first++;
                    else sp.back().second++;
                }
            }
        }
        int an=0;
        for(int a=0; a<sp.size()-1-a; a++)
        {
            int q0=sp[a].first+sp[sp.size()-1-a].first;
            int q1=sp[a].second+sp[sp.size()-1-a].second;
            an+=min(q0, q1);
        }
        cout<<an<<"\n";
    }
}