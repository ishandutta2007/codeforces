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
int a[100002];
ll wyn[100002];
ll s[100002];
int main()
{
    ios_base::sync_with_stdio(0);
    int n;CZ(n);
    FOR(i,n) CZ(a[i]);
    sort(a,a+n);
    n--;
    reverse(a,a+n);
    //DBG(vi(a,a+n));

    s[0]=0;
    REP(i,1,n)s[i]=s[i-1]+a[i-1];
    REP(i,1,n)
    {
		int k=0;
		int k2;
		int cnt=1;
		ll plus=i;
		while(k<n)
		{
			k2=min(k+plus,(ll)n);
			wyn[i]+=cnt*(s[k2]-s[k]);
			k=k2;
			cnt++;
			plus*=i;
		}
	}
	//DBG(vector<ll>(wyn,wyn+n+1));
	int q;CZ(q);
	while(q--)
	{
		int z;CZ(z);
		z=min(z,n);
		printf("%I64d ",wyn[z]);
	}
    return 0;
}