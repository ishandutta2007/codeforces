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

int n,k;

double tran[1111][1111];

int zrob(int x,int a,int b)
{
	if (x<a || x>b) return x;
	return b-(x-a);
}

double p1[1111],p2[1111];
int tab[1111];

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    FOR(i,n)cin>>tab[i];
    double p=1.0/(n*(n+1)/2);
    FOR(i,n)FOR(j,n)
    {
    	if (i==j) continue;
    	FOR(a,n)REP(b,a,n-1)
    	{
    		int i1=zrob(i,a,b),j1=zrob(j,a,b);
    		tran[i+n*j][i1+n*j1]+=p;
    	}
    }

    double wyn=0;
    int mx=n*n;
    FOR(i,mx)p1[i]=0;
    FOR(I,n)REP(J,I+1,n-1)
    {
    	if (tab[I]<tab[J])
    	p1[I+J*n]+=1;
    	else p1[J+I*n]+=1;
    	
    }
    FOR(gsg,k)
    	{
    		FOR(i,mx)p2[i]=0;
    		FOR(i,mx)
    		{
    			if (p1[i])
    			{
    				FOR(j,mx)
    				{
    					p2[j]+=p1[i]*tran[i][j];
    				}
    			}
    		}
    		FOR(i,mx)p1[i]=p2[i];
    	}
    	FOR(i,mx)
    	{
    		if (p1[i])
    		{
    			int i1=i%n,j1=i/n;
    			if (i1>j1) wyn+=p1[i];
    		}
    	}
    cout<<setprecision(12)<<fixed<<wyn;

	return 0;
}