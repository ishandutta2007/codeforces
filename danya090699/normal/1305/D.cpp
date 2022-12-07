#include <bits/stdc++.h>
using namespace std;
main()
{
    int n;
    cin>>n;
    int st[n+1], us[n+1];
    for(int a=0; a<=n; a++) st[a]=0, us[a]=0;
    vector <int> sv[n+1];
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        cin>>u>>v;
        sv[u].push_back(v);
        sv[v].push_back(u);
        st[u]++, st[v]++;
    }
    while(1)
    {
        vector <int> sp;
        for(int a=1; a<=n; a++) if(!us[a] and st[a]<2) sp.push_back(a);
        if(sp.size()==1)
        {
            cout<<"! "<<sp[0]<<endl;
            break;
        }
        else
        {
            int u=sp[0], v=sp[1];
            cout<<"? "<<u<<" "<<v<<endl;
            int x;
            cin>>x;
            if(x==u or x==v)
            {
                cout<<"! "<<x<<endl;
                break;
            }
            else
            {
                us[u]=1, us[v]=1;
                for(int a=0; a<sv[u].size(); a++) st[sv[u][a]]--;
                for(int a=0; a<sv[v].size(); a++) st[sv[v][a]]--;
            }
        }
    }
}