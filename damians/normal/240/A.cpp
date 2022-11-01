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

bool ulub[1001];
bool mam[1001];
int mn[1002],mx[1002];

int main()
{
	FILE *inf=fopen("input.txt","r");
	FILE *outf=fopen("output.txt","w");
	
	int m,k,n;
	CZ2(m,k);
	FOR(i,k)
	{
		int a;CZ(a);
		ulub[a]=1;
	}
	CZ(n);
	FOR(i,n)
	{
		char syf[1000];
		fscanf(inf,"%s",syf);
		int d;CZ(d);
		int zer=0;
		int zajf=0;
		int zajnf=0;
		FOR(ii,d)
		{
			int a;CZ(a);
			if (a==0) zer++;
			else if (ulub[a]) 
			{
				zajf++;
			}
			else zajnf++;
		}
		mx[i]=zajf+min(zer,k-zajf);
		mn[i]=zajf+max(0,zer-(m-k-zajnf));
	}
	FOR(i,n)
	{
		int mall=0;
		int mnall=0;
		FOR(j,n) if (i!=j) REMAX(mall,mx[j]);
		FOR(j,n) if (i!=j) REMAX(mnall,mn[j]);
		//DBG(mp(mn[i],mx[i]));
		//DBG(mall);
		//DBG(mnall);
		if (mall<=mn[i]) {fprintf(outf,"0\n");continue;}
		if (mx[i]<mnall) {fprintf(outf,"1\n");continue;}
		
		{fprintf(outf,"2\n");continue;}
	}
	
	fclose (inf);
	fclose (outf);
    
    return 0;
}