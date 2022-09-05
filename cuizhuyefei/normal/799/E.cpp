#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 233333, M = 8000000, mx = 1e9;
Vi a[4];int n,m,k,c[N],kd[N];
int lc[M],rc[M],cnt[M],sz=1;ll sum[M];//WA
inline void modify(int k, int l, int r, int p, int xs){
//	if(k==1)printf("ins %d %d\n",p,xs);
	cnt[k]+=xs;sum[k]+=xs*p;if(l==r)return;
	int mid=(l+r)>>1;
	if(p<=mid){if(!lc[k])lc[k]=++sz;modify(lc[k],l,mid,p,xs);}
	else{if(!rc[k])rc[k]=++sz;modify(rc[k],mid+1,r,p,xs);}
}
inline ll query(int k, int l, int r, int x){
	if(x>cnt[k])return 1e18;if(!x)return 0;if(l==r)return 1LL*x*l;
	int mid=(l+r)>>1;if(cnt[lc[k]]>=x)return query(lc[k],l,mid,x);
	return sum[lc[k]]+query(rc[k],mid+1,r,x-cnt[lc[k]]);
}
int main() {
	read(n);read(m);read(k);
	rep(i,1,n)read(c[i]);
	int x,l;read(l);while(l--)read(x),kd[x]|=2;
	read(l);while(l--)read(x),kd[x]|=1;
	rep(i,1,n)a[kd[i]].pb(c[i]);
	rep(i,0,3)a[i].pb(-233),sort(a[i].begin(),a[i].end());
	ll res=1e18;int p[4]={0};rep(i,1,n)modify(1,1,mx,c[i],1);ll sum=0;
	rep(x,0,k)if(x<=SZ(a[3])-1&&k-x<=SZ(a[2])-1&&k-x<=SZ(a[1])-1&&x+k-x+k-x<=m){
		int q[4];q[3]=x;q[2]=k-x;q[1]=k-x;
		rep(i,1,3){
			while(p[i]<q[i])p[i]++,sum+=a[i][p[i]],modify(1,1,mx,a[i][p[i]],-1);
			while(p[i]>q[i])sum-=a[i][p[i]],modify(1,1,mx,a[i][p[i]],1),p[i]--;
		}
		res=min(res,query(1,1,mx,m-(x+k-x+k-x))+sum);
	}
	printf("%lld\n",res<1e18?res:-1);
	return 0;
}