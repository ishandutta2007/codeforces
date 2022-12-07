#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n, f, an=0;
    cin>>n>>f;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        int k, l;
        cin>>k>>l;
        an+=min(k, l);
        k*=2;
        ar[a]=min(k, l)-min(k/2, l);
    }
    sort(ar, ar+n, greater <int>());
    for(int a=0; a<f; a++) an+=ar[a];
    cout<<an;
}