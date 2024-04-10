#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=500005,M=55;
int pa[M][N],sz[M][N],a[N],b[N],e[N],c[N];
int cur[N],las[N],A[N],B[N],C[N];
vi T[N<<2],pos[N];
int n,m,K,Q,top;

void push(int o,int l,int r,int x,int y,int z){
	if(l==x&&y==r)return (void)(T[o].pb(z));
	if(x<=mid)push(lc,l,mid,x,min(y,mid),z);
	if(mid<y)push(rc,mid+1,r,max(mid+1,x),y,z);
}

bool w[M][N];
pii getpa(int c,int x){
	int f=0;
	while(pa[c][x]!=x)
		f^=w[c][x],x=pa[c][x];
	return mp(x,f);
}

void add(int x,int y,int c){
	pii a=getpa(c,x),b=getpa(c,y);
	if(a.fi==b.fi)return;
	if(sz[a.fi]<sz[b.fi])swap(a,b);
	pa[c][b.fi]=a.fi;
	w[c][b.fi]=a.se^b.se^1;
	sz[c][a.fi]+=sz[c][b.fi];
	A[++top]=a.fi,B[top]=b.fi,C[top]=c;
}

void del(int a,int b,int c){
	sz[c][a]-=sz[c][b];
	w[c][b]=0,pa[c][b]=b;
}

void solve(int o,int l,int r){
	int owo=top;
	for(auto x:T[o])
		if(cur[x]){
			int k=cur[x];
			add(a[e[k]],b[e[k]],c[k]);
		}
	if(l==r){
		int col=c[l],k=e[l];
		pii x=getpa(col,a[k]);
		pii y=getpa(col,b[k]);
		if(x.fi==y.fi&&x.se==y.se){
			puts("NO");
			cur[l]=cur[las[l]];
		}
		else puts("YES");
		while(top>owo)
			del(A[top],B[top],C[top]),top--;
		return;
	}
	solve(lc,l,mid),solve(rc,mid+1,r);
	while(top>owo)
		del(A[top],B[top],C[top]),top--;
}

int main(){
	read(n),read(m);
	read(K),read(Q);
	rep(i,1,m)
		read(a[i]),read(b[i]);
	rep(i,1,Q){
		read(e[i]),read(c[i]);
		pos[e[i]].pb(i),cur[i]=i;
	}
	rep(i,1,m){
		pos[i].pb(Q);
		for(int j=0;j+1<pos[i].size();j++){
			int a=pos[i][j],b=pos[i][j+1];
			if(a<b)push(1,1,Q,a+1,b,a),las[b]=a;
		}
	}
	rep(i,1,K)rep(j,1,n)
		pa[i][j]=j,sz[i][j]=1;
	solve(1,1,Q);
	return 0;
}