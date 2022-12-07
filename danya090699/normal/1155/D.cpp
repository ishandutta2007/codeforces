#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n, x;
    cin>>n>>x;
    int ar[n], r[n+1];
    for(int a=0; a<n; a++) scanf("%lld", &ar[a]);

    r[n]=0;
    int su=0, mi=0;
    for(int a=n-1; a>=0; a--)
    {
        su+=ar[a], mi=min(mi, su);
        r[a]=su-mi;
    }

    su=0, mi=0;
    int su2=0, mi2=0, an=r[0];
    for(int a=0; a<n; a++)
    {
        su2+=ar[a], mi2=min(mi2, su2);

        su+=ar[a]*x;
        mi=min(mi, su-(su2-mi2));

        an=max(an, su-mi+r[a+1]);
    }
    cout<<an;
}