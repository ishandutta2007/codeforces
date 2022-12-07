#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[2][n];
    for(int i=0; i<2; i++)
    {
        for(int a=0; a<n; a++) cin>>ar[i][a];
    }
    long long x=(1ll*ar[0][1]*ar[0][2])/ar[1][2];
    int l=0, r=1e9+10;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        if(1ll*mid*mid<=x) l=mid;
        else r=mid;
    }
    cout<<l<<" ";
    for(int a=1; a<n; a++) cout<<ar[0][a]/l<<" ";
}