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

vi kro[1111];
vi krn[1111];
vi zost;
int n;

pii sa(int z)
{
	int d=zost.sz;
	int i=0;
	while(zost[i]!=z) i++;
	pii p;
	if (i) p.fi=zost[i-1]; else p.fi=zost.back();
	if (i<d-1) p.se=zost[i+1];else p.se=zost[0];
	return p;
}
int U;
bool por(int a,int b)
{
	if (a>U && b>U)return a<b;
	if (a<U && b<U) return a<b;
	if (a>U && b<U) return 1;
	return 0;
}


void wywaln(int a,int b)
{
	FOR(i,krn[a].sz)
	{
		if (krn[a][i]==b)
		{
			swap(krn[a][i],krn[a].back());
			krn[a].pop_back();
			break;
		}
	}
}

void wywalo(int a,int b)
{
	FOR(i,kro[a].sz)
	{
		if (kro[a][i]==b)
		{
			swap(kro[a][i],kro[a].back());
			kro[a].pop_back();
			break;
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    FOR(i,n)
    {
    	kro[i].pb((i+1)%n);
    	kro[(i+1)%n].pb(i);
    	krn[i].pb((i+1)%n);
    	krn[(i+1)%n].pb(i);
    }
    FOR(i,n-3)
    {
    	int a,b;cin>>a>>b;
    	a--;b--;
    	kro[a].pb(b);
    	kro[b].pb(a);
    }
    FOR(i,n-3)
    {
    	int a,b;cin>>a>>b;
    	a--;b--;
    	krn[a].pb(b);
    	krn[b].pb(a);
    }
    FOR(i,n)zost.pb(i);
    vector<pii> w;
    
    while(zost.sz>3)
    {
    	int u=0;
    	while(krn[zost[u]].sz>2) u++;
    	int v=zost[u];

    	while(kro[v].sz>2)
    	{
    		U=v;
    		sort(ALL(kro[v]),por);
    		int r=rand()%(kro[v].sz-2);
    		r+=1;
    		int v2=kro[v][r];
    		int x=kro[v][r-1],y=kro[v][r+1];
    		w.pb(mp(v+1,v2+1));
    		wywalo(v,v2);wywalo(v2,v);
    		kro[x].pb(y);
    		kro[y].pb(x);
    	}
    	pii p=sa(v);
    	wywalo(p.fi,v);wywalo(v,p.fi);
    	wywalo(p.se,v);wywalo(v,p.se);
    	wywaln(p.fi,v);wywaln(v,p.fi);
    	wywaln(p.se,v);wywaln(v,p.se);
    	zost.erase(zost.begin() + u);
    }
    cout<<w.sz<<"\n";
    FOR(i,w.sz) cout<<w[i].fi<<" "<<w[i].se<<"\n";
    

	return 0;
}