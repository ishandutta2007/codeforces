#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int a, b, c, d, x, y, x1, y1, x2, y2;
        cin>>a>>b>>c>>d>>x>>y>>x1>>y1>>x2>>y2;
        x=x-a+b, y=y-c+d;
        if(x>=x1 and x<=x2 and y>=y1 and y<=y2)
        {
            if((a+b==0 or x1<x2) and (c+d==0 or y1<y2)) cout<<"Yes\n";
            else cout<<"No\n";
        }
        else cout<<"No\n";
    }
}