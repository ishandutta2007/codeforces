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

int komp[300];
vi kr[300];
int indeg[300];
bool doned[300];
int n;

int go(int kol)
{
	FOR(i,n) indeg[i]=0;
	FOR(i,n) doned[i]=0;
	int mam=0;
	FOR(i,n) FOR(j,kr[i].sz) indeg[kr[i][j]]++;
	int wyn=-1;
	while(mam<n)
	{
		FOR(l,n)
		{
			bool ok=0;
		FOR(j,n)
		{
			if (!doned[j] && indeg[j]==0 && komp[j]==kol)
			{
				FOR(k,kr[j].sz) indeg[kr[j][k]]--;
				doned[j]=1;
				mam++;
				ok=1;
			}
		}
		if (!ok) break;
		}
		wyn++;
		kol=(kol+1)%3;
	}
	return wyn;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    FOR(i,n)
	{
		cin>>komp[i];
		komp[i]--;
	}
	FOR(i,n)
	{
		int k;cin>>k;
		FOR(j,k)
		{
			int a;
			cin>>a;
			a--;
			kr[a].pb(i);
		}
	}
	int g=1423534;
	//FOR(k,3) DBG(go(k));
	FOR(k,3) REMIN(g,go(k));
	cout<<g+n;
    
    return 0;
}