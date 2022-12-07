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
        int a, b;
        cin>>a>>b;
        if(__gcd(a, b)==1) cout<<"Finite\n";
        else cout<<"Infinite\n";
    }
}