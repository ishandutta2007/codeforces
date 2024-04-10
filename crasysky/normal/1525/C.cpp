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
int m,ans[N];
void upd(int &x,int y){ if (x==-1||x>y) x=y; }
void solve(pair<int,pr> *a,int n){
	sort(a+1,a+1+n);
	static int st[N]; int tp=0;
	rep(i,1,n)
		if (a[i].se.fi==1||!tp) st[++tp]=i;
		else{
			int j=st[tp],t=a[i].fi-a[j].fi>>1;
			if (a[j].se.fi==0) t+=a[j].fi;
			upd(ans[a[i].se.se],t);
			upd(ans[a[j].se.se],t); --tp;
		}
	static int st2[N]; int tp2=0;
	per(i,n,1)
		if (a[i].se.fi==0||!tp2) st2[++tp2]=i;
		else{
			int j=st2[tp2],t=a[j].fi-a[i].fi>>1;
			if (a[j].se.fi==1) t+=m-a[j].fi;
			upd(ans[a[i].se.se],t);
			upd(ans[a[j].se.se],t); --tp2;
		}
	if (tp&&tp2){
		int p=st[1],q=st2[1];
		if (a[p].se.fi==0&&a[q].se.fi==1){
			int t=a[p].fi+(m-a[q].fi)+m>>1;
			upd(ans[a[p].se.se],t);
			upd(ans[a[q].se.se],t);
		}
	}
}
pair<int,pr> v1[N],v2[N]; int x[N]; char s[N][5];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d%d",&n,&m);
		rep(i,1,n) scanf("%d",&x[i]),ans[i]=-1;
		rep(i,1,n) scanf("%s",s[i]);
		int k1=0,k2=0;
		rep(i,1,n)
			if (x[i]&1) v1[++k1]=mp(x[i],mp(s[i][0]=='R',i));
			else v2[++k2]=mp(x[i],mp(s[i][0]=='R',i));
		solve(v1,k1),solve(v2,k2);
		rep(i,1,n) printf("%d ",ans[i]); putchar('\n');
	}
	return 0;
}