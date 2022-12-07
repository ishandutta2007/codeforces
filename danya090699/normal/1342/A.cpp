#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int x, y, a, b;
        cin>>x>>y>>a>>b;
        cout<<1ll*a*abs(x-y)+1ll*min(x, y)*min(a*2, b)<<"\n";
    }
}