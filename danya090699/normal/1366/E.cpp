#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ar[n], mi[m];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    reverse(ar, ar+n);
    vector <pair <int, int> > pref;
    for(int a=0; a<n; a++)
    {
        if(a==0 or pref.back().first>ar[a]) pref.push_back({ar[a], 1});
        else pref.back().second++;
    }
    for(int a=0; a<m; a++) scanf("%d", &mi[a]);
    reverse(mi, mi+m);
    int an=1, yk=0;
    if(pref.back().first!=mi[m-1]) an=0;
    for(int a=0; a<m-1; a++)
    {
        while(yk<pref.size() and pref[yk].first!=mi[a]) yk++;
        if(yk==pref.size()) an=0;
        else an=1ll*an*pref[yk].second%mod;
    }
    cout<<an;
}