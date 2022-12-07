#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n, su=0, cu;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        su+=ar[a];
    }
    if(su%2==0)
    {
        bool fo=0;
        set <int> se;
        cu=0;
        for(int a=0; a<n; a++)
        {
            se.insert(cu);
            cu+=ar[a];
            if(se.find(su/2-ar[a])!=se.end()) fo=1;
        }
        se.clear();
        cu=0;
        for(int a=n-1; a>=0; a--)
        {
            se.insert(cu);
            cu+=ar[a];
            if(se.find(su/2-ar[a])!=se.end()) fo=1;
        }
        if(fo) cout<<"YES";
        else cout<<"NO";
    }
    else cout<<"NO";
}