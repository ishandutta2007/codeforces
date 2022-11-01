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
#include <complex>
#include <ctime>
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
#define MOD 1000000007
ll mpow(ll a, ll b)
{
    a=a%MOD;
    ll w=1;
    while(b)
    {
        if (b%2) w=(w*a)%MOD;
        a=(a*a)%MOD;
        b/=2;
    }
    return w;
}
int n,k;
ll dpold[1<<20];
ll dpnew[1<<20];
ll l;
int a[1<<20];
int main()
{
    ios_base::sync_with_stdio(0);
	cin>>n>>l>>k;
	FOR(i,n) cin>>a[i];
	vector<pii> v;
	FOR(i,n) v.pb(mp(a[i],i));
	sort(ALL(v));
	FOR(i,n) dpold[i]=1;
	ll z=l/n;
	ll r=l%n;
	ll z1=1;
	ll z0=0;
	ll silnia=1;
	ll silnia1=1;
	ll res=0;
	ll wsp0,wsp1;
	REP(x,1,k)
	{
		wsp0=(z-x+1);
		if (wsp0<0) wsp0=0;
		wsp0%=MOD;

		int ind=0;
		ll wyn=0;
		FOR(i,n)
		{
			if (v[i].se<r && (x-1<=z) ) res=(res+dpold[i])%MOD;
			res=(res+wsp0*dpold[i])%MOD;
		}
		FOR(i,n)
		{
			while(ind<n && v[ind].fi<=v[i].fi) {wyn=(wyn+dpold[ind])%MOD;ind++;}
			dpnew[i]=wyn;
		}
		FOR(i,n) dpold[i]=dpnew[i];
	}
	cout<<res;
	return 0;
}