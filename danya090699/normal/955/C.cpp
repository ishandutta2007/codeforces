#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e6+10, inf=1e18+10;
int sq(int x)
{
    int l=0, r=1e9+10;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        if(mid*mid<=x) l=mid;
        else r=mid;
    }
    return l;
}
vector <int> sp2, sp;
int f(int x)
{
    int re=sq(x);
    re+=(upper_bound(sp.begin(), sp.end(), x)-sp.begin());
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    for(int a=2; a<sz; a++)
    {
        int x=a;
        for(int b=1; ; b++)
        {
            if(b>2)
            {
                int y=sq(x);
                if(y*y<x) sp2.push_back(x);
            }
            if(inf/x<a) break;
            x*=a;
        }
    }
    sort(sp2.begin(), sp2.end());
    for(int a=0; a<sp2.size(); a++)
    {
        if(sp.size())
        {
            if(sp.back()!=sp2[a]) sp.push_back(sp2[a]);
        }
        else sp.push_back(sp2[a]);
    }
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int l, r;
        scanf("%lld%lld", &l, &r);
        printf("%lld\n", f(r)-f(l-1));
    }
}