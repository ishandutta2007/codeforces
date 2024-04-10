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

int a[101][101];
int modifr[102];
int modifc[102];
int n,m;
void row(int nr)
{
	modifr[nr]^=1;
	REP(j,1,m) a[nr][j]=-a[nr][j];
}

void col(int nr)
{
	modifc[nr]^=1;
	REP(i,1,n) a[i][nr]=-a[i][nr];
}

int main()
{
    ios_base::sync_with_stdio(0);
    //FOR(dsg,100000)
    //{
		//DBG(dsg);
    CZ2(n,m);

    FOR(i,n)FOR(j,m) CZ(a[i+1][j+1]);
    while(1)
    {
		vector<pii> v;
		REP(i,1,n)
		{
			int sum=0;
			REP(j,1,m) sum+=a[i][j];
			if (sum<0) v.pb(mp(sum,-i));
		}
		REP(j,1,m)
		{
			int sum=0;
			REP(i,1,n) sum+=a[i][j];
			if (sum<0) v.pb(mp(sum,j));
		}
		sort(ALL(v));
		if (v.sz==0) break;
		//DBG(v);
		if (v[0].se<0) row(-v[0].se);
		else col(v[0].se);
	}

	int s=0;
	REP(i,1,n) s+=modifr[i];
	cout<<s<<" ";
	REP(i,1,n) if (modifr[i]) cout<<i<<" ";
	cout<<"\n";
	s=0;
	REP(j,1,m) s+=modifc[j];
	cout<<s<<" ";
	REP(j,1,m) if (modifc[j]) cout<<j<<" ";
    return 0;
}