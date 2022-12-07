#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q=0;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        q+=x;
    }
    for(int a=0; a<n; a++) cin>>ar[a];
    sort(ar, ar+n);
    if(ar[n-1]+ar[n-2]>=q) cout<<"YES";
    else cout<<"NO";
}