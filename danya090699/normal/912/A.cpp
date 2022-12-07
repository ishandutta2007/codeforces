#include <bits/stdc++.h>
#define int long long
using namespace std;
int ma(int x, int y)
{
    if(x<y) return y;
    else return x;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int a, b, x, y, z;
    cin>>a>>b>>x>>y>>z;
    int a2=x*2+y, b2=z*3+y;
    cout<<ma(0, a2-a)+ma(0, b2-b);
}