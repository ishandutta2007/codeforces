#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int ar[n], ar2[n], an[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        ar2[a]=ar[a];
        an[a]=0;
    }
    sort(ar2, ar2+n);
    for(int a=0; a<k; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        if(ar[u]>ar[v]) an[u]--;
        if(ar[v]>ar[u]) an[v]--;
    }
    for(int a=0; a<n; a++)
    {
        int q=lower_bound(ar2, ar2+n, ar[a])-ar2;
        cout<<q+an[a]<<" ";
    }
}