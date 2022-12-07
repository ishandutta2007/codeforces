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
        int n;
        cin>>n;
        if(n%2) cout<<7, n-=3;
        for(int a=2; a<=n; a+=2) cout<<1;
        cout<<"\n";
    }
}