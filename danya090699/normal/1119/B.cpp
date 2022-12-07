#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, h;
    cin>>n>>h;
    int bu[n];
    for(int a=0; a<n; a++) cin>>bu[a];
    for(int a=n; a>0; a--)
    {
        int ar[a];
        for(int b=0; b<a; b++) ar[b]=bu[b];
        sort(ar, ar+a, greater <int>());
        long long su=0;
        for(int b=0; b<a; b+=2) su+=ar[b];

        if(su<=h)
        {
            cout<<a;
            break;
        }
    }
}