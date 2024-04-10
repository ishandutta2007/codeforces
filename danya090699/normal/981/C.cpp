#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector <int> sv[n];
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    vector <int> fo, leaf;
    for(int a=0; a<n; a++)
    {
        if(sv[a].size()>2) fo.push_back(a);
        if(sv[a].size()==1) leaf.push_back(a);
    }
    if(fo.size()==1)
    {
        cout<<"Yes\n"<<leaf.size()<<"\n";
        for(int a=0; a<leaf.size(); a++) cout<<fo[0]+1<<" "<<leaf[a]+1<<"\n";
    }
    else if(fo.size()==0)
    {
        cout<<"Yes\n"<<1<<"\n"<<leaf[0]+1<<" "<<leaf[1]+1;
    }
    else cout<<"No";
}