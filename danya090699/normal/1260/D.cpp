#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int m, n, k, t;
    cin>>m>>n>>k>>t;
    int ar[m+1];
    for(int a=0; a<m; a++) scanf("%d", &ar[a]);
    ar[m]=1e9;
    sort(ar, ar+m+1, greater <int>());
    vector <pair <int, int> > sp[n+2];
    for(int a=0; a<k; a++)
    {
        int l, r, d;
        scanf("%d%d%d", &l, &r, &d);
        sp[l-1].push_back({d, 1});
        sp[r].push_back({d, -1});
    }
    int l=0, r=m+1;
    while(r-l>1)
    {
        int mid=(l+r)>>1, su=0, q=0;
        for(int a=0; a<=n; a++)
        {
            for(int b=0; b<sp[a].size(); b++)
            {
                if(sp[a][b].first>ar[mid]) q+=sp[a][b].second;
            }
            if(q) su+=3;
            else su++;
        }
        if(su<=t) l=mid;
        else r=mid;
    }
    cout<<l;
}