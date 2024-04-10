#include <bits/stdc++.h>
using namespace std;
long long a,b,x,y,z,na,nb,s=0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>a>>b>>x>>y>>z;
    na+=2*x;
    na+=y;
    nb+=y;
    nb+=3*z;
    if(na>a)
        s+=na-a;
    if(nb>b)
        s+=nb-b;
    cout<<s;
    return 0;
}
/**

**/