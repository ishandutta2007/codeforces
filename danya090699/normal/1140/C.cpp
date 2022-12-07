#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    pair <int, int> ar[n];
    for(int a=0; a<n; a++) scanf("%lld%lld", &ar[a].second, &ar[a].first);
    sort(ar, ar+n, greater <pair <int, int> >());
    int su=0, an=0;
    multiset <int> se;
    for(int a=0; a<n; a++)
    {
        se.insert(ar[a].second);
        su+=ar[a].second;
        if(se.size()>k)
        {
            su-=(*se.begin());
            se.erase(se.begin());
        }
        an=max(an, ar[a].first*su);
    }
    cout<<an;
}