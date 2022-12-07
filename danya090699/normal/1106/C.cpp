#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    sort(ar, ar+n);
    for(int a=0; a<n/2; a++) an+=(ar[a]+ar[n-1-a])*(ar[a]+ar[n-1-a]);
    cout<<an;
}