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

string s[111111];

vi kr[300];
int odw[300];

vi to;

void dfs(int u)
{
	odw[u]=1;
	FORE(it,kr[u]) if (!odw[*it]) dfs(*it);
	to.pb(u);
}

int nr[333];

int main()
{
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    FOR(i,n) cin>>s[i];
    FOR(i,n-1)
    {
    	int j=0;
    	while(s[i].sz>j && s[i+1].sz>j && s[i][j]==s[i+1][j]) j++;
    	if (j<s[i].sz && j<s[i+1].sz)
    	{
    		kr[s[i][j]].pb(s[i+1][j]);
    	}
    	else if (j<s[i].sz && j==s[i+1].sz)
    	{
    		cout<<"Impossible";
    		return 0;
    		
    	}
    }
    REP(c,'a','z')
    {
    	if (!odw[c]) dfs(c);
    }
    string s;
    REPD(i,to.sz-1,0) s+=char(to[i]);
	FOR(i,to.sz) nr[to[i]]=n-i;
	bool zle=0;
	FOR(i,300) FORE(it,kr[i]) if (nr[i]>nr[*it]) zle=1;
	if (zle) cout<<"Impossible";
	else cout<<s;
	
    

	return 0;
}