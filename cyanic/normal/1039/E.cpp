#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
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

const int N=100005,M=50,inf=2e9+9;
struct list{
	int *a,n;
	void pb(int x){
		if((n&-n)==n){
			a=(int*)realloc(a,(n*2+1)*(sizeof n));
		}
		a[n++]=x;
	}
} li[N];
int R[N],p[N],f[N],g[N],x[N],ans[N];
int mn[N][18],mx[N][18],lg[N];
int n,m,w,Q;
pii q[N];

int value(int l,int r){
	if(r>n) return inf;
	int t=lg[r-l+1];
	return max(mx[l][t],mx[r-(1<<t)+1][t])
		  -min(mn[l][t],mn[r-(1<<t)+1][t]);
}

void init(){
	read(n),read(w),read(Q);
	m=max(1,(int)(1.5*pow(n,1./3))),lg[0]=-1;
	rep(i,1,n){
		read(x[i]),lg[i]=lg[i>>1]+1;
		mn[i][0]=mx[i][0]=x[i];
	}
	rep(j,1,17) rep(i,1,n-(1<<j)+1){
		mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
		mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
	}
	rep(i,1,Q){
		read(q[i].fi);
		q[i].fi=w-q[i].fi;
		q[i].se=i;
	}
	sort(q+1,q+Q+1);
	per(i,n,1){
		if(i==n||i%m==0){
			R[i]=i,p[i]=i+1;
			f[i]=0,g[i]=i;
		}
		else{
			R[i]=R[i+1],p[i]=i+1;
			f[i]=f[p[i]]+1,g[i]=g[p[i]];
		}
		int las=0;
		rep(j,i+1,R[i]+1){
			int d=lower_bound(q+1,q+Q+1,mp(value(i,j),0))-q;
			if(las<d) li[d].pb(i),las=d;
		}
	}
}

int solve(int step,int id){
	REP(i,li[id].n){
		int k=li[id].a[i];
		while(p[k]<=k+m*m&&value(k,p[k])<=step) p[k]++;
		if(p[k]>R[k]) f[k]=0,g[k]=k;
		else f[k]=f[p[k]]+1,g[k]=g[p[k]];
		for(int j=k-1;R[j]==R[k];j--)
			if(p[j]<=R[j]) f[j]=f[p[j]]+1,g[j]=g[p[j]];
	}
	int res=0,k=1;
	while(k<=n){
		if(p[k]<=R[k]) res+=f[k],k=g[k];
		assert(p[k]>R[k]);
		while(p[k]<=k+m*m&&value(k,p[k])<=step) p[k]++;
		if(p[k]<=k+m*m) res++,k=p[k];
		else{
			int l=k,r=n+1,mid;
			while(l<r){
				mid=(l+r+1)>>1;
				if(value(k,mid)<=step) l=mid;
				else r=mid-1;
			}
			res++,k=l+1;
		}
	}
	return res;
}

int main(){
	init();
	rep(i,1,Q) ans[q[i].se]=solve(q[i].fi,i);
	rep(i,1,Q) printf("%d\n",ans[i]-1);
	return 0;
}