#include <bits/stdc++.h>
using namespace std;
const int inf=1e9+10;
main()
{
    //freopen("input.txt", "r", stdin);
    int q[6], an=2*inf;
    for(int a=0; a<6; a++) cin>>q[a];
    int n;
    cin>>n;
    vector <pair <int, int> > sp;
    int last[n];
    multiset <int> se;
    for(int a=0; a<n; a++)
    {
        last[a]=-inf;
        se.insert(-inf);
        int x;
        scanf("%d", &x);
        for(int b=0; b<6; b++) sp.push_back({x-q[b], a});
    }
    sort(sp.begin(), sp.end());

    for(int a=0; a<sp.size(); a++)
    {
        int x=sp[a].first, i=sp[a].second;
        se.erase(se.find(last[i]));
        last[i]=x;
        se.insert(x);
        an=min(an, x-(*se.begin()));
    }
    cout<<an;
}