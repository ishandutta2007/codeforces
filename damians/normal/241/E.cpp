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

int a[6000];
int b[6000];
int d[6000];
bool wazne[5000];
int osiag1[5000];
int osiag2[5000];



int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;CZ2(n,m);
    FOR(i,m) CZ2(a[i],b[i]);
    FOR(i,m) {a[i]--;b[i]--;}
    osiag1[0]=1;
    osiag2[n-1]=1;
    FOR(dsg,n) FOR(i,m)
    {
		osiag1[b[i]]|=osiag1[a[i]];
		osiag2[a[i]]|=osiag2[b[i]];
	}
	FOR(i,m) wazne[i]=(osiag1[a[i]] && osiag2[a[i]] && osiag1[b[i]] && osiag2[b[i]]);
    FOR(i,n) d[i]=10325300;
    d[0]=0;
    FOR(gfj,n)FOR(i,m)
    {
		if (wazne[i])
		{
			REMIN(d[b[i]],d[a[i]]+2);
			REMIN(d[a[i]],d[b[i]]-1);
		}
	}
	FOR(i,m)
	{
		if (wazne[i] && !(1<=d[b[i]]-d[a[i]] && d[b[i]]-d[a[i]]<=2)) {puts("No");return 0;}
	}
	puts("Yes");
	FOR(i,m) printf("%d\n",(wazne[i])?d[b[i]]-d[a[i]]:1);
    return 0;
}