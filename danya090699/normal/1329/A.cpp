#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, su=0;
    cin>>n>>m;
    int ar[m];
    for(int a=0; a<m; a++)
    {
        scanf("%lld", &ar[a]);
        su+=ar[a];
    }
    if(su<n)
    {
        cout<<-1;
        return 0;
    }
    int l=0, an[m];
    for(int a=0; a<m; a++)
    {
        l=max(l+1, n-su+1);
        if(l+ar[a]-1>n)
        {
            cout<<-1;
            return 0;
        }
        an[a]=l;
        su-=ar[a];
    }
    for(int a=0; a<m; a++) printf("%lld ", an[a]);
}