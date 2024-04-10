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
const int N=1e3+5;
vector<int> e[N],tmp[N];
int _a[N],a[N],q[N],id[N],rd[N];
ui f[N];
const ui p=998244353;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n>>m;
		for (i=1;i<=n;i++) cin>>_a[i];
		for (i=1;i<=n;i++)
		{
			rd[i]=0;
			e[i].clear();
		}
		while (m--)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			++rd[v];
		}
		int ql=1,qr=0;
		for (i=1;i<=n;i++) if (!rd[i]) q[++qr]=i;
		while (ql<=qr)
		{
			int u=q[ql++];
			for (int v:e[u]) if (!--rd[v]) q[++qr]=v;
		}
		for (i=1;i<=n;i++) id[q[i]]=i;
		for (i=1;i<=n;i++) tmp[i]=e[i];
		for (i=1;i<=n;i++)
		{
			e[i]=tmp[q[i]];
			for (int &x:e[i]) x=id[x],assert(i<x);
		}
		for (i=1;i<=n;i++) a[i]=_a[q[i]];
		assert(!e[n].size());
		for (i=1;i<=n+2;i++)
		{
			if (!*max_element(a+1,a+n+1)) break;
			for (j=n;j;j--) if (a[j])
			{
				--a[j];
				for (int v:e[j]) ++a[v];
			}
		}
		if (!*max_element(a+1,a+n+1)) {cout<<i-1<<'\n';continue;}
		for (i=1;i<=n;i++) f[i]=a[i]%p;
		for (i=1;i<=n;i++) for (int v:e[i]) (f[v]+=f[i])%=p;
		cout<<(f[n]+n+2)%p<<'\n';
	}
}