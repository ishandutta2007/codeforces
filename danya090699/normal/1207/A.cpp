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
        int b, p, f, h, c;
        cin>>b>>p>>f>>h>>c;
        int q=min(b/2, p+f);
        p=min(p, q), f=min(f, q);
        if(h>c) cout<<p*h+min(f, q-p)*c<<"\n";
        else cout<<f*c+min(p, q-f)*h<<"\n";
    }
}