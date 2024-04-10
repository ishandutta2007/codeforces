#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n;
    cin>>n;
    n++;
    if(n==1) cout<<0;
    else
    {
        if(n%2==0) cout<<n/2;
        else cout<<n;
    }
}