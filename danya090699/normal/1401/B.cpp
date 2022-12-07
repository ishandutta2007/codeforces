#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int a0, a1, a2, b0, b1, b2;
        cin>>a0>>a1>>a2>>b0>>b1>>b2;
        int n=a0+a1+a2, q=min(a2, b1), an=q*2;
        if(a1+b2>n-q) an-=(a1+b2-(n-q))*2;
        cout<<an<<"\n";
    }
}