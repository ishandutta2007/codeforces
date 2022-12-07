#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, p, l=1e9, r=1e9;
    cin>>n>>m>>p;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        if(x%p) l=min(l, a);
    }
    for(int a=0; a<m; a++)
    {
        int x;
        scanf("%d", &x);
        if(x%p) r=min(r, a);
    }
    cout<<l+r;
}