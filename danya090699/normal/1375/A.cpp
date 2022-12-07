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
        for(int a=0; a<n; a++)
        {
            int x;
            cin>>x;
            x=abs(x);
            if(a&1) x=-x;
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}