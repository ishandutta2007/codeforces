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

void zle()
{
	puts("NO");
	exit(0);
}

int v[1000002];
int ne[10000002];
int pre[1000002];
int mn[1000002];
bool doned[1000002];

int main()
{
    ios_base::sync_with_stdio(0);
    int n;CZ(n);
    FOR(i,n)CZ(v[i+1]);
    int t;CZ(t);FOR(i,t){int x;CZ(x);mn[x]=1;}
    REP(i,1,n){pre[i]=i-1;ne[i]=i+1;}
    int red=0;
    vi r;
    REP(i,1,n)
    {
		if (mn[i]==1)
		{
			while(1)
			{
				if (pre[i]==0) zle();
				if (v[pre[i]]==v[i])
				{
					doned[pre[i]]=doned[i]=1;
					red++;
					ne[pre[pre[i]]]=ne[i];
					pre[ne[i]]=pre[pre[i]];
					break;
				}
				if (r.sz==0) zle();
				int f=r.back();r.pop_back();
				if (pre[f]==0 || doned[f] || doned[pre[f]] || v[f]!=v[pre[f]]) continue;
				doned[pre[f]]=doned[f]=1;
				red++;
				mn[f]=1;
				ne[pre[pre[f]]]=ne[f];
				pre[ne[f]]=pre[pre[f]];
				f=ne[f];
				r.pb(f);
			}
		}
		else
		{
			if (v[pre[i]]==v[i])
			{
				r.pb(i);
			}
		}
	}
	//DBG(r);
	while(r.sz)
	{
		//DBG(r);
		int f=r.back();r.pop_back();
		//DBG(f);
		//DBG(red);
		
		//DBG(f);
		//DBG(pre[f]);
		//DBG(ne[f]);
		if (pre[f]==0 || doned[f] || doned[pre[f]] || v[f]!=v[pre[f]]) continue;
		doned[pre[f]]=doned[f]=1;
		red++;
		mn[f]=1;
		ne[pre[pre[f]]]=ne[f];
				pre[ne[f]]=pre[pre[f]];
		f=ne[f];
		r.pb(f);
	}
	if (red*2!=n) zle();
	puts("YES");
	REP(i,1,n)
	{
		printf("%d ",mn[i]?-v[i]:v[i]);
	}
    
    return 0;
}