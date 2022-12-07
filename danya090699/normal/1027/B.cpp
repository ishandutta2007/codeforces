#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    for(int a=0; a<q; a++)
    {
        int x, y;
        cin>>x>>y;
        x--, y--;
        int nu=x*n+y, an;
        if((x+y)&1) an=(n*n)/2+((n*n)%2>0)+nu/2+1;
        else an=nu/2+1;
        cout<<an<<"\n";
    }
}