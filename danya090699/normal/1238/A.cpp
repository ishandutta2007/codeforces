#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int x, y;
        cin>>x>>y;
        if(x-y==1) cout<<"NO\n";
        else cout<<"YES\n";
    }
}