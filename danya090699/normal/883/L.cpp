#include <bits/stdc++.h>
#define int long long
#define iter set <int, int>::iterator
using namespace std;
const int inf=1e9;
int mo(int x)
{
    if(x<0) return -x;
    else return x;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, m;
    cin>>n>>k>>m;
    set <int> pos;
    set <pair <int, int> > av[n];
    set <pair <int, pair <int, int> > > ocu;
    for(int a=0; a<k; a++)
    {
        int x;
        scanf("%lld", &x);
        x--;
        pos.insert(x), av[x].insert(make_pair(0, a));
    }
    for(int a=0; a<m; a++)
    {
        int t, fr, to, ti;
        scanf("%lld%lld%lld", &t, &fr, &to);
        fr--, to--;
        ti=t;
        if(pos.size()==0)
        {
            if((*ocu.begin()).first>t) ti=(*ocu.begin()).first;
        }
        while(ocu.size()>0)
        {
            int cut=(*ocu.begin()).first;
            if(cut>ti) break;
            int nu=(*ocu.begin()).second.first, ho=(*ocu.begin()).second.second;
            pos.insert(ho), av[ho].insert(make_pair(cut, nu));
            ocu.erase(ocu.begin());
        }
        int l=-inf, r=inf;
        iter it=pos.lower_bound(fr);
        if(it!=pos.end()) r=*it;
        if(it!=pos.begin())
        {
            it--, l=*it;
        }
        if(fr-l==r-fr)
        {
            if((*av[l].begin())<(*av[r].begin())) r=inf;
            else l=-inf;
        }
        int ho=l;
        if(fr-l>r-fr) ho=r;
        int nu=(*av[ho].begin()).second;
        ti=(*av[ho].begin()).first;
        if(ti<t) ti=t;
        int get=ti+mo(fr-ho);
        printf("%lld %lld\n", nu+1, get-t);
        av[ho].erase(av[ho].begin());
        if(av[ho].size()==0) pos.erase(ho);
        ocu.insert(make_pair(get+mo(fr-to), make_pair(nu, to)));
    }
}