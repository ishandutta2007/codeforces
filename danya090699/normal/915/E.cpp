#include <bits/stdc++.h>
#define iter map <int, pair <int, int> >::iterator
using namespace std;
map <int, pair <int, int> > ma;
void cut(int l)
{
    iter it=ma.upper_bound(l);
    it--;
    if((*it).first<l)
    {
        int lg=(*it).first, su=(*it).second.first, va=(*it).second.second;
        (*it).second.first=l-lg;
        ma[l]=make_pair(su-(l-lg), va);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int q, n, an;
    cin>>n>>q;
    an=n;
    ma[0]=make_pair(n, 1);
    for(int a=0; a<q; a++)
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        l--, r--, k--;
        cut(l);
        if(r+1<n) cut(r+1);
        iter st=ma.lower_bound(l), en=ma.lower_bound(r+1);
        for(iter it=st; it!=en; it++)
        {
            an-=(*it).second.first*(*it).second.second;
        }
        ma.erase(st, en);
        an+=(r-l+1)*k;
        ma[l]=make_pair(r-l+1, k);
        printf("%d\n", an);
    }
}