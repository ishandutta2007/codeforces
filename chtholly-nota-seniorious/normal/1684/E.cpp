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
const int N=1e6+5;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j,r=1e9;
		cin>>n>>m;
		vector<int> a(n);
		for (int &x:a) cin>>x;
		auto s=a;
		sort(all(s));s.resize(unique(all(s))-s.begin());
		int L;
		{
			int l=0,r=1e9,mid;
			while (l<r)
			{
				mid=l+r+1>>1;
				int cnt=mid;
				for (int x:s) if (x<mid) --cnt; else break;
				if (cnt<=m) l=mid; else r=mid-1;
			}
			L=l;
		}
		//dbg(L);
		map<int,int> f;
		vector<int> res;
		for (int x:a) if (x>L) ++f[x];
		for (auto [x,y]:f) res.push_back(y);
		sort(all(res));
		n=res.size();
		for (i=0;i<n;i++) if ((m-=res[i])<0) break;
		cout<<n-i<<'\n';
	}
}