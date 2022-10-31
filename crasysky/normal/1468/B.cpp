#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<db,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
#define db long double
using namespace std;
const int N=1e6+6; const db eps=1e-8;
int a[N],st[N],son[N],pre[N],nxt[N]; ll s[N];
pr v[N]; set<int> pos; multiset<int> ans;
db slope(int i,int j){ return (db)(s[j]-s[i])/(j-i); }
int main(){
	int n,m; scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
	s[n]=3e14; int tp=0;
	rep(i,0,n){
		while (tp>1&&slope(st[tp-1],st[tp])>slope(st[tp],i)) --tp;
		v[i]=mp(slope(st[tp],i),i),st[++tp]=i;
	}
	pos.insert(0),pos.insert(n),ans.insert(n),sort(v+1,v+1+n);
	for (int j=1;m--;){
		int k; scanf("%d",&k);
		while (j<=n&&v[j].fi<=k+eps){
			int u=v[j].se,l=*--pos.lower_bound(u),r=*pos.lower_bound(u);
			pos.insert(u),ans.erase(ans.find(r-l)),ans.insert(u-l),ans.insert(r-u);
			++j;
		}
		printf("%d ",(*--ans.end())-1);
	}
	return 0;
}