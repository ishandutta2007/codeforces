#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k, an=0;
    cin>>n>>m>>k;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%lld", &ar[a]);
    for(int i=0; i<m; i++)
    {
        for(int a=i; a<n; a+=m) ar[a]-=k;
        int su=0, mi=4e18;
        for(int q=0; q<=n; q++)
        {
            //if(i==2) cout<<su<<" ";
            if(q%m==i) mi=min(mi, su);
            an=max(an, su-mi);
            if(q<n) su+=ar[q];
        }
        for(int a=i; a<n; a+=m) ar[a]+=k;
    }
    cout<<an;
}