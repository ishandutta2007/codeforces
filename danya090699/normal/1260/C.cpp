#include <bits/stdc++.h>
using namespace std;
int de(int x, int y){return x/y+(x%y>0);}
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int r, b, k;
        cin>>r>>b>>k;
        if(r<b) swap(r, b);
        if(de(r-__gcd(r, b), b)>=k) cout<<"REBEL\n";
        else cout<<"OBEY\n";
    }
}