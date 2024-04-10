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
        int a, b;
        cin>>a>>b;
        if((a+b)%3==0 and (a+b)/3<=a and (a+b)/3<=b) cout<<"YES\n";
        else cout<<"NO\n";
    }
}