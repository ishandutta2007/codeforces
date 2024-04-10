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
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1100020,mo=998244353;
int n,m,p[N],mx[N],mn[N],f[505][505];
Vi pos[N];
inline int solve(int *p, int n){
	static int mn[505][505];
	rep(i,0,n+1)rep(j,0,n+1)f[i][j]=0;
	rep(i,1,n+1)f[i][i-1]=1;
	rep(i,1,n){
		mn[i][i]=i;
		rep(j,i+1,n){
			mn[i][j]=mn[i][j-1];
			if(p[j]<p[mn[i][j]])mn[i][j]=j;
		}
	}
	per(l,n,1)rep(r,l,n){
		int a=0,b=0,p=mn[l][r];
		rep(i,l,p)a=(a+1LL*f[l][i-1]*f[i][p-1])%mo;
		rep(i,p,r)b=(b+1LL*f[p+1][i]*f[i+1][r])%mo;
		f[l][r]=1LL*a*b%mo;
	}
	return f[1][n];
}
int getans(int l, int r){
	if(l>r)return 1;
	int res=1;
	int sz=0;int s[1020];
	for(int i=l;i<=r;i=mx[p[i]]+1)s[++sz]=p[i];
	res=solve(s,sz);
	rep(i,1,sz)rep(j,0,SZ(pos[s[i]])-2)res=1LL*res*getans(pos[s[i]][j]+1,pos[s[i]][j+1]-1)%mo;
	return res;
}
inline int qrymn(int l, int r){
	int res=p[l];rep(i,l,r)umin(res,p[i]);return res;
}
int main() {
	read(n);read(m);
	rep(i,1,m)read(p[i]),pos[p[i]].pb(i);
	rep(i,1,m)mn[i]=m+1;
	rep(i,1,m)mx[p[i]]=i;
	per(i,m,1)mn[p[i]]=i;
	rep(i,1,n)if(qrymn(mn[i],mx[i])<i){puts("0");return 0;}
	printf("%d\n",getans(1,m));
	/*
	printf("%d\n",f[1][n]);*/
	return 0;
}