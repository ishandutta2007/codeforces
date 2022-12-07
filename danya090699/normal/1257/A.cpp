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
        int n, x, a, b;
        cin>>n>>x>>a>>b;
        cout<<min(n-1, abs(a-b)+x)<<"\n";
    }
}