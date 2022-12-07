#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int main()
{
    //freopen("input.txt", "r", stdin);
    int xl=inf, xr=-inf, yl=inf, yr=-inf;
    for(int a=0; a<4; a++)
    {
        int x, y;
        cin>>x>>y;
        xl=min(xl, x), xr=max(xr, x);
        yl=min(yl, y), yr=max(yr, y);
    }
    int xl2=inf, xr2=-inf, yl2=inf, yr2=-inf;
    for(int a=0; a<4; a++)
    {
        int x, y;
        cin>>x>>y;
        xl2=min(xl2, x), xr2=max(xr2, x);
        yl2=min(yl2, y), yr2=max(yr2, y);
    }
    int cx=(xl2+xr2)/2, cy=(yl2+yr2)/2, d=(xr2-xl2)/2, ok=0;
    for(int a=yr2; a>=yl2; a--)
    {
        for(int b=xl2; b<=xr2; b++)
        {
            //cout<<b<<" "<<a<<"\n";
            if(abs(a-cy)+abs(b-cx)<=d)
            {

                if(b>=xl and b<=xr and a>=yl and a<=yr)
                {
                    //cout<<b<<" "<<a<<"\n";
                    ok=1;
                }
            }
        }
    }
    if(ok) cout<<"YES";
    else cout<<"NO";
}