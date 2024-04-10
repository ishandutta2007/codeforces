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


int main()
{
	FILE *inf=fopen("input.txt","r");
	FILE *outf=fopen("output.txt","w");
	int n;CZ(n);
	if (n==1)
	{
		fprintf(outf,"1\n1 1\n");
	}
	else
	{
		int m=n-1;
		int cnt=0;
		while(m)
		{
			cnt++;
			m/=2;
		}
		fprintf(outf,"%d\n",cnt);
		FOR(i,cnt)
		{
			vi v;
			FOR(j,n)
			{
				if ((1<<i)&j) v.pb(j);
			}
			fprintf(outf,"%d ",v.sz);
			FOR(j,v.sz) fprintf(outf,"%d ",v[j]+1);
			fprintf(outf,"\n");
		}
	}
	fclose (inf);
	fclose (outf);
    
    return 0;
}