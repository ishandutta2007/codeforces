#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        if(x==1) cout<<"0\n";
        else if(x==2) cout<<"1\n";
        else if(x==3) cout<<"2\n";
        else cout<<2+(x&1)<<"\n";
    }
}