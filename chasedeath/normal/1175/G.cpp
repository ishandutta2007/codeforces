#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=2e4+10,U=2e4,INF=1e9+10;

int n,m,A[N];
struct Node{
	ll k,b;
	Node(){}
	Node(ll k,ll b):k(k),b(b){}
	ll operator [] (ll x) const { return k*x+b; }
};
struct Tree{
	static const int M=N*20;
	Node s[M];
	int ls[M],rs[M],cnt;
	int New(){
		int u=++cnt;
		ls[u]=rs[u]=0,s[u]=Node(INF,INF);
		return u;
	}
	void Upd(int &p,int l,int r,int ql,int qr,Node x){
		if(x.k==INF) return;
		if(!p) p=New();
		int mid=(l+r)>>1;
		if(ql<=l && r<=qr) {
			if(x[mid]<s[p][mid]) swap(s[p],x);
			if(l==r) return;
			if(x[l]<s[p][l]) Upd(ls[p],l,mid,ql,qr,x);
			if(x[r]<s[p][r]) Upd(rs[p],mid+1,r,ql,qr,x);
			return;
		}
		if(ql<=mid) Upd(ls[p],l,mid,ql,qr,x);
		if(qr>mid) Upd(rs[p],mid+1,r,ql,qr,x);
	}
	ll Que(int p,int l,int r,int x){
		if(!p) return INF;	
		if(l==r) return s[p][x];
		int mid=(l+r)>>1;
		return min(s[p][x],x<=mid?Que(ls[p],l,mid,x):Que(rs[p],mid+1,r,x));
	}
	int Union(int x,int y,int l,int r){
		if(!x||!y) return x|y;
		Upd(x,l,r,l,r,s[y]);
		int mid=(l+r)>>1;
		ls[x]=Union(ls[x],ls[y],l,mid),rs[x]=Union(rs[x],rs[y],mid+1,r);
		return x;
	}
} X,Y;

int ls[N],rs[N],stk[N],top,mk[N];
int dp[110][N];

int rt[N],Rt;
void Solve(int k,int u,int l,int r){
	if(l>r) return;
	Solve(k,ls[u],l,u-1),Solve(k,rs[u],u+1,r);
	rt[u]=rt[ls[u]];
	if(u>1) X.Upd(rt[u],1,U,1,U,Node(-(u-1),dp[k][u-1]));
	int res=X.Que(rt[u],1,U,A[u]);
	//cout<<"$"<<u<<' '<<l<<' '<<r<<' '<<res<<endl;
	Y.Upd(Rt,1,n,u,r,Node(A[u],res));
	rt[u]=X.Union(rt[u],rt[rs[u]],1,U);
}

int main(){
	X.s[0]=Y.s[0]=Node(INF,INF);
	n=rd(),m=rd();
	rep(i,1,n) {
		A[i]=rd();
		while(top && A[stk[top]]<A[i]) ls[i]=stk[top--];
		if(top) rs[stk[top]]=i;
		stk[++top]=i;
	}
	rep(i,1,n) mk[ls[i]]=mk[rs[i]]=1;
	int rt=0;
	rep(i,1,n) if(!mk[i]) rt=i;
	int ma=0;
	rep(i,1,n) cmax(ma,A[i]),dp[1][i]=ma*i;
	rep(i,1,m-1) {
		X.cnt=0,Y.cnt=0;
		Solve(i,rt,1,n);
		rep(j,1,n) dp[i+1][j]=Y.Que(1,1,n,j);
	}
	printf("%d\n",dp[m][n]);
}