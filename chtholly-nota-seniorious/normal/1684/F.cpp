//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC> ostream & operator<<(ostream &cout,const vector<typC> &a)
{
	int n=a.size(),i;
	for (i=0;i<n;i++) cout<<a[i]<<" \n"[i+1==n];
	return cout;
}
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
template<typename T> struct tork
{
	vector<T> a;
	int n;
	tork(const vector<T> &b):a(all(b))
	{
		sort(all(a));
		a.resize(unique(all(a))-a.begin());
		n=a.size();
	}
	tork(const T* first,const T* last):a(first,last)
	{
		sort(all(a));
		a.resize(unique(all(a))-a.begin());
		n=a.size();
	}
	void get(T &x) {x=lower_bound(all(a),x)-a.begin()+1;}
	T operator[](const int &x) {return a[x-1];}
};
const int N=1e6+5;
int a[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n>>m;
		for (i=1;i<=n;i++) cin>>a[i];
		{
			tork<int> s(a+1,a+n+1);
			for (i=1;i<=n;i++) s.get(a[i]);
		}
		vector<int> R(n+1);
		while (m--)
		{
			int l,r;
			cin>>l>>r;
			R[l]=max(R[l],r);
		}
		for (i=2;i<=n;i++) R[i]=max({R[i],R[i-1],i});
		vector<pair<int,int>> v;
		vector<vector<int>> pos(n+1);
		for (i=1;i<=n;i++) pos[a[i]].push_back(i);
		for (i=1;i<=n;i++)
		{
			auto rp=upper_bound(all(pos[a[i]]),R[i]);
			if (rp!=pos[a[i]].begin()&&*(rp-1)!=i) v.push_back({i,*--rp});
			if (rp!=pos[a[i]].begin()&&*(rp-1)!=i) v.push_back({i,*--rp});
		}
		vector<int> lst(n+1);
		for (i=n;i;i--)
		{
			if (lst[a[i]]&&R[i]>=lst[a[i]]) v.push_back({i,lst[a[i]]});
			lst[a[i]]=i;
		}
		if (!v.size()) {cout<<"0\n";continue;}
		int l=0,r=n,mid;m=v.size();
		vector<vector<int>> bel(n+1);
		for (i=0;i<m;i++) bel[v[i].first].push_back(i),bel[v[i].second].push_back(i);
		vector<int> sum(n+1);
		for (auto [l,r]:v) ++sum[l],++sum[r];
		while (l<r)
		{
			mid=l+r>>1;
			int cnt=0;
			vector<int> ed(m+1,2);
			for (i=1;i<=mid;i++)
			{
				cnt+=sum[i];
				for (int x:bel[i]) if (!--ed[x]) --cnt;
			}
			assert(cnt<=m);
			if (cnt==m) {r=mid;continue;}
			for (i=mid+1;i<=n;i++)
			{
				cnt+=sum[i]-sum[i-mid];
				for (int x:bel[i-mid]) if (!(ed[x]++)) ++cnt;
				for (int x:bel[i]) if (!--ed[x]) --cnt;
				assert(cnt<=m);
				if (cnt==m) break;
			}
			if (i<=n) r=mid; else l=mid+1;
		}
		cout<<l<<'\n';
	}
}