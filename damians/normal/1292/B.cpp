#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define pb push_back
#define sz(x) (int)(x).size()
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
#define un(x) x.erase(unique(ALL(x)),x.end());
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }


ll di(pair<ll,ll> A, pair<ll,ll> B)
{
    return abs(A.fi-B.fi)+abs(A.se-B.se);
}

int main()
{
    ios_base::sync_with_stdio(0);
    ll inf=1e16+10;
    ll x0,y0;cin>>x0>>y0;
    ll ax,ay,bx,by;
    cin>>ax>>ay>>bx>>by;
    ll xs,ys,t;
    cin>>xs>>ys>>t;
    vector<pair<ll,ll>> p;
    p.pb({x0,y0});
    while(1)
    {
        if (p.back().fi>inf || p.back().se>inf) break;
        ll X=p.back().fi, Y=p.back().se;
        pair<ll, ll> u=mp(X*ax+bx, Y*ay+by);
        p.pb(u);
    }
    int be=0;
    REP(s,0,sz(p)-1)
    {
        REP(l,0,s)REP(r,s,sz(p)-1)
        {
            vi v;
            v.pb(s);
            while(v.back()>l)
            {
                v.pb(v.back()-1);
            }
            while(v.back()<r)
            {
                v.pb(v.back()+1);
            }
            ll dis=0;
            vi odw(sz(p),0);
            int vis=0;
            pair<ll, ll> w(xs,ys);
            FOR(k,sz(v))
            {
                if (dis+di(w,p[v[k]])<=t)
                {
                    vis+=1-odw[v[k]];
                    odw[v[k]]=1;
                    dis+=di(w,p[v[k]]);
                    w=p[v[k]];
                }
                else break;
            }
            be=max(be,vis);
        }


        REP(l,0,s)REP(r,s,sz(p)-1)
        {
            vi v;
            v.pb(s);
            while(v.back()<r)
            {
                v.pb(v.back()+1);
            }
            while(v.back()>l)
            {
                v.pb(v.back()-1);
            }
            ll dis=0;
            vi odw(sz(p),0);
            int vis=0;
            pair<ll, ll> w(xs,ys);
            FOR(k,sz(v))
            {
                if (dis+di(w,p[v[k]])<=t)
                {
                    vis+=1-odw[v[k]];
                    odw[v[k]]=1;
                    dis+=di(w,p[v[k]]);
                    w=p[v[k]];
                }
                else break;
            }
            be=max(be,vis);
        }
    }
    cout<<be;

    return 0;
}