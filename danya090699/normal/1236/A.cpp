#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int a, b, c;
        cin>>a>>b>>c;
        int an=min(b, c/2)*3;
        b-=min(b, c/2);
        an+=min(a, b/2)*3;
        cout<<an<<"\n";
    }
}