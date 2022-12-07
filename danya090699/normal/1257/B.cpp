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
        int x, y;
        cin>>x>>y;
        if(x>3) x=2e9;
        else if(x>1) x=3;
        if(x>=y) cout<<"YES\n";
        else cout<<"NO\n";
    }
}