#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2.2e3+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<pip> wals;
    for(int i=0;i<m;i++)
    {
        int l,r,t;
        cin >> l >> r >> t;
        r--;
        wals.push_back(pip(t,pii(l,r)));
    }

    vector<pii> qs;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        qs.push_back(pii(x,i));
    }

    sort(all(qs));

    vector<pii> evs;
    for(int i=0;i<m;i++)
    {
        evs.push_back(pii(wals[i].s.f,i+1));
        evs.push_back(pii(wals[i].s.s+1,-(i+1)));
    }

    sort(all(evs));

    vector<pii> intervals;
    ll last=-2e9;
    set<pii> kks;
    vector<pii> ev2;
    for(auto p : evs)
    {
        int t=p.f;
        int id=p.s;
        if(t>last && !kks.empty())
        {
            int l=last;
            int r=t-1;
            ll tim=(*kks.begin()).f;
            intervals.push_back(pii(tim-r,tim-l));
            ev2.push_back(pii(tim-r,1));
            ev2.push_back(pii(tim-l+1,-1));
//            cout << tim-r << ' ' << 1 << '\n';
//            cout << tim-l+1 << ' ' << -1 << '\n';
        }
        if(id<0)
        {
            id=-id;
            id--;
            kks.erase(pii(wals[id].f,id));
        }
        else
        {
            id--;
            kks.insert(pii(wals[id].f,id));
        }
        last=t;
    }

    sort(all(ev2));

    vector<ll> ans(n);
    ll act=0;
    last=-2e9;
    ll sum=0;
    int pos=0;
    for(int i=0;i<n;i++)
    {
        ll t=qs[i].f;
        while(pos<ev2.size() && ev2[pos].f<=t)
        {
            ll t2=ev2[pos].f;
            if(t2!=last)
                act+=sum*(t2-last);
            last=t2;
            sum+=ev2[pos].s;
            pos++;
        }
        act+=sum*(t+1-last);
        last=t+1;
        ans[qs[i].s]=act;
    }

    for(int i=0;i<n;i++)
        db(ans[i])

    return 0;
}