#include <bits/stdc++.h>
#define double long double
using namespace std;
const double inf=1e15;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int po[n][2], fop=0, foo=0, nq=0;
    for(int a=0; a<n; a++)
    {
        scanf("%d%d", &po[a][0], &po[a][1]);
        if(po[a][1]>0) fop=1;
        if(po[a][1]<0) foo=1;
        if(po[a][1]==0) nq++;
    }
    if((fop and foo) or (nq>1)) cout<<-1;
    else
    {
        for(int a=0; a<n; a++) if(po[a][1]<0) po[a][1]*=-1;

        double l=0, r=inf;
        for(int i=0; i<100; i++)
        {
            double ra=(l+r)/2, lg=-inf, rg=inf;
            bool ok=1;
            for(int a=0; a<n; a++)
            {
                int x=po[a][0], y=po[a][1];
                if(abs(ra-y)>ra) ok=0;
                else
                {
                    double dx=sqrt(2*y*ra-1.0*y*y);
                    //double dx=sqrt(ra*ra-(ra-y)*(ra-y));
                    lg=max(lg, x-dx), rg=min(rg, x+dx);
                }
            }
            if(ok and lg<rg) r=ra;
            else l=ra;
        }

        cout<<fixed<<setprecision(10)<<r;
    }
}