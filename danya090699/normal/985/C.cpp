#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, l;
    cin>>n>>k>>l;
    int m=n*k;
    int ar[m];
    for(int a=0; a<m; a++) cin>>ar[a];
    sort(ar, ar+m);
    int yk=m-1;
    while(yk>0)
    {
        if(ar[yk]>ar[0]+l) yk--;
        else break;
    }
    if(yk+1<n) cout<<0;
    else
    {
        int an=0;
        for(int a=n-1; a>=0; a--)
        {
            yk=min(yk, a*k), an+=ar[yk], yk--;
        }
        cout<<an;
    }
}