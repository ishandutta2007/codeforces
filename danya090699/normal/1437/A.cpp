#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int l, r;
        cin>>l>>r;
        if(l*2>r) cout<<"YES\n";
        else cout<<"NO\n";
    }
}