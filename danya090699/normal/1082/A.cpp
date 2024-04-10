#include <bits/stdc++.h>
using namespace std;
const int inf=2e9+10;
int de(int x, int y){return x/y+(x%y>0);}
int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n, x, y, d, an=inf;
        cin>>n>>x>>y>>d;
        if(abs(x-y)%d==0) an=abs(x-y)/d;
        if((y-1)%d==0) an=min(an, de(x, d)+(y-1)/d);
        if((n-y)%d==0) an=min(an, de(n-x, d)+(n-y)/d);
        if(an!=inf) cout<<an<<"\n";
        else cout<<"-1\n";
    }
}