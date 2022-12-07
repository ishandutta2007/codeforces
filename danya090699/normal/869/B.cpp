#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int a, b, an=1, mod=10;
    cin>>a>>b;
    for(int i=a+1; i<=b; i++)
    {
        an=(an*(i%10))%mod;
        if(an==0) break;
    }
    cout<<an;
}