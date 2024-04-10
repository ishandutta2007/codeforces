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
#define CZ(x) fscanf(inf,"%d",&(x));
#define CZ2(x,y) fscanf(inf,"%d%d",&(x),&(y));
#define CZ3(x,y,z) fscanf(inf,"%d%d%d",&(x),&(y),&(z));
#define ALL(x) (x).begin(),(x).end()
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define testss int dsdsf;CZ(dsdsf);while(dsdsf--)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

struct pakiet
{
	int nr;
	int a,b;
	int face;
};
int n[2];
int a[2][1000002];
vector<pakiet> v[2];

int main()
{
	FILE *inf=fopen("input.txt","r");
	FILE *outf=fopen("output.txt","w");
	FOR(nr,2)
	{
		pakiet tp;
		tp.nr=nr;
		CZ(n[nr]);
		FOR(i,n[nr])
		{
			CZ(a[nr][i]);
		}
		int i=0;
		while(i<n[nr])
		{
			int j=i;
			while(j<n[nr] && a[nr][j]==a[nr][i]) j++;
			tp.a=i;
			tp.b=j;
			tp.face=a[nr][i];
			i=j;
			v[nr].pb(tp);
		}
	}
	vector<pakiet> V;
	if (v[1].back().face==0) swap(v[0],v[1]);
	while(v[0].sz || v[1].sz)
	{
		if (v[0].sz) {V.pb(v[0].back());v[0].pop_back();}
		if (v[1].sz) {V.pb(v[1].back());v[1].pop_back();}
	}
	reverse(ALL(V));
	FOR(i,V.sz)
	{
		REP(j,V[i].a,V[i].b-1)
		{
			fprintf(outf,"%d ",j+V[i].nr*n[0]+1);
		}
	}
	fprintf(outf,"\n");
	int w=V.back().face;
	FOR(i,(int)V.sz-1) if (V[i].face!=V[i+1].face) w++;
	fprintf(outf,"%d\n",w);
	int sum=0;
	FOR(i,(int)V.sz-1)
	{
		sum+=V[i].b-V[i].a;
		if (V[i].face!=V[i+1].face) fprintf(outf,"%d ",sum);
	}
	if (V.back().face) fprintf(outf,"%d ",n[0]+n[1]);
	fclose (inf);
	fclose (outf);
    
    return 0;
}