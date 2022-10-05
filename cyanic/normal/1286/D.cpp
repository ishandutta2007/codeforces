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
typedef double ld;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

namespace{
	const int mod=998244353;
	int fix(int x){
		return x>=mod?x-mod:x;
	}
	int mul(int x,int y){
		return (ll)x*y%mod;
	}
	int power(int x,int p){
		int res=1;
		for(;p;p>>=1,x=(ll)x*x%mod)
			if(p&1)res=(ll)res*x%mod;
		return res;
	}
	int Div(int x,int y){
		return (ll)x*power(y,mod-2)%mod;
	}
}
 
const int N=100005;
struct mat{
	int v[2][2];
	mat(int _v=0) { v[0][0]=v[1][1]=_v,v[0][1]=v[1][0]=0; }
	int sum() { return fix(fix(v[0][0]+v[0][1])+fix(v[1][0]+v[1][1])); }
	friend mat operator * (mat a,mat b){
		mat res;
		res.v[0][0]=fix(mul(a.v[0][0],b.v[0][0])
					   +mul(a.v[0][1],b.v[1][0]));
		res.v[0][1]=fix(mul(a.v[0][0],b.v[0][1])
					   +mul(a.v[0][1],b.v[1][1]));
		res.v[1][0]=fix(mul(a.v[1][0],b.v[0][0])
					   +mul(a.v[1][1],b.v[1][0]));
		res.v[1][1]=fix(mul(a.v[1][0],b.v[0][1])
					   +mul(a.v[1][1],b.v[1][1]));
		return res;
	}
} T[N<<2];
int x[N],v[N],p[N],q[N],n;

void build(int o,int l,int r){
	if(l==r){
		T[o].v[0][0]=q[l];
		T[o].v[0][1]=q[l];
		T[o].v[1][0]=p[l];
		T[o].v[1][1]=p[l];
		assert(T[o].sum()==2);
		return;
	}
	int m=(l+r)>>1;
	build(o<<1,l,m),build(o<<1|1,m+1,r);
	T[o]=T[o<<1]*T[o<<1|1];
	assert(T[o].sum()==2);
}
void upd(int o,int l,int r,int x,int a,int b){
	if(l==r){
		T[o].v[a][b]=0;
		return;
	}
	int m=(l+r)>>1;
	if(x<=m) upd(o<<1,l,m,x,a,b);
	else upd(o<<1|1,m+1,r,x,a,b);
	T[o]=T[o<<1]*T[o<<1|1];
}

struct node{
	int k,a,b,t;
	ld tim;
	friend bool operator < (node x,node y){
		return x.tim<y.tim;
	}
} qu[N<<1];
int cnt;

int main(){
	read(n);
	if(n==1){
		puts("0");
		return 0;
	}
	rep(i,1,n){
		read(x[i]),read(v[i]),read(p[i]);
		p[i]=Div(p[i],100),q[i]=fix(mod+1-p[i]);
	}
	build(1,1,n);
	rep(i,1,n-1){
		int t=Div(x[i+1]-x[i],v[i]+v[i+1]);
		qu[++cnt]=(node){i,1,0,t,1.0*(x[i+1]-x[i])/(v[i]+v[i+1])};
		if(v[i]>v[i+1]){
			int t=Div(x[i+1]-x[i],v[i]-v[i+1]);
			qu[++cnt]=(node){i,1,1,t,1.0*(x[i+1]-x[i])/(v[i]-v[i+1])};
		}
		if(v[i+1]>v[i]){
			int t=Div(x[i+1]-x[i],v[i+1]-v[i]);
			qu[++cnt]=(node){i,0,0,t,1.0*(x[i+1]-x[i])/(v[i+1]-v[i])};
		}
	}
	sort(qu+1,qu+cnt+1);
	int ans=0,prob=2;
	rep(i,1,cnt){
		upd(1,1,n,qu[i].k,qu[i].a,qu[i].b);
		int now=fix(fix(T[1].v[0][0]+T[1].v[0][1])
				   +fix(T[1].v[1][0]+T[1].v[1][1]));
		ans=fix(ans+mul(qu[i].t,fix(prob-now+mod)));
		prob=now;
	}
	cout<<Div(ans,2)<<endl;
	return 0;
}