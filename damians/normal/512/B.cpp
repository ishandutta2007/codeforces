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
#define INF (1LL<<50)

int l[333];
int c[333];
int n;
vi d;

int get(int x)
{
	return lower_bound(ALL(d),x)-d.begin();
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    FOR(i,n)cin>>l[i];
    FOR(i,n)cin>>c[i];
    FOR(i,n)
    {
    	int x=l[i];
    	for(int j=1;j*j<=x;j++)
    	{
    		if (x%j==0)
    		{
    			d.pb(j);
    			d.pb(x/j);
    		}
    	}
    }
    d.pb(0);
    sort(ALL(d));
    un(d);

    vector<ll> dp(d.sz,INF);
    dp[0]=0;

    FOR(i,n)
    {

    	FOR(j,d.sz) REMIN(dp[get(__gcd(d[j],l[i]))],dp[j]+c[i]);

    }
    if (dp[1]<INF) cout<<dp[1];
    else cout<<-1;

	return 0;
}