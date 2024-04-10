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
        int a, b, n;
        cin>>a>>b>>n;
        if(n%3==0) cout<<a<<"\n";
        if(n%3==1) cout<<b<<"\n";
        if(n%3==2) cout<<(a^b)<<"\n";
    }
}