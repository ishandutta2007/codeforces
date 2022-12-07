#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int x, y;
        cin>>x>>y;
        int an=x+y;
        if(abs(x-y)>0) an+=abs(x-y)-1;
        cout<<an<<"\n";
    }
}