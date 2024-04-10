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



int main()
{
    ios_base::sync_with_stdio(0);
    int hl,hr,n;cin>>hl>>hr>>n;
    vector<pair<pii,int> > m[2];
    FOR(i,n)
    {
		int v;cin>>v;
		char typ;cin>>typ;
		int a,b;cin>>a>>b;
		if (typ=='F') m[0].pb(mp(mp(a,b),v));
		else m[1].pb(mp(mp(a,b),v));
	}
	ll best=0;
	ll D=100000;
	REP(d,1,n+1)
	{
		bool uz[2][102];
		FOR(i,2)FOR(j,102) uz[i][j]=0;
		ll wyn=0;
		ll H=abs(d%2?hr+(d-1)*100:100-hr+(d-1)*100)+hl;
		bool zle=0;
		FOR(i,d)
		{
			ll L=hl+i*100;
			ll R=H-L;
			int kt=i%2;
			bool nic=0;
			FOR(j,m[kt].sz)
			{
				int x=m[kt][j].fi.fi;
				int y=m[kt][j].fi.se;
				if (x*(R+L)<=L*D && L*D<=y*(R+L))
				{
					wyn+=m[kt][j].se;
					if (uz[kt][j]) zle=1;
					uz[kt][j]=1;
					nic=1;
				}
			}
			if (!nic) zle=1;
		}
		if (!zle) REMAX(best,wyn);
	}
	swap(m[0],m[1]);
	hl=100-hl;
	hr=100-hr;
	REP(d,1,n+1)
	{
		bool uz[2][102];
		FOR(i,2)FOR(j,102) uz[i][j]=0;
		ll wyn=0;
		ll H=abs(d%2?hr+(d-1)*100:100-hr+(d-1)*100)+hl;
		bool zle=0;
		if (d==3) DBG(H);
		FOR(i,d)
		{
			ll L=hl+i*100;
			ll R=H-L;
			if (d==3) DBG(mp(L,R));
			int kt=i%2;
			bool nic=0;
			FOR(j,m[kt].sz)
			{
				int x=m[kt][j].fi.fi;
				int y=m[kt][j].fi.se;
				if (x*(R+L)<=L*D && L*D<=y*(R+L))
				{
					wyn+=m[kt][j].se;
					if (uz[kt][j]) zle=1;
					uz[kt][j]=1;
					nic=1;
				}
			}
			if (!nic) zle=1;
		}
		if (!zle) REMAX(best,wyn);
	}
	cout<<best;
    return 0;
}