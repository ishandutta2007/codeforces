#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n>30)
        {
            int x=6, y=10, z=14, os=n-30;
            if(os==6 or os==10 or os==14) z++, os--;
            cout<<"YES\n"<<x<<" "<<y<<" "<<z<<" "<<os<<"\n";
        }
        else cout<<"NO\n";
    }
}