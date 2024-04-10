#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, s;
    cin>>n>>s;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    int l=-1, r=n+1, be;
    while(r-l>1)
    {
        int cu=(l+r)/2, su=0;
        int ar2[n];
        for(int a=0; a<n; a++) ar2[a]=ar[a]+(a+1)*cu;
        sort(ar2, ar2+n);
        for(int a=0; a<cu; a++) su+=ar2[a];
        if(su>s) r=cu;
        else
        {
            be=su, l=cu;
        }
    }
    cout<<l<<" "<<be;
}