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
        int c, m, x;
        cin>>c>>m>>x;
        int q=min(c, m);
        cout<<min(q, (c+m+x)/3)<<"\n";
    }
}