#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll inf=(1ll<<60);

struct line
{
    ll k,n;
    mutable ll r;
    line(ll a,ll b,ll c){k=a;n=b;r=c;}
};

bool operator<(const line &a,const line &b){return a.k>b.k;}
bool operator<(const line &a,const ll &b){return a.r<b;}

double intersect(line a,line b){return (((double)b.n-a.n)/(a.k-b.k));}

struct cht
{
    set<line,less<>> s;
    void upd(set<line>::iterator it,ll nr){it->r=nr;}
    void add(ll k,ll n)
    {
        line now(k,n,0);
        auto it=s.lower_bound(now);
        if(it!=s.end()&&it->k==k)
        {
            if(it->n>n) it=s.erase(it);
            else return;
        }
        if(it!=s.end()&&it!=s.begin()&&intersect(*prev(it),now)>intersect(now,*it)) return;
        s.insert(now);
        while(it!=s.end()&&next(it)!=s.end()&&intersect(now,*it)>intersect(*it,*next(it))) it=s.erase(it);
        it--;
        while(it!=s.begin()&&prev(it)!=s.begin()&&intersect(now,*prev(it))<intersect(*prev(it),*prev(prev(it)))) s.erase(prev(it));
        if(it!=s.begin()) upd(prev(it),floor(intersect(*prev(it),*it)));
        if(next(it)!=s.end()) upd(it,floor(intersect(*it,*next(it))));
        else upd(it,inf);
    }
    ll query(ll a)
    {
        line best=*s.lower_bound(a);
        return (best.k*a+best.n);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,p;
    cin >> n >> m >> p;
    vector<ll> d(n+1,0);
    for(int i=2;i<=n;i++)
    {
        cin >> d[i];
        d[i]+=d[i-1];
    }
    vector<ll> x(m+1,0);
    for(int i=1;i<=m;i++)
    {
        int h,t;
        cin >> h >> t;
        x[i]=t-d[h];
    }
    sort(x.begin()+1,x.end());
    vector<ll> sum(m+1,0);
    for(int i=1;i<=m;i++) sum[i]=sum[i-1]+x[i];
    vector<ll> now(m+1,inf);
    while(p--)
    {
        vector<ll> nxt(m+1,inf);
        cht c;
        c.add(0,0);
        for(int i=1;i<=m;i++)
        {
            nxt[i]=i*x[i]-sum[i]+c.query(x[i]);
            c.add(-i,now[i]+sum[i]);
        }
        now=nxt;
    }
    cout << now[m] << "\n";
    return 0;
}