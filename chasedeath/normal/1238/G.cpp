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

const int N=1e6+10,INF=1e9+10;

int n,m,c0,c;
int H[N],C;
struct Node{
	int t,a,b;
	bool operator < (const Node __) const { return b<__.b; }
} A[N];
int Lim[N];
int s[N<<2],t[N<<2];
void Down(int p){
	rep(i,p<<1,i+1) s[i]+=t[p],t[i]+=t[p];
	t[p]=0;
}
void Build(int p,int l,int r){
	t[p]=0;
	if(l==r) { s[p]=c; return; }
	int mid=(l+r)>>1;
	Build(p<<1,l,mid),Build(p<<1|1,mid+1,r);
	s[p]=min(s[p<<1],s[p<<1|1]);
}
int Que(int p,int l,int r,int ql,int qr){
	//cout<<"Que "<<ql<<' '<<qr<<' '<<l<<' '<<r<<' '<<s[p]<<endl;
	if(ql<=l && r<=qr) return s[p];
	int mid=(l+r)>>1,res=1e9;
	Down(p);
	if(ql<=mid) cmin(res,Que(p<<1,l,mid,ql,qr));
	if(qr>mid) cmin(res,Que(p<<1|1,mid+1,r,ql,qr));
	return res;
}
void Upd(int p,int l,int r,int ql,int qr,int x){
	//cout<<"Upd "<<ql<<' '<<qr<<' '<<l<<' '<<r<<' '<<x<<' '<<s[p]<<endl;
	if(ql<=l && r<=qr) {
		s[p]+=x,t[p]+=x;
		return;
	}
	Down(p);
	int mid=(l+r)>>1;
	if(ql<=mid) Upd(p<<1,l,mid,ql,qr,x);
	if(qr>mid) Upd(p<<1|1,mid+1,r,ql,qr,x);
	s[p]=min(s[p<<1],s[p<<1|1]);
	//cout<<p<<' '<<l<<' '<<r<<' '<<s[p]<<endl;
}

int B[N],F[N];
int Find(int x){ return F[x]==x?x:F[x]=Find(F[x]); }

int main(){
	rep(_,1,rd()) {
		n=rd(),m=rd(),c=rd(),A[n+1].a=rd(),A[n+1].b=A[n+1].t=0;
		H[C=1]=0,H[C=2]=m-1;
		rep(i,1,n) H[++C]=A[i].t=rd(),A[i].a=rd(),A[i].b=rd();
		sort(H+1,H+C+1),C=unique(H+1,H+C+1)-H-1,H[C+1]=m;
		rep(i,1,C) B[i]=H[i+1]-H[i];
		rep(i,1,C+1) F[i]=i;
		Build(1,1,C);
		sort(A+1,A+n+2);
		ll ans=0,s=0; 
		rep(i,1,n+1){
			A[i].t=lower_bound(H+1,H+C+1,A[i].t)-H;
			while(A[i].a) {
				int j=Find(A[i].t);
				//cout<<"Find "<<j<<endl;
				if(j>C) break;
				if(!B[j]){ F[j]=j+1; continue; }
				int t=Que(1,1,C,A[i].t,j);
				int w=min(t,min(A[i].a,B[j]));
				ans+=1ll*w*A[i].b,Upd(1,1,C,A[i].t,j,-w);
				//cout<<"$"<<A[i].t<<' '<<A[i].a<<' '<<A[i].b<<' '<<"j="<<j<<' '<<B[j]<<' '<<w<<endl;
				A[i].a-=w,s+=w,B[j]-=w;
				if(w==t) break;
			}
		}
		if(s<m) puts("-1");
		else printf("%lld\n",ans);
	}
}