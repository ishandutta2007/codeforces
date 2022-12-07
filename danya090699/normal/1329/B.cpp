#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int d, m, st=1, an=1;
        cin>>d>>m;
        while(d)
        {
            int q=min(st, d);
            an=1ll*an*(q+1)%m;
            st<<=1, d-=q;
        }
        an--;
        if(an<0) an+=m;
        cout<<an<<"\n";
    }
}