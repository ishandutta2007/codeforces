#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int l, r;
        cin>>l>>r;
        if(l*2<=r) cout<<l<<" "<<l*2<<"\n";
        else cout<<"-1 -1\n";
    }
}