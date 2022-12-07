#include <bits/stdc++.h>
using namespace std;
const double PI=atan2(0, -1);
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<fixed<<setprecision(10)<<0.5/tan(PI/n/2)*2<<"\n";
    }
}