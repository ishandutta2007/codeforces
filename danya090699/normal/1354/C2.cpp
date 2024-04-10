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
        double a=0.5/sin(PI/n/2);
        cout<<fixed<<setprecision(10)<<a*cos(PI/n/4)*2<<"\n";
    }
}