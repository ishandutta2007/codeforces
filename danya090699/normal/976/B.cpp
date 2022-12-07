#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n, m, k;
    cin>>n>>m>>k;
    if(k<n) cout<<k+1<<" "<<1;
    else
    {
        int l=(k-n)/(m-1), p=(k-n)%(m-1);
        cout<<n-l<<" ";
        if(l%2==0) cout<<p+2;
        else cout<<m-p;
    }
}