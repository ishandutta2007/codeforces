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
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cout<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define ALL(x) (x).begin(),(x).end()
#define INF 100000000
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }


vector<int> KUPA(string pat, string tar)
{
    vector<int> macz;
    int n=pat.sz;
    int m=tar.sz;
    FOR(i,m)
    {
        if (i+n>m) break;
        bool ok=1;
        FOR(j,n)
        {
            if (pat[j]!=tar[i+j])
            {
                ok=0;
                break;
            }
        }
        if (ok) macz.pb(i);
    }
    return macz;
}
string tab[11];
vector<pii> v;

int main()
{
    ios_base::sync_with_stdio(0);
    string s;
    cin>>s;
    int k;
    int n=s.sz;
    cin>>k;
    FOR(i,k) cin>>tab[i];

    FOR(i,k)
    {
        vi u=KUPA(tab[i],s);
        DBG(u);
        FOR(j,u.sz)
        {
            v.pb(mp(u[j],tab[i].sz));
        }
    }
    v.pb(mp(n,1));
    sort(ALL(v));
    v=vector<pii>(v.begin(),unique(ALL(v)));
    DBG(v);vector<pii>::iterator it;
    int mx=-1;
    int pos=0;
    FOR(i,n)
    {
        int dl=INF;
        it=upper_bound(ALL(v),mp(i,-1));
        REP(ssf,1,100)
        {
            if (it==v.end()) break;
            dl=min(dl,(it->fi)+(it->se)-1-i);
            it++;
        }
        
        if (dl>mx)
        {
            mx=dl;
            pos=i;
        }
    }
    cout<<mx<<" "<<pos<<endl;
    

    return 0;
}