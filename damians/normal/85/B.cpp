#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <map>
#include <queue>
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
typedef pair<ll,ll> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

ll ile[3];
ll czas[3];
set<pii> st;
multiset<ll> s[3];

ll osoba[200000];
ll t[200000];

int main()
{
    ios_base::sync_with_stdio(0);
    FOR(i,200000) osoba[i]=0;
    FOR(i,3) 
        cin>>ile[i];
    FOR(i,3) cin>>czas[i];
    int n;cin>>n;
    FOR(i,n)
    {
        int a;
        cin>>t[i];
        osoba[i]=0;
        st.insert(mp(t[i],i));
    }
    FOR(i,3)
    {
        FOR(j,min((ll)n,ile[i])) s[i].insert(0);
    }
    pii p;
    ll best=0;
    while(!st.empty())
    {
        p=*(st.begin());
        st.erase(st.begin());
        int ktora=p.se;
        int lol=osoba[ktora];
        if (osoba[ktora]==3)
        {
            best=max(best,p.fi)-t[ktora];;
            continue;
        }
        else
        {
            ll go=*(s[osoba[ktora]].begin());
            s[osoba[ktora]].erase(s[osoba[ktora]].begin());
            s[lol].insert(max(go,p.fi)+czas[lol]);
            osoba[ktora]++;
            st.insert(mp(max(go,p.fi)+czas[lol],ktora));
        }
    }
    cout<<best;

    return 0;
}