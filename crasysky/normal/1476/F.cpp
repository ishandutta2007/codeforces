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
int a[N],ans[N]; pr st[N],tr[N]; int fa[N],to[N],u,cnt;
void push(int x,int y,int f,pr t){
	while (u&&st[u].se<=y) u=fa[u];
	st[++cnt]=mp(x,y),fa[cnt]=u,u=cnt,to[u]=f,tr[u]=t;
}
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i]);
		u=cnt=0,push(1,0,0,mp(0,0));
		rep(i,1,n){
			if (!a[i]) continue;
			int l=i-a[i],r=i+a[i],x=-1,y=-1,v=-1;
			if (u) x=u;
			while (u&&st[u].fi>=l) v=st[u].se,y=u,u=fa[u];
			int t1=~x?(st[x].fi<=i?st[x].fi:r+1):-1;
			int t2=~y?(v>=i?v+1:i):-1;
			if (t1<t2){
				if (~x) push(t1,r,x,mp(i,1));
				if (~y) push(t2,v,y,mp(i,0));
			}
			else{
				if (~y) push(t2,v,y,mp(i,0));
				if (~x) push(t1,r,x,mp(i,1));
			}
		}
		if (st[u].fi<=n){ puts("NO"); continue; }
		puts("YES");
		while (u) ans[tr[u].fi]=tr[u].se,u=to[u];
		rep(i,1,n) putchar(ans[i]==0?'L':'R');
		putchar('\n');
	}
	return 0;
}
/*
1
7
2 1 1 1 1 1 0
*/