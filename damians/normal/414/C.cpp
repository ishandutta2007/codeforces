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

ll val[2][22];
int t[1<<21];
int co[22];

vi go(int lev,int a,int b)
{
	if (lev==0)
	{
		val[0][0]=val[1][0]=0;
		return vi(1,t[a]);
	}
	else
	{
		vi v1=go(lev-1,a,(a+b)/2);
		vi v2=go(lev-1,(a+b)/2+1,b);
		//DBG(mp(a,b));
		//DBG(v1);
		//DBG(v2);
		int d=(b-a+1)/2,d1=0,d2=0;
		vi v;
		while(d1<d || d2<d)
		{
			if (d1==d) {v.pb(v2[d2++]); continue;}
			else if (d2==d) {v.pb(v1[d1++]);val[0][lev]+=d; continue;}
			if (v1[d1]<=v2[d2])
			{
				v.pb(v1[d1++]);
				val[0][lev]+=d2;
			}
			else v.pb(v2[d2++]);
		}
		d1=0;d2=0;
		swap(v1,v2);
		while(d1<d || d2<d)
		{
			if (d1==d) {d2++; continue;}
			else if (d2==d) {d1++;val[1][lev]+=d; continue;}
			if (v1[d1]<=v2[d2])
			{
				d1++;
				val[1][lev]+=d2;
			}
			else d2++;
		}
		//DBG(mp(a,b));
		
		//DBG(v);
		return v;
		
	}
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;CZ(n);
    FOR(i,1<<n) CZ(t[i]);
    int q;CZ(q);
    go(n,0,(1<<n)-1);
    while(q--)
    {
		int x;CZ(x);
		REPD(i,x,0) co[i]^=1;
		ll sum=0;
		FOR(i,n+1) sum+=val[co[i]][i];
		printf("%I64d\n",sum);
	}
    
    return 0;
}