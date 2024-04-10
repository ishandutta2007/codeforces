#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n;
        cin>>n;
        int ar[n];
        for(int a=0; a<n; a++) cin>>ar[a];
        sort(ar, ar+n, greater <int>());
        for(int a=0; a<n; a++) cout<<ar[a]<<" ";
        cout<<"\n";
    }
}