#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FORE(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REMIN(x,y) (x)=min((x),(y))
#define REMAX(x,y) (x)=max((x),(y))
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define LOLDBG
#ifdef LOLDBG
#define DBG(vari) cerr<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cerr<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define CZ3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z));
#define ALL(x) (x).begin(),(x).end()
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define testss int dsdsf;CZ(dsdsf);while(dsdsf--)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

vector<ll> lc;

int main()
{
    ios_base::sync_with_stdio(0);
    cout<<setprecision(13)<<fixed;
    REP(i,1,10)
    {
        FOR(j,(1<<i))
        {
            ll num=0;
            FOR(k,i)
            {
                if ((1<<k)&j) num=num*10+4;
                else num=num*10+7;
            }
            lc.pb(num);
        }
    }
    lc.pb(0);
    sort(ALL(lc));
    DBG(lc.sz);
    vector<ll> p(2),v(2);
    ll k;
    cin>>p[0]>>p[1];
    cin>>v[0]>>v[1];
    cin>>k;
    double wyn=0.0;
    ll w,e,ile1,ile2;
    //DBG(k);
    for(int i=0;;i++)
    {
        if (lc[i+k]>1000000000) break;
        w=max(lc[i]+1,p[0]);
        e=min(lc[i+1],p[1]);
        //DBG2(e,w);
        ile1=e-w+1;
        w=max(lc[i+k],v[0]);
        e=min(lc[i+k+1]-1,v[1]);
        //DBG2(e,w);
        ile2=e-w+1;
        if (ile1>0 && ile2>0) wyn+=(ile1*1.0*ile2);
        swap(v,p);
        w=max(lc[i]+1,p[0]);
        e=min(lc[i+1],p[1]);
        ile1=e-w+1;
        w=max(lc[i+k],v[0]);
        e=min(lc[i+k+1]-1,v[1]);
        ile2=e-w+1;
        if (ile1>0 && ile2>0) wyn+=(ile1*1.0*ile2);
        swap(v,p);
        //DBG(wyn);
    }
    if (k==1)
    {
        FOR(j,lc.sz)
        {
            if (p[0]<=lc[j] && lc[j]<=p[1] && v[0]<=lc[j] && lc[j]<=v[1]) wyn-=1.0;
        }
    }
    cout<<wyn/((p[1]-p[0]+1)*1.0*(v[1]-v[0]+1));

    return 0;
}