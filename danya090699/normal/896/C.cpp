#include <bits/stdc++.h>
#define iter map <int, pair <long long, int> >::iterator
using namespace std;
const int mod=1e9+7;
int n, m, seed, vmax;
int rnd()
{
    int ret=seed;
    seed=(1ll*seed*7+13)%mod;
    return ret;
}
int mod2;
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(1ll*re*x)%mod2;
        x=(1ll*x*x)%mod2;
        y>>=1;
    }
    return re;
}
map <int, pair <long long, int> > ma;
void cut(int l, int r)
{
    iter it=ma.upper_bound(l);
    it--;
    int lg=(*it).first, rg=(*it).second.second;
    long long va=(*it).second.first;
    if(lg<l)
    {
        (*it).second.second=l-1, it++;
        ma.insert(it, make_pair(l, make_pair(va, rg)));
    }
    it=ma.upper_bound(r), it--;
    lg=(*it).first, rg=(*it).second.second;
    va=(*it).second.first;
    if(rg>r)
    {
        (*it).second.second=r, it++;
        ma.insert(it, make_pair(r+1, make_pair(va, rg)));
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m>>seed>>vmax;
    for(int a=0; a<n; a++)
    {
        ma[a]=make_pair(rnd()%vmax+1, a);
    }
    for(int a=0; a<m; a++)
    {
        int ty=rnd()%4+1, l=rnd()%n, r=rnd()%n, x, y;
        if(l>r) swap(l, r);
        if(ty==3) x=rnd()%(r-l+1);
        else x=rnd()%vmax+1;
        if(ty==4) y=rnd()%vmax+1;
        cut(l, r);
        iter it=ma.lower_bound(l), en=ma.upper_bound(r);
        if(ty==1)
        {
            for(it; it!=en; it++) (*it).second.first+=x;
        }
        if(ty==2)
        {
            ma.erase(it, en);
            ma[l]=make_pair(x, r);
        }
        if(ty==3)
        {
            vector <pair <long long, int> > ve;
            for(it; it!=en; it++)
            {
                ve.push_back(make_pair((*it).second.first, (*it).second.second-(*it).first+1));
            }
            int q=0;
            sort(ve.begin(), ve.end());
            for(int b=0; b<ve.size(); b++)
            {
                q+=ve[b].second;
                if(q>x)
                {
                    printf("%lld\n", ve[b].first);
                    break;
                }
            }
        }
        if(ty==4)
        {
            int su=0;
            mod2=y;
            for(it; it!=en; it++)
            {
                int q=(*it).second.second-(*it).first+1;
                long long va=(*it).second.first;
                su=(su+1ll*q*po(va%mod2, x))%mod2;
            }
            printf("%d\n", su);
        }
    }
}