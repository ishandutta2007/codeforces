#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, dq, gq;
    cin>>n>>k;
    dq=n/2/(k+1);
    gq=dq*k;
    cout<<dq<<" "<<gq<<" "<<n-dq-gq;
}