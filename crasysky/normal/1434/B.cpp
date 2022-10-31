#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6;
int n,c[N],a[N],C[N]; set <int> s; vector<int> ans[N];
void upd(int x,int y){ for (;x;x-=x&-x) C[x]=y; }
int query(int x){
	int s=0; for (;x<=n;x+=x&-x) s=max(s,C[x]);
	return s;
}
int main(){
	int m=0; scanf("%d",&n);
	rep(i,1,2*n){
		char s[5]; scanf("%s",s);
		if (s[0]=='+') ++c[m];
		else scanf("%d",&a[++m]);
	}
	if (c[0]) s.insert(0);
	rep(i,1,m){
		set<int>::iterator it=s.lower_bound(query(a[i]));
		if (it==s.end()){ puts("NO"); return 0; }
		ans[*it].push_back(a[i]);
		if (!--c[*it]) s.erase(it);
		upd(a[i],i); if (c[i]) s.insert(i);
	}
	puts("YES");
	rep(i,0,n) rep0(j,ans[i].size()) printf("%d ",ans[i][j]);
	return 0;
}