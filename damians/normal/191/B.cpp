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
#define un(v) v.erase(unique(ALL(v)),v.end())
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

ll a[1000001];
ll best[1000001];
ll b;

int main()
{
    ios_base::sync_with_stdio(0);
    int n,k;cin>>n>>k;
    cin>>b;
    FOR(i,n) cin>>a[i];
    vector<pair<ll,int> > v;
    v.pb(mp(0,n));
    FOR(i,n-1) v.pb(mp(a[i],i));
    sort(ALL(v));
    reverse(ALL(v));
    ll sum=0;
    FOR(i,k) sum+=v[i].fi;
    FOR(i,n-1)
    {
        if (i<k)
        {
            best[v[i].se]=sum;
        }
        else
        {
            best[v[i].se]=sum-v[k-1].fi+v[i].fi;
        }
    }
    
    best[n-1]=b+2;
   // FOR(i,n) DBG(best[i]);
    FOR(i,n)
    {
        if (best[i]>b)
        {
            cout<<i+1;
            return 0;
        }
    }
    
    

    return 0;
}