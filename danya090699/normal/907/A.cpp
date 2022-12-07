#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int v1, v2, v3, vm;
    cin>>v1>>v2>>v3>>vm;
    if(v2>vm)
    {
        int l=max(v3, vm), r=min(v3*2, vm*2);
        if(l<=r) cout<<v1*2<<"\n"<<v2*2<<"\n"<<l;
        else cout<<-1;
    }
    else cout<<-1;
}