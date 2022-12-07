#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    set <int> av;
    map <int, set <int> > ma;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%lld", &x);
        ma[x].insert(a);
    }
    for(auto it=ma.begin(); it!=ma.end(); it++) if((*it).second.size()>=2) av.insert((*it).first);
    while(av.size())
    {
        int x=*av.begin();
        ma[x].erase(ma[x].begin());
        int p=*ma[x].begin();
        ma[x].erase(ma[x].begin());
        if(ma[x].size()<2) av.erase(x);
        ma[x*2].insert(p);
        if(ma[x*2].size()==2) av.insert(x*2);
    }
    vector <pair <int, int> > sp;
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        if((*it).second.size())
        {
            sp.push_back(make_pair(*((*it).second.begin()), (*it).first));
        }
    }
    sort(sp.begin(), sp.end());
    cout<<sp.size()<<"\n";
    for(int a=0; a<sp.size(); a++) cout<<sp[a].second<<" ";
}