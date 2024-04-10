#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, x, y;
        cin>>n>>x>>y;
        x--, y=n-y;
        cout<<1+max(0, min(x-(y-1), n-1))<<" "<<n-max(0, y-x)<<"\n";
    }
}