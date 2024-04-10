#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    set <int> sv[n];
    int st[n], ok=1;
    for(int a=0; a<n; a++)
    {
        int v;
        scanf("%d", &v);
        v--;
        if(v!=-1)
        {
            sv[a].insert(v);
            sv[v].insert(a);
        }
        st[a]=0;
    }
    vector <int> sv2[n];
    set <pair <int, int> > av;
    for(int a=0; a<n; a++) av.insert(make_pair(sv[a].size(), a));
    while(av.size())
    {
        int v=(*av.begin()).second;
        av.erase(av.begin());
        if(sv[v].size())
        {
            int u=*sv[v].begin();
            av.erase(make_pair(sv[u].size(), u));
            sv[u].erase(v);
            av.insert(make_pair(sv[u].size(), u));
            if(sv2[v].size()&1) swap(u, v);
            sv2[u].push_back(v), st[v]++;
        }
        else if(sv2[v].size()&1) ok=0;
    }
    if(ok)
    {
        cout<<"YES\n";
        for(int a=0; a<n; a++) av.insert(make_pair(st[a], a));
        while(av.size())
        {
            int v=(*av.begin()).second;
            av.erase(av.begin());
            printf("%d\n", v+1);
            for(int a=0; a<sv2[v].size(); a++)
            {
                int u=sv2[v][a];
                av.erase(make_pair(st[u], u));
                st[u]--;
                av.insert(make_pair(st[u], u));
            }
        }
    }
    else cout<<"NO";
}