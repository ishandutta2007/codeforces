#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, ma=0, an=0;
    cin>>n;
    vector <int> sp[n];
    int be[n];
    for(int a=0; a<n; a++)
    {
        int q;
        scanf("%lld", &q);
        sp[a].resize(q), be[a]=0;
        for(int b=0; b<q; b++)
        {
            scanf("%lld", &sp[a][b]);
            be[a]=max(be[a], sp[a][b]);
        }
        ma=max(ma, be[a]);
    }
    for(int a=0; a<n; a++) an+=1ll*(ma-be[a])*sp[a].size();
    cout<<an;
}