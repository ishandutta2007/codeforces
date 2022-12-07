#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ara[n], arb[n];
    for(int a=0; a<n; a++) scanf("%d", &ara[a]);
    for(int a=0; a<n; a++) scanf("%d", &arb[a]);
    double l=0, r=2e9;
    bool fo=0;
    for(int i=0; i<100; i++)
    {
        double mid=(l+r)/2;
        double cu=mid;
        bool ok=1;
        for(int a=0; a<n; a++)
        {
            double q=(cu+m)/ara[a];
            if(q>cu)
            {
                ok=0;
                break;
            }
            else cu-=q;

            q=(cu+m)/arb[(a+1)%n];
            if(q>cu)
            {
                ok=0;
                break;
            }
            else cu-=q;
        }
        if(ok)
        {
            fo=1, r=mid;
        }
        else l=mid;
    }
    if(fo) cout<<fixed<<setprecision(10)<<r;
    else cout<<-1;
}