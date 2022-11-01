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
#include <ctime>
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

int p[1<<19];
int ne[1<<19];
int szuk(int x){if (x==p[x]) return x;return p[x]=szuk(p[x]);}
inline void unia(int x,int y){p[szuk(x)]=szuk(y);}

void go(int a,int b)
{
	if (a>=b) return;
	unia(a,a+1);
	int c=a+1;
	if (ne[a]>a) c=ne[a];
	go(c,b);
	ne[a]=ne[c];
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n,q;cin>>n>>q;
    FOR(i,n) p[i]=i;
    FOR(i,n) ne[i]=i;
    while(q--)
    {
    	int typ,a,b;
    	cin>>typ>>a>>b;
    	a--;b--;
    	if (typ==1)
    	{
    		unia(a,b);
    	}
    	if (typ==2)
    	{
    		go(a,b);
    	}
    	if (typ==3)
    	{
    		if (szuk(a)==szuk(b)) puts("YES");
    		else puts("NO");
    	}
    }
    

	return 0;
}