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
#define LOLDBG1
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
vector<pair<int,string> > v;
string s;
int n,k;


void go(int x)
{
    string h=s;
    vector<pii> g;
    REP(c,0,9) g.pb(mp(abs(x-c),-c));
    sort(ALL(g));
    if (x==8) DBG(g);
    int ile=0;
    int wyn=0;
    FOR(j,g.sz)
    {
        if (x==8) DBG(mp(ile,wyn));
        int f=-g[j].se;
        if (ile>=k) continue;
        if (f<x) reverse(ALL(h));
        FOR(i,h.sz)
        {
            if (ile<k && h[i]==f)
            {
                h[i]=x;
                ile++;
                wyn+=abs(f-x);
            }
        }
        if (f<x) reverse(ALL(h));
    }
    FOR(j,h.sz) h[j]+='0';
    v.pb(mp(wyn,h));
}


int main()
{
    ios_base::sync_with_stdio(0);
    
    cin>>n>>k;
    cin>>s;
    FOR(i,s.sz) s[i]-='0';
    FOR(i,10) go(i);
    sort(ALL(v));
    DBG(v);
    cout<<v[0].fi<<"\n";
    cout<<v[0].se;

    return 0;
}