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

const int N=2e5+10,INF=1e9+10;

int n,m;
ll L,R;
vector <int> F[N];

int X[N<<2],Y[N<<2],c[N];
void Upd(int p,int l,int r,int x,int y,int k) {
	if(l==r) {
		if(k==1) X[p]=x,Y[p]=y;
		if((c[x]+=k)==0) X[p]=Y[p]=0;
		//if(x==16) cout<<"$U "<<X[p]<<' '<<Y[p]<<endl;
		return;
	}
	int mid=(l+r)>>1;
	x<=mid?Upd(p<<1,l,mid,x,y,k):Upd(p<<1|1,mid+1,r,x,y,k);
	int q=p<<1; q+=!X[q];
	X[p]=X[q],Y[p]=Y[q];
}

int x,y;
void Que(int p,int l,int r,int ql,int qr) {
	if(!X[p]) return;
	if(ql<=l && r<=qr) { x=X[p],y=Y[p]; return; }
	int mid=(l+r)>>1;
	if(ql<=mid) Que(p<<1,l,mid,ql,qr);
	if(!x && qr>mid) Que(p<<1|1,mid+1,r,ql,qr);
}

void Add(int x,int k) { 
	//cout<<"Add "<<x<<' '<<k<<endl;
	for(int i:F[x]) Upd(1,1,N-1,i,x,k); 
}

int main() {
	rep(i,1,N-1) for(int j=i;j<N;j+=i) F[j].pb(i);
	n=rd(),m=rd();
	L=rd<ll>(),R=rd<ll>();
	int l=m+1,r=m;
	rep(i,1,n) {
		ll ly=(L+i-1)/i,ry=R/i;
		if(ly<1) ly=1;
		if(ry>m) ry=m;
		if(ly>ry){ puts("-1"); continue; }
		while(l>ly) Add(--l,1);
		while(r>ry) Add(r--,-1);
		//cout<<"$"<<i<<' '<<l<<' '<<r<<endl;
		int f=0;
		for(int a:F[i]) {
			int lb=a+1,rb=n/(i/a);
			if(lb>rb) continue;
			//cout<<"Que "<<a<<' '<<lb<<' '<<rb<<endl;
			x=y=0,Que(1,1,N-1,lb,rb);
			if(!x) continue;
			f=1,printf("%d %d %d %d\n",i,y,i/a*x,y/x*a);
			break;
		}
		if(!f) puts("-1");
	}
}