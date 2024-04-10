#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 i128;
typedef long double ld;

struct line
{
    ll k,n;
    mutable ll r;
    line(ll a,ll b):k(a),n(b){r=0;}
    bool operator<(const line &o)const{return (k<o.k);}
    bool operator<(ll o)const{return (r<o);}
};

struct cht
{
    set<line,less<>> s;
    const ll inf=(1ll<<60);
    ld intersect(line a,line b){return ((ld)b.n-a.n)/(a.k-b.k);}
    bool bad(line a,line b,line c){return (intersect(a,b)>intersect(b,c));}
    void add(ll k,ll n)
    {
        line now(k,n);
        auto it=s.lower_bound(now);
        if(it!=s.end()&&(it->k)==k)
        {
            if(it->n<n) it=s.erase(it);
            else return;
        }
        if(it!=s.begin()&&it!=s.end()&&bad(*prev(it),now,*it)) return;
        s.insert(now);
        while(it!=s.end()&&next(it)!=s.end()&&bad(now,*it,*next(it))) it=s.erase(it);
        it--;
        while(it!=s.begin()&&prev(it)!=s.begin()&&bad(*prev(prev(it)),*prev(it),now)) s.erase(prev(it));
        if(it!=s.begin()) prev(it)->r=floor(intersect(*prev(it),now));
        if(next(it)!=s.end()) it->r=floor(intersect(now,*next(it)));
        else it->r=inf;
    }
    i128 query(ll a)
    {
        line best=(*s.lower_bound(a));
        return ((i128)best.k*a+best.n);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll s;
    cin >> n >> s;
    vector<array<ll,2>> v(n);
    for(int i=0;i<n;i++) cin >> v[i][1] >> v[i][0];
    sort(v.begin(),v.end(),[](const array<ll,2> &a,const array<ll,2> &b){return (a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]));});
    vector<array<ll,2>> tmp;
    ll mx=0;
    for(array<ll,2> a:v)
    {
        if(a[1]>mx)
        {
            tmp.push_back(a);
            mx=a[1];
        }
    }
    v=tmp;
    cht opt;
    opt.add(0,0);
    for(auto [cost,val]:v)
    {
        ll l=-1,r=cost;
        while(l<r-1)
        {
            ll m=(l+r)/2;
            if(opt.query(m)>=cost) r=m;
            else l=m;
        }
        ll now=opt.query(r);
        opt.add(val,now-cost-r*val);
    }
    ll l=0;
    ll r=s;
    while(l<r-1)
    {
        ll m=(l+r)/2;
        if(opt.query(m)>=s) r=m;
        else l=m;
    }
    cout << r << "\n";
    return 0;
}