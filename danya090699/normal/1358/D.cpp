#include <bits/stdc++.h>
#define int long long
using namespace std;
int f(int l, int r)
{
    return (l+r)*(r-l+1)/2;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, x;
    cin>>n>>x;
    int ar[n*2];
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &ar[a]);
        ar[a+n]=ar[a];
    }
    reverse(ar, ar+n*2);
    int q=0, su=0, yk=0, an=0;
    for(int a=0; a<n; a++)
    {
        while(q+ar[yk]<x)
        {
            q+=ar[yk], su+=f(1, ar[yk]), yk++;
        }

        an=max(an, su+f(ar[yk]-(x-q)+1, ar[yk]));

        if(q) q-=ar[a], su-=f(1, ar[a]);
        else yk++;
    }
    cout<<an;
}