//114514min
//ACM 
#pragma GCC optimize("Ofast")
#pragma GCC target("popcnt")
#pragma GCC target("sse3","sse2","sse")
#pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target("f16c")
#pragma GCC target("fma","avx2")
#pragma GCC target("xop","fma4")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream & operator>>(istream &cin,pair<typC,typD> &a) {return cin>>a.first>>a.second;}
template<typename typC> istream & operator>>(istream &cin,vector<typC> &a){for (auto &x:a) cin>>x;return cin;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const pair<typC,typD> &a) {return cout<<a.first<<' '<<a.second;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const vector<pair<typC,typD>> &a){for (auto &x:a) cout<<x<<'\n';return cout;}
template<typename typC> ostream & operator<<(ostream &cout,const vector<typC> &a){int n=a.size();if (!n) return cout;cout<<a[0];for (int i=1;i<n;i++) cout<<' '<<a[i];return cout;}
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=2e5+5;
set<int> s[N];
vector<int> e[N];
int a[N],f[N],dep[N];
int ans;
void dfs(int u)
{
	bool flg=0;
	dep[u]^=a[u];
	s[u].insert(dep[u]);
	for (int v:e[u]) if (v!=f[u])
	{
		f[v]=u;
		dep[v]=dep[u];
		dfs(v);
		if (s[u].size()<s[v].size()) swap(s[u],s[v]);
		if (!flg) for (int x:s[v])
		{
			flg|=s[u].count(x^a[u]);
			if (flg) break;
		}
		s[u].insert(all(s[v]));
		{
			set<int> t;
			s[v].swap(t);
		}
	}
	if (flg)
	{
		ans++;
		{
			set<int> t;
			s[u].swap(t);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,i;
	cin>>n;
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1);
	cout<<ans<<endl;
}