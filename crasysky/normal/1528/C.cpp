#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
#define db long double
#define sit set<int>::iterator
using namespace std;
const int N=1e6+6,P=998244353;
vector<int> G1[N],G2[N]; int l[N],r[N],dc,ans; set<int> s;
void init2(int u){
	l[u]=++dc; rep0(i,G2[u].size()) init2(G2[u][i]);
	r[l[u]]=dc;
}
void solve(int u){
	sit it=s.lower_bound(l[u]);
	int x=0,y=0;
	if (it==s.end()||*it>r[l[u]]){
		if (it!=s.begin()){
			--it;
			if (r[*it]>=l[u]) y=*it,s.erase(it);
		}
		x=l[u],s.insert(l[u]);
	}
	ans=max(ans,(int)s.size());
	rep0(i,G1[u].size()) solve(G1[u][i]);
	if (x) s.erase(x);
	if (y) s.insert(y);
}
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d",&n);
		rep(i,1,n) G1[i].clear(),G2[i].clear();
		rep(i,2,n){
			int f; scanf("%d",&f); G1[f].pb(i);
		}
		rep(i,2,n){
			int f; scanf("%d",&f); G2[f].pb(i);
		}
		dc=ans=0,init2(1),solve(1);
		printf("%d\n",ans);
	}
	return 0;
}