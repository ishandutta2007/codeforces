#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll inf=(1ll<<60);

struct line
{
    ll k,n,r;
    line(ll a,ll b,ll c){k=a;n=b;r=c;}
};

bool operator<(const line &a,const line &b){return a.k<b.k;}
bool operator<(const line &a,const ll &b){return a.r<b;}

ld intersect(line a,line b)
{
    assert(a.k!=b.k);
    return ((ld)b.n-a.n)/(a.k-b.k);
}

struct cht
{
    set<line,less<>> s;
    void upd(line a,ll nr)
    {
        s.erase(a);
        a.r=nr;
        s.insert(a);
    }
    void updr(set<line>::iterator it)
    {
        if(it!=s.begin())
        {
            line tmp=*it;
            it--;
            upd(*it,floor(intersect(tmp,*it)));
        }
    }
    void add(ll k,ll n)
    {
        line now(k,n,0);
        auto it=s.lower_bound(now);
        if(it!=s.end()&&it->k==k)
        {
            if(n<=it->n) return;
            else
            {
                it=s.erase(it);
                updr(it);
            }
        }
        if(it!=s.end()&&it!=s.begin()&&intersect(*prev(it),now)>intersect(*it,now)) return;
        it=s.insert(now).first;
        it++;
        while(it!=s.end()&&next(it)!=s.end()&&intersect(now,*it)>=intersect(*it,*next(it))) it=s.erase(it);
        it--;
        while(it!=s.begin()&&prev(it)!=s.begin()&&intersect(now,*prev(it))<=intersect(*prev(it),*prev(prev(it)))) it=s.erase(prev(it));
        updr(it);
        if(next(it)!=s.end()) upd(now,floor(intersect(now,*next(it))));
        else upd(now,inf);
    }
    ll query(ll a)
    {
        auto it=s.lower_bound(a);
        ll k=it->k;
        ll n=it->n;
        return k*a+n;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n+1,0);
    vector<ll> sum(n+1,0);
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        sum[i]=sum[i-1]+a[i];
        res+=(i*a[i]);
    }
    ll d=0;
    cht c1;
    for(ll i=1;i<=n;i++)
    {
        c1.add(i,-sum[i-1]);
        d=max(d,sum[i-1]-i*a[i]+c1.query(a[i]));
    }
    cht c2;
    for(ll i=n;i>=1;i--)
    {
        c2.add(i,-sum[i]);
        d=max(d,sum[i]-i*a[i]+c2.query(a[i]));
    }
    cout << res+d << "\n";
    return 0;
}