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
char s[1000002];
#define MOD 1000000007
int n,k;

void rev()
{
	FOR(i,n/2) swap(s[i],s[n-1-i]);
}

int lol[3000020];
int qp[1000002];

int main()
{
    CZ2(n,k);
    scanf("%s",s);
    rev();
    int of=1000002;
    lol[of]=1;
    int sum=1;
    int moz=0;
    int last=0;
    FOR(i,n)
    {
		DBG(lol[of]);
		DBG(lol[of+1]);
		if (s[i]=='W')
		{
			of--;
			if (lol[of+k])
			{
				moz=(moz+lol[of+k])%MOD;
				sum=(sum-lol[of+k]+MOD)%MOD;
				lol[of+k]=0;
			}
		}
		else if (s[i]=='B')
		{
			FOR(j,2*(i-last)+3) lol[of+j]=0;
			of=1000002;
			lol[of]=sum;
			last=i;
		}
		else
		{
			lol[of-1]=sum;
			sum=(sum+sum)%MOD;
			of--;
			moz=(moz+moz)%MOD;
			if (lol[of+k])
			{
				moz=(moz+lol[of+k])%MOD;
				sum=(sum-lol[of+k]+MOD)%MOD;
				lol[of+k]=0;
			}
		}
		qp[n-1-i]=moz;
		
	}
	DBG(vi(qp,qp+n));
	rev();
	
	
	FOR(i,3000020) lol[i]=0;
	of=1000002;
	sum=1;
    moz=0;
    last=0;
    ll wyn=0;
    lol[of]=1;
    FOR(i,n)
    {
		DBG(lol[of]);
		DBG(lol[of+1]);
		if (s[i]=='B')
		{
			of--;
			if (lol[of+k])
			{
				wyn=(wyn+lol[of+k]*1LL*qp[i+1])%MOD;
				sum=(sum-lol[of+k]+MOD)%MOD;
				lol[of+k]=0;
			}
		}
		else if (s[i]=='W')
		{
			FOR(j,2*(i-last)+3) lol[of+j]=0;
			of=1000002;
			lol[of]=sum;
			last=i;
		}
		else
		{
			lol[of-1]=sum;
			sum=(sum+sum)%MOD;
			of--;
			if (lol[of+k])
			{
				wyn=(wyn+lol[of+k]*1LL*qp[i+1])%MOD;
				sum=(sum-lol[of+k]+MOD)%MOD;
				lol[of+k]=0;
			}
		}	
	}
	cout<<wyn;
    
    return 0;
}