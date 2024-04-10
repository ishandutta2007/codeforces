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
vector<int> lg(2);
template <typename T> struct maxtable
{
	vector<T> a;
	vector<vector<T>> st;
	maxtable(const vector<T> &b):a(all(b))
	{
		int n=a.size(),i,j,k,r;
		while (lg.size()<=n) lg.push_back(lg[lg.size()>>1]+1);
		st.assign(lg[n]+1,vector<T>(n));
		iota(all(st[0]),0);
		for (j=1;j<=lg[n];j++)
		{
			r=n-(1<<j);
			k=1<<j-1;
			for (i=0;i<=r;i++) st[j][i]=a[st[j-1][i]]<a[st[j-1][i+k]]?st[j-1][i+k]:st[j-1][i];
		}
	}
	T rmq(int l,int r) const
	{
		assert(0<=l&&l<=r&&r<a.size());
		int z=lg[r-l+1];
		return max(a[st[z][l]],a[st[z][r-(1<<z)+1]]);
	}
	int rmp(int l,int r) const
	{
		assert(0<=l&&l<=r&&r<a.size());
		int z=lg[r-l+1];
		return a[st[z][l]]<a[st[z][r-(1<<z)+1]]?st[z][r-(1<<z)+1]:st[z][l];
	}
};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,m;
	cin>>m>>n;
	vector<int> a(n);
	cin>>a;
	maxtable s(a);
	int q;
	cin>>q;
	while (q--)
	{
		int x1,y1,x2,y2,k,u;
		cin>>x1>>y1>>x2>>y2>>k;
		if ((x1-x2)%k||(y1-y2)%k) goto no;
		--y1;--y2;
		if (y1>y2) swap(y1,y2),swap(x1,x2);
		x2+=(m-x2)/k*k;
		u=s.rmq(y1,y2);
		if (x2<=u) goto no;
		cout<<"YES\n";continue;
		no:cout<<"NO\n";
	}
}