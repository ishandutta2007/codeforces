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
int query(int *p,int n,int l,int r){
	return upper_bound(p+1,p+1+n,r)-lower_bound(p+1,p+1+n,l);
}
int solve(int *p,int n,int *q,int m){
	static int s[N]; s[n+1]=0;
	per(i,n,1){
		int t=lower_bound(q+1,q+1+m,p[i])-q;
		s[i]=s[i+1]; if (t<=m&&q[t]==p[i]) ++s[i];
	}
	int ans=0;
	rep(i,1,m){
		int x=q[i],l=1,r=n;
		while (l<=r){
			int m=l+r>>1;
			if (m-(p[m]-q[i]+1)>=0) l=m+1;
			else r=m-1;
		}
		int e=x+(l-1)-1;
		ans=max(ans,query(q,m,x,e)+s[l]);
	}
	return ans;
}
int p1[N],p2[N],q1[N],q2[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,m; scanf("%d%d",&n,&m);
		int n1=0,n2=0,m1=0,m2=0;
		rep(i,1,n){
			int x; scanf("%d",&x);
			if (x<0) p1[++n1]=-x; else p2[++n2]=x;
		}
		rep(i,1,m){
			int x; scanf("%d",&x);
			if (x<0) q1[++m1]=-x; else q2[++m2]=x;
		}
		reverse(p1+1,p1+1+n1),reverse(q1+1,q1+1+m1);
		printf("%d\n",solve(p1,n1,q1,m1)+solve(p2,n2,q2,m2)); 
	}
	return 0;
}