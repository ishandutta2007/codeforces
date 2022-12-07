#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, r;
        cin>>n>>r;
        long long an=0;
        if(r>=n) an++;
        int q=min(r, n-1);
        if(q) an+=(1ll+q)*q/2;
        cout<<an<<"\n";
    }
}