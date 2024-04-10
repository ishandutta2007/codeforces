#include <bits/stdc++.h>
#define int long long
using namespace std;
struct li
{
    int k, b, l;
};
li nel;
vector <li> hull(1);
int de(int a, int b)
{
    int re=a/b;
    if(a%b!=0) re++;
    return re;
}
void add(int k, int b)
{
    while(1)
    {
        int k2=hull.back().k, b2=hull.back().b, l2=hull.back().l, l;
        if(b>=b2) l=de(b-b2, k2-k);
        else l=-((b2-b)/(k2-k));
        if(l<=l2) hull.pop_back();
        else
        {
            nel.k=k, nel.b=b, nel.l=l;
            hull.push_back(nel);
            break;
        }
    }
}
int que(int x)
{
    int l=0, r=hull.size();
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(x>=hull[mid].l) l=mid;
        else r=mid;
    }
    return x*hull[l].k+hull[l].b;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, inf=4e18;
    cin>>n;
    int h[n], pr[n];
    for(int a=0; a<n; a++) scanf("%lld", &h[a]);
    for(int a=0; a<n; a++) scanf("%lld", &pr[a]);
    if(n==1) cout<<0;
    else
    {
        hull[0].k=pr[0], hull[0].b=0, hull[0].l=-inf;
        for(int a=1; a<n; a++)
        {
            int an=que(h[a]);
            if(a==n-1) cout<<an;
            else add(pr[a], an);
        }
    }
}