#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        if(a<c) cout<<"1 ";
        else cout<<"-1 ";

        if(1ll*a*b>c) cout<<b<<"\n";
        else cout<<"-1\n";
    }
}