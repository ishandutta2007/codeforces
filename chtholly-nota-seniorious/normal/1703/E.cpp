//114514min
//ACM 
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
const int N=1e6+5;
struct union_set
{
	vector<int> f;
	int n;
	union_set(){}
	union_set(int nn):n(nn),f(nn+1)
	{
		iota(all(f),0);
	}
	int getf(int u) {return f[u]==u?u:f[u]=getf(f[u]);}
	void uni(int u,int v)
	{
		u=getf(u);v=getf(v);
		f[u]=v;
	}
	bool con(int u,int v) {return getf(u)==getf(v);}
};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j,ans=0;
		cin>>n;
		vector<string> a(n);
		for (auto &s:a) cin>>s;
		union_set s(n*n);
		vector cnt(n*n,vector(2,0));
		for (i=0;i<n;i++) for (j=0;j<n;j++) s.uni(i*n+j,j*n+(n-i-1));
		for (i=0;i<n;i++) for (j=0;j<n;j++) cnt[s.getf(i*n+j)][a[i][j]-'0']++;
		for (i=0;i<n*n;i++) if (s.f[i]==i) ans+=min(cnt[i][0],cnt[i][1]);
		cout<<ans<<'\n';
	}
}