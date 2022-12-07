#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10;
int c[sz], an[sz];
vector <pair <int, int> > sp;
set <int> us;
map <int, int> se;
multiset <int, greater <int> > be;
void add(int l, int r)
{
    se[l]=r-l;
    be.insert(r-l);
    sp.push_back({l, r});
}
void ins(int p)
{
    auto it=se.upper_bound(p);
    int l=0, r=0;
    if(it!=se.end())
    {
        if((*it).first==p+1) r=(*it).second;
    }
    if(it!=se.begin())
    {
        it--;
        if((*it).first+(*it).second==p) l=(*it).second;
    }
    if(l)
    {
        be.erase(be.find(l));
        se.erase(p-l);
    }
    if(r)
    {
        be.erase(be.find(r));
        se.erase(p+1);
    }
    add(p-l, p+1+r);
}
void del(int p)
{
    auto it=se.upper_bound(p);
    it--;
    int l=(*it).first, r=l+(*it).second;
    be.erase(be.find(r-l));
    se.erase(it);

    if(l<p) add(l, p);
    if(r>p+1) add(p+1, r);
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    pair <int, int> ar[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a].first);
        ar[a].second=a;
        us.insert(us.end(), a);
    }
    sort(ar, ar+n);
    reverse(ar, ar+n);
    int yk=0, ma=0;
    while(yk<n)
    {
        int x=ar[yk].first;
        while(yk<n and ar[yk].first==x)
        {
            int i=ar[yk].second, q=0;
            c[i]=1;
            if(i)
            {
                if(c[i-1]) del(i-1), q++;
                else ins(i-1);
            }
            else q++;

            if(i+1<n)
            {
                if(c[i+1]) del(i), q++;
                else ins(i);
            }
            else q++;

            if(q)
            {
                if(i and c[i-1]) an[i-1]=max(an[i-1], x);
                an[i]=max(an[i], x);
                if(i+1<n and c[i+1]) an[i+1]=max(an[i+1], x);
            }
            yk++;
        }

        if(be.size()) ma=max(ma, (*be.begin())>>1);

        for(int a=0; a<sp.size(); a++)
        {
            int l=sp[a].first, r=sp[a].second;
            auto it=se.find(l);
            if(it!=se.end() and (*it).second==r-l)
            {
                if(c[l] and c[r]) l++;
                else if(c[l]) l++, r=(l+r)>>1;
                else if(c[r]) l++, l=(l+r)>>1;
                else l=1e9;

                auto it=us.lower_bound(l);
                while(it!=us.end() and (*it)<r)
                {
                    an[*it]=max(an[*it], x);
                    auto it2=it++;
                    us.erase(it2);
                }
            }
        }
        sp.clear();
    }
    cout<<ma<<"\n";
    for(int a=0; a<n; a++) printf("%d ", an[a]);
}