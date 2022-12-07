#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int a, b, n, m;
        cin>>a>>b>>n>>m;
        if(a+b<n+m or min(a, b)<m) cout<<"No\n";
        else cout<<"Yes\n";
    }
}