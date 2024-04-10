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
using namespace std;
const int N=1e6+6;
int k[N],c[N],p[N],ans[N]; vector<int> v[N];
bool cmp(int x,int y){ return k[x]<k[y]; }
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,m; scanf("%d%d",&n,&m);
		rep(i,1,n) c[i]=0; rep(i,1,m) v[i].clear();
		rep(i,1,m){
			scanf("%d",&k[i]);
			rep(j,1,k[i]){
				int x; scanf("%d",&x); v[i].pb(x);
			}
			p[i]=i;
		}
		sort(p+1,p+1+m,cmp);
		rep(t,1,m){
			int i=p[t],u=0;
			rep(j,1,k[i]-1)
				if (c[v[i][j]]<c[v[i][u]]) u=j;
			ans[i]=v[i][u],++c[v[i][u]];
		}
		bool f=false; 
		rep(i,1,n) if (c[i]>(m+1)/2){ f=true; break; }
		if (f){ puts("NO"); continue; }
		puts("YES");
		rep(i,1,m) printf("%d ",ans[i]);
		puts("");
	}
 	return 0;
}