#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, v, v1;
    cin>>n>>v>>v1;
    int ar[n], su=0;
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &ar[a]);
        su+=ar[a];
    }
    sort(ar+1, ar+n);
    for(int a=n; a>0; a--)
    {
        if(ar[0]*v>=v1*su)
        {
            cout<<n-a;
            break;
        }
        su-=ar[a-1];
    }
}