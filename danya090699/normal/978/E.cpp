#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, w, cu=0, mi=0, ma=0;
    cin>>n>>w;
    for(int a=0; a<n; a++)
    {
        int d;
        cin>>d;
        cu+=d;
        mi=min(mi, cu), ma=max(ma, cu);
    }
    cout<<max(0, w-(ma-mi)+1);
}