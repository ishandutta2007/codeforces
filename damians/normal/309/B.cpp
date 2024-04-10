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

vector<string> S;
int d[1000002];
char s[7000005];
int ne[1000002][22];

int main()
{
    ios_base::sync_with_stdio(0);
    int n,r,c;CZ3(n,r,c);
    FOR(i,n)
    {
		scanf("%s",s);
		d[i]=strlen(s);
		S.pb(string(s));
	}
	d[n]=r+c+5;
	int dokad=0;
	int sum=d[0]+1;
	FOR(i,n)
	{
		
		if (d[i]>c)
		{
			ne[i][0]=i;
			sum=d[i]+1;
			dokad=i;
		}
		else if (d[i]==c)
		{
			ne[i][0]=i+1;
			sum=d[i]+1+d[i+1]+1;
			dokad=i+1;
		}
		else
		{
			if (i) sum-=d[i-1]+1;
			while(sum<=c+1)
			{
				//DBG(sum);
				sum+=d[++dokad]+1;
			}
			ne[i][0]=dokad;
		}
		//DBG(ne[i][0]);
		//DBG(ne[i][0]);
	}
	ne[n][0]=n;
	for(int j=1;(1<<j)<=r;j++)
	{
		FOR(i,n+1)ne[i][j]=ne[ne[i][j-1]][j-1];
	}

	int best=0;
	int ind=0;
	FOR(i,n)
	{
		int x=r;
		int a=i;
		REPD(j,21,0)
		{
			if (x>=(1<<j))
			{
				a=ne[a][j];
				x-=(1<<j);
			}
		}
		//DBG(a);
		if (a-i>best)
		{
			best=a-i;
			ind=i;
		}
	}
	int wiersz=0;
	int liter=0;
	int nr=0;
	while(wiersz<r)
	{
		if (liter+d[ind]+(!!nr)<=c)
		{
			liter+=d[ind]+(!!nr);
			if (nr) printf(" ");
			nr++;
			printf("%s",S[ind].c_str());
			ind++;
		}
		else
		{
			
			nr=0;
			wiersz++;
			liter=0;
			if (wiersz<r) puts("");
		}
	}
    
    return 0;
}