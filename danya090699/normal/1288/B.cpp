#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int a, b;
        cin>>a>>b;
        long long x=10, an=0;
        while(b>=x-1) an+=a, x*=10;
        cout<<an<<"\n";
    }
}