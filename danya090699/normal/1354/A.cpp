#include <bits/stdc++.h>
#define int long long
using namespace std;
int de(int x, int y){return x/y+(x%y>0);}
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        if(a<=b) cout<<b<<"\n";
        else
        {
            if(d<c)
            {
                cout<<b+de(a-b, c-d)*c<<"\n";
            }
            else cout<<"-1\n";
        }
    }
}