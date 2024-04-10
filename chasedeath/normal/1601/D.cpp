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

bool Mbe;
const int N=1e6+10,INF=1e9+10;

int n,m,d;
struct Node{
	int a,b;
	bool operator < (const Node __) const {
		return b<__.b;
	}
} A[N],B[N];
int H[N],C;

int s[N<<2],t[N<<2];
void Upd(int p,int l,int r,int ql,int qr,int x) {
	if(ql<=l && r<=qr) return s[p]+=x,t[p]+=x,void();
	int mid=(l+r)>>1;
	if(ql<=mid) Upd(p<<1,l,mid,ql,qr,x);
	if(qr>mid) Upd(p<<1|1,mid+1,r,ql,qr,x);
	s[p]=max(s[p<<1],s[p<<1|1])+t[p];
}
int Que(int p,int l,int r,int x){
	if(l==r) return s[p];
	int mid=(l+r)>>1;
	return (x<=mid?Que(p<<1,l,mid,x):max(s[p<<1],Que(p<<1|1,mid+1,r,x)))+t[p];
}

int X[N],init;
void Build(int p,int l,int r) {
	if(l<=d && d<=r) s[p]=init;
	else s[p]=-1e9;
	if(l==r) return;
	int mid=(l+r)>>1;
	Build(p<<1,l,mid),Build(p<<1|1,mid+1,r);
}
void Upd(int p,int l,int r,int x,int y) {
	if(l==r) { cmax(s[p],y); return; }
	y-=t[p];
	int mid=(l+r)>>1;
	x<=mid?Upd(p<<1,l,mid,x,y):Upd(p<<1|1,mid+1,r,x,y);
	s[p]=max(s[p<<1],s[p<<1|1])+t[p];
}

bool Med;
int main() {
	//fprintf(stderr,"%.2lf\n",(&Med-&Mbe)/1024.0/1024.0);
	int t=rd(); d=rd();
	H[++C]=d;
	rep(i,1,t) {
		int x=rd(),y=rd();
		if(x>=d && y<=d) init++;
		A[++n]=(Node){x,y};
		H[++C]=x,H[++C]=y;
	}
	sort(H+1,H+C+1),C=unique(H+1,H+C+1)-H-1;
	sort(A+1,A+n+1);
	rep(i,1,n) {
		A[i].a=lower_bound(H+1,H+C+1,A[i].a)-H;
		A[i].b=lower_bound(H+1,H+C+1,A[i].b)-H;
	}
	d=lower_bound(H+1,H+C+1,d)-H;
	rep(i,1,n) if(A[i].a>=A[i].b) B[++m]=A[i];
	sort(B+1,B+m+1,[&](Node x,Node y){ return x.a<y.a; });
	Build(1,1,C);
	rep(i,1,m) {
		for(int p=B[i].b;p<=C;p+=p&-p) X[p]++;
		Upd(1,1,C,B[i].b,C,-1);
		//cout<<"!"<<B[i].b<<' '<<C<<' '<<-1<<endl;
	}
	int q=1,ans=init;
	//cout<<"!"<<init<<endl;
	rep(i,1,n) {
		//rep(i,1,C) cout<<Que(1,1,C,i)<<' ';
		//puts("");
		while(q<=m && A[i].b>B[q].a) {
			for(int p=B[q].b;p<=C;p+=p&-p) X[p]--;
			Upd(1,1,C,B[q].b,C,1);
			//cout<<"Delete "<<B[i].b<<' '<<C<<endl;
			q++;
		}
		int r=min(A[i].a,A[i].b-1);
		if(r==0) continue;
		int t=Que(1,1,C,r);
		//cout<<"! upd "<<A[i].a<<' '<<A[i].b<<' '<<t<<endl;
		if(t<-1e7) continue;
		Upd(1,1,C,A[i].b,t+=(A[i].a<A[i].b));
		//cout<<"! upd "<<A[i].a<<' '<<A[i].b<<' '<<t<<endl;
		for(int p=A[i].b;p;p-=p&-p) t+=X[p];
		//cout<<"! upd "<<A[i].a<<' '<<A[i].b<<' '<<t<<endl;
		cmax(ans,t);
	}
	printf("%d\n",ans);
}