//Come on, make Togliatti great again!
#include <bits/stdc++.h>
#define int long long
#define iter multiset <int>::iterator
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, p, q, rr, an=-5e18;
    cin>>n>>p>>q>>rr;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    multiset <int> l, r;
    l.insert(ar[0]);
    for(int a=0; a<n; a++) r.insert(ar[a]);
    for(int a=0; a<n; a++)
    {
        int cu=q*ar[a];
        iter it=l.begin();
        if(p>0)
        {
            it=l.end(), it--;
        }
        cu+=p*(*it);
        it=r.begin();
        if(rr>0)
        {
            it=r.end(), it--;
        }
        cu+=rr*(*it);
        an=max(an, cu);
        if(a!=n-1)
        {
            l.insert(ar[a+1]);
            r.erase(r.find(ar[a]));
        }
    }
    cout<<an;
}