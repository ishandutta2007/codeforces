#include <bits/stdc++.h>
#define iter map <int, pair <int, int> >::iterator
using namespace std;
bool comp(pair <int, int> a, pair <int, int> b)
{
    if(a.first!=b.first) return a.first>b.first;
    else return a.second<b.second;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    int ar[n];
    map <int, pair <int, int> > ma;
    set <pair <int, int>, bool(*)(pair <int, int>, pair <int, int>)> se(comp);
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    int yk=0;
    while(yk<n)
    {
        int cu=ar[yk], st=yk;
        while(yk<n)
        {
            if(cu==ar[yk]) yk++;
            else break;
        }
        ma[st]=make_pair(yk-st, cu);
        se.insert(make_pair(yk-st, st));
    }
    while(se.size())
    {
        an++;
        int nu=(*se.begin()).second;
        se.erase(se.begin());
        iter it=ma.find(nu);
        iter l=it, r=it;
        if(it!=ma.begin()) l--;
        r++;
        if(!(l==it or r==ma.end()))
        {
            int grl=(*l).first, ql=(*l).second.first, cl=(*l).second.second, grr=(*r).first, qr=(*r).second.first, cr=(*r).second.second;
            if(cl==cr)
            {
                ma.erase(l), ma.erase(r), ma[grl]=make_pair(ql+qr, cl);
                se.erase(make_pair(ql, grl)), se.erase(make_pair(qr, grr)), se.insert(make_pair(ql+qr, grl));
            }
        }
        ma.erase(it);
    }
    cout<<an;
}