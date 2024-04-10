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
const int N=2e6+10,INF=1e9+10;

int n,m;
int A[N],B[N],C[N],H;
int X[N],Y[N];

int s[N<<2],t[N<<2];
void Upd(int p,int l,int r,int ql,int qr,int x){
	if(ql<=l && r<=qr) return s[p]+=x,t[p]+=x,void();
	int mid=(l+r)>>1;
	if(ql<=mid) Upd(p<<1,l,mid,ql,qr,x);
	if(qr>mid) Upd(p<<1|1,mid+1,r,ql,qr,x);
	s[p]=min(s[p<<1],s[p<<1|1])+t[p];
}

int I[N];
void Build(int p,int l,int r){
	s[p]=l,t[p]=0;
	if(l==r) return;
	int mid=(l+r)>>1;
	Build(p<<1,l,mid),Build(p<<1|1,mid+1,r);
}

bool Med;
int main() {
	//fprintf(stderr,"%.2lf\n",(&Med-&Mbe)/1024.0/1024.0);
	rep(_,1,rd()) {
		n=rd(),m=rd();
		rep(i,1,n) A[i]=C[i]=rd();
		rep(i,1,m) B[i]=C[i+n]=rd();
		sort(C+1,C+n+m+1),H=unique(C+1,C+n+m+1)-C-1;
		rep(i,1,n) A[i]=lower_bound(C+1,C+H+1,A[i])-C,I[i]=i;
		rep(i,1,m) B[i]=lower_bound(C+1,C+H+1,B[i])-C;
		sort(B+1,B+m+1);
		sort(I+1,I+n+1,[&](int x,int y){ return A[x]<A[y]; });
		int p=1,q=1;
		Build(1,0,n);
		ll ans=0;
		rep(i,1,H) X[i]=0;
		rep(i,1,n) {
			for(int p=A[i]+1;p<=H;p+=p&-p) ans+=X[p];
			for(int p=A[i];p;p-=p&-p) X[p]++;
		}
		//cout<<"!"<<ans<<endl;
		rep(i,1,m) {
			while(p<=n && A[I[p]]<B[i]) Upd(1,0,n,0,I[p]-1,1),p++;
			while(q<=n && A[I[q]]<=B[i]) Upd(1,0,n,I[q],n,-1),q++;
			ans+=s[1];
		}
		printf("%lld\n",ans);
	}
}