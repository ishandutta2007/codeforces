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
        int x=(1<<n);
        for(int a=1; a<n; a++)
        {
            if(a<n/2) x+=(1<<a);
            else x-=(1<<a);
        }
        cout<<x<<"\n";
    }
}