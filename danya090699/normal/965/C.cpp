#include <bits/stdc++.h>
#define int long long
using namespace std;
int de(int x, int y){return x/y+(x%y>0);}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, m, d, an=0;
    cin>>n>>k>>m>>d;
    for(int a=1; a<=d; a++)
    {
        int l=0, r=2e18;
        while(r-l>1)
        {
            int mid=(l+r)>>1;
            int q=de(n/mid, k);
            if(q<a) r=mid;
            else l=mid;
        }
        int rg=l;
        l=0, r=2e18;
        while(r-l>1)
        {
            int mid=(l+r)>>1;
            int q=de(n/mid, k);
            if(q<=a) r=mid;
            else l=mid;
        }
        int lg=r;
        if(lg<=m) an=max(an, min(rg, m)*a);
    }
    cout<<an;
}