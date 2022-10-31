#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=1e6+6; int v[N],c[N],_c[N];
vector<int> ans[N];
int main(){
	int n,k; scanf("%d%d",&n,&k);
	rep(i,1,n){ 
		int x; scanf("%d",&x); ++c[x];
	}
	rep(i,1,k) scanf("%d",&v[i]);
	int l=1,r=n;
	while (l<=r){
		int m=l+r>>1;
		rep(i,1,k+1) _c[i]=c[i];
		rep(i,1,k)
			c[i+1]+=max(c[i]-(ll)m*(v[i]-v[i+1]),0LL);
		if (c[k+1]) l=m+1;
		else r=m-1;
		rep(i,1,k+1) c[i]=_c[i];
	}
	++r; printf("%d\n",r);
	queue<int> q;
	rep(i,1,k){
		rep(j,1,c[i]) q.push(i);
		if (v[i]==v[i+1]) continue;
		rep(p,1,r){
			for (int j=1;j<=v[i]-v[i+1]&&!q.empty();++j)
				ans[p].push_back(q.front()),q.pop();
			if (q.empty()) break;
		}
	}
	rep(i,1,r){
		printf("%d ",ans[i].size());
		rep0(j,ans[i].size()) printf("%d ",ans[i][j]);
		putchar('\n');
	}
	return 0;
}