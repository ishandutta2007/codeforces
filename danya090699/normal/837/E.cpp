//Come on, make Togliatti great again!
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18;
int gcd(int a, int b)
{
    if(b==0) return a;
    else return gcd(b, a%b);
}
int lcm(int x, int y)
{
    x/=gcd(x, y);
    if(inf/y<x) return inf;
    else return x*y;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int x, y, an=0;
    cin>>x>>y;
    vector <int> de;
    for(int a=1; a*a<=x; a++)
    {
        if(x%a==0)
        {
            de.push_back(a);
            if(a!=x/a) de.push_back(x/a);
        }
    }
    while(y>0)
    {
        int cu=gcd(x, y);
        int be=0;
        for(int a=0; a<de.size(); a++)
        {
            int ne=de[a];
            if(ne>cu and ne%cu==0)
            {
                int z=lcm(cu, ne);
                be=max(be, (y/z)*z);
            }
        }
        an+=(y-be)/cu;
        y=be;
    }
    cout<<an;
}