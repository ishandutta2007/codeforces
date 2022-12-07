#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int a, b, n, an=0;
        cin>>a>>b>>n;
        if(a>b) swap(a, b);
        while(b<=n)
        {
            a+=b;
            if(a>b) swap(a, b);
            an++;
        }
        cout<<an<<"\n";
    }
}