#include <bits/stdc++.h>
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...); 1;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=52,M=302,inf=1e9;
struct Q
{
	int u,v,w,tw;
	bool operator<(const Q &o) const {return tw<o.tw;}
};
Q a[M];
int f[N];
int getf(int u) {return f[u]==u?u:f[u]=getf(f[u]);}
int main()
{
	vector<int> s;
	vector<vector<int>> ans;
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,i,j,q;
	cin>>n>>m;
	for (i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	for (i=1;i<=m;i++) for (j=i+1;j<=m;j++) s.push_back(a[i].w+a[j].w-1>>1),s.push_back(a[i].w+a[j].w+1>>1);
	s.push_back(0);
	sort(all(s));s.resize(unique(all(s))-s.begin());q=s.size();ans.resize(q);
	for (i=0;i<q;i++)
	{
		//dbg(s[i]);
		iota(f+1,f+n+1,1);
		for (j=1;j<=m;j++) a[j].tw=abs(s[i]-a[j].w); 
		sort(a+1,a+m+1);
		for (j=1;j<=m;j++)
		{
			int u=getf(a[j].u),v=getf(a[j].v);
			if (u==v) continue;
			ans[i].push_back(a[j].w);
			//dbg(a[j].u,a[j].v,a[j].w);
			f[u]=v;
		}
	}
	ll cur,ta=0;
	int p,k,A,B,C,x,y;
	cin>>p>>k>>A>>B>>C;
	for (i=0;i<p;i++)
	{
		cur=0;
		cin>>x;
		if (s.back()<=x) y=q-1; else y=lower_bound(all(s),x)-s.begin();
		//dbg(y);
		for (int v:ans[y]) cur+=abs(v-x);
		ta^=cur;
		//dbg(cur);
	}
	for (i=p+1;i<=k;i++)
	{
		cur=0;
		x=((ll)x*A+B)%C;
		if (s.back()<=x) y=q-1; else y=lower_bound(all(s),x)-s.begin();
		for (int v:ans[y]) cur+=abs(v-x);
		ta^=cur;
		//dbg(cur);
	}
	cout<<ta<<endl;
}