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
		int n,m,i,j,k;
		cin>>n>>m;
		vector<vector<int>> a(n,vector<int>(m+2));
		vector<int> r(n);
		for (i=0;i<n;i++) for (j=1;j<=m;j++) cin>>a[i][j];
		for (i=0;i<n;i++) for (j=2;j<=m;j++) r[i]+=a[i][j-1]>a[i][j];
		for (i=0;i<n;i++) a[i][m+1]=2e9;
		if (!*max_element(all(r))) {cout<<"1 1\n";continue;}
		for (i=0;i<n;i++) for (j=2;j<=m;j++) if (a[i][j-1]>a[i][j])
		{
			for (i=0;i<n;i++)
			{
				int cnt=0;
				swap(a[i][j-1],a[i][j]);
				for (int j=2;j<=m;j++) cnt+=a[i][j-1]>a[i][j];
				swap(a[i][j-1],a[i][j]);
				if (cnt) break;
			}
			if (i==n) {cout<<j-1<<' '<<j<<'\n';goto yes;}
			set<pair<int,int>> s;
			for (k=1;k<=m;k++) if (k!=j&&k!=j-1)
			{
				//dbg(i,j,k);
				auto v=r;
				for (i=0;i<n;i++)
				{
					s={{j-1,j},{j,j+1},{k-1,k},{k,k+1}};
					for (auto [x,y]:s) v[i]-=a[i][x]>a[i][y];
					swap(a[i][j],a[i][k]);
					for (auto [x,y]:s) v[i]+=a[i][x]>a[i][y];
					swap(a[i][j],a[i][k]);
				}
				if (!*max_element(all(v))) {cout<<j<<' '<<k<<'\n';goto yes;}
				--j;v=r;
				//dbg(j,k);
				for (i=0;i<n;i++)
				{
					s={{j-1,j},{j,j+1},{k-1,k},{k,k+1}};
					for (auto [x,y]:s) v[i]-=a[i][x]>a[i][y];
					swap(a[i][j],a[i][k]);
					for (auto [x,y]:s) v[i]+=a[i][x]>a[i][y];
					swap(a[i][j],a[i][k]);
				}
				//dbg(v);
				if (!*max_element(all(v))) {cout<<j<<' '<<k<<'\n';goto yes;}
				++j;
			}
			goto no;
		}
		no:cout<<"-1\n";continue;
		yes:;
	}
}