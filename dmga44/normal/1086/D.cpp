#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(1e4+5)

struct aux{
    set<int> s;
    vector<int> abi;
    int maxn;
    aux(int n) : abi(n+1),maxn(n+1){}

    void update(int p,int v)
    {
        while(p<maxn)
        {
            abi[p]+=v;
            p+=(p&-p);
        }
    }

    int query(int p)
    {
        int res=0;
        while(p)
        {
            res+=abi[p];
            p-=(p&-p);
        }
        return res;
    }

    void insert(int pos)
    {
        update(pos,1);
        s.insert(pos);
    }

    void erase(int pos)
    {
        update(pos,-1);
        s.erase(pos);
    }

    pii info()
    {
        if(s.empty())
            return pii(-1,-1);
        auto it=s.end();
        it--;
        return pii(*s.begin(),*it);
    }

    int interval(int l,int r)
    {
        return query(r)-query(l-1);
    }
};

int trans(char x)
{
    if(x=='P')
        return 0;
    if(x=='R')
        return 1;
    return 2;
}

int solve1(aux& p,aux& r,aux& s)
{
    pii malos=s.info();
    pii buenos=r.info();
//    cout << malos.f << ' ' << malos.s << '\n';
//    cout << buenos.f << ' ' << buenos.s << '\n';
    if(malos.f==-1)
        return 0;
    if(buenos.f==-1)
        return p.s.size();
    ll res=0;
    if(malos.f<buenos.f)
        res+=p.interval(malos.f,buenos.f);
    if(malos.s>buenos.s)
        res+=p.interval(buenos.s,malos.s);
    return res;
}

void solve(vector<aux>& m)
{
    ll res=m[0].maxn-1;
    for(int i=0;i<3;i++)
        res-=solve1(m[i],m[(i+1)%3],m[(i+2)%3]);
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    ///paper-0
    ///rock-1
    ///scissors-2
    vector<aux> m(3,aux(n));
    for(int i=0;i<n;i++)
        m[trans(s[i])].insert(i+1);

    solve(m);

    while(q--)
    {
        int p;
        char t;
        cin >> p >> t;
        p--;
        m[trans(s[p])].erase(p+1);
        s[p]=t;
        m[trans(s[p])].insert(p+1);

        solve(m);
//        db(s)
//        db("")
    }

    return 0;
}