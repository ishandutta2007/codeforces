#include <bits/stdc++.h>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define LOLDBG
#ifdef LOLDBG
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cout<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define ALL(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

const int mxn=111111;

int a[mxn];
int b[mxn];
ll res[mxn];
int inv[mxn];
int outv[mxn];
int timer=0;
vi kr[mxn];




const ll is_query = -(1LL << 62);

struct Line {
    ll m, b;
    mutable function<const Line *()> succ;

    bool operator<(const Line &rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line *s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};

struct HullDynamic : public multiset<Line> {
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return (x->b - y->b) * (long double) (z->m - y->m) >= (y->b - z->b) * (long double) (y->m - x->m);
    }

    void insert_line(ll m, ll b) {
        auto y = insert({m, b});
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) {
            erase(y);
            return;
        }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }

    ll eval(ll x) {
        auto l = *lower_bound((Line) {x, is_query});
        return l.m * x + l.b;
    }
};
int ssz[mxn];
int inu[mxn];
int outu[mxn];
HullDynamic h[mxn];
int where[mxn];
int ren[mxn];
void dfs(int u,int p)
{
    ssz[u]=1;
    inu[u]=timer++;
   // DBG(mp(u,inu[u]))
    ren[inu[u]]=u;
    int bg=-1;
    for(auto v: kr[u])
    {
        if (v!=p)
        {
            dfs(v,u);
            ssz[u]+=ssz[v];
            if (bg==-1 || ssz[v]>ssz[bg]) bg=v;
        }
    }
    outu[u]=timer;
    if (bg==-1)
    {
        res[u]=0;
        where[u]=u;
        h[u].insert_line(-b[u],0);
    }
    else
    {
        where[u]=where[bg];
        for(auto v: kr[u])
        {
            if (v!=p && v!=bg) REP(j,inu[v],outu[v]-1)
            {
                //DBG(v);
                //DBG(ren[j]);
                //DBG(mp(-b[ren[j]],-res[ren[j]]));
                //DBG(where[bg]);
                //DBG(mp(-b[ren[j]],-res[ren[j]]));
                h[where[bg]].insert_line(-b[ren[j]],-res[ren[j]]);
            }
        }
        //DBG(u);
        //DBG(h[where[u]].eval(a[u]));
        res[u]=-h[where[u]].eval(a[u]);
        h[where[u]].insert_line(-b[u],-res[u]);
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    FOR(i,n) cin>>a[i];
    FOR(i,n) cin>>b[i];
    FOR(i,n-1)
    {
        int x,y;cin>>x>>y;
        x--;y--;
        kr[x].pb(y);
        kr[y].pb(x);
    }
    dfs(0,-1);
    FOR(i,n) cout<<res[i]<<" ";

    return 0;
}