#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector <pair <int, int> > an;
    an.push_back({-1, 0});
    an.push_back({-1, -1});
    for(int a=0; a<n; a++)
    {
        an.push_back({a, a});
        an.push_back({a, a+1});
        an.push_back({a, a-1});
    }
    an.push_back({n, n});
    an.push_back({n, n-1});
    cout<<an.size()<<"\n";
    for(int a=0; a<an.size(); a++) cout<<an[a].first<<" "<<an[a].second<<"\n";
}