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

int n,m,q;
int a[N],b[N];
struct BIT{
	ll s[N];
	int c[N],n;
	void Init(int m){ n=m; }
	void Add(int p,int x,int y){
		p++;
		while(p<N) s[p]+=x,c[p]+=y,p+=p&-p;
	}
	ll Que(int p){
		p++;
		if(p<=0) return 0;
		ll sum=0,cnt=0,t=p-1;
		while(p) sum+=s[p],cnt+=c[p],p-=p&-p;
		return t*cnt-sum;
	}
	int Rank(int p){
		if(p<0) return 0;
		p++,cmin(p,N-1);
		int res=0;
		while(p) res+=c[p],p-=p&-p;
		return res;
	}
	int Kth(int k){
		cmin(k,n),cmax(k,1);
		int p=0;
		drep(i,19,0) if(p+(1<<i)<N && c[p+(1<<i)]<k) k-=c[p+=1<<i];
		return p;
	}
	int Prev(int x) { return Kth(Rank(x)); }
	int Next(int x) { return Kth(min(n,Rank(x)+1)); }
} A,B;

ll delta;
void AddA(int x,int k){
	delta+=x*k;
	A.Add(x,x*k,k);
}
void AddB(int x,int k){
	delta-=x*k;
	B.Add(x,x*k,k);
}

ll QueA(ll k){
	ll Min=min(A.Kth(1),B.Kth(1));
	auto F=[&](ll t){ return (n-1)*max(0ll,t-k-Min)-B.Que(t-k)+(m-n)*t; };
	ll ans=max(F(A.Kth(1)),F(A.Kth(n)));
	int p=B.Kth(m-1)+k;
	cmax(ans,F(A.Prev(p))),cmax(ans,F(A.Next(p)));
	return ans;
}

ll QueB(ll k){
	ll Min=min(A.Kth(1),B.Kth(1));
	auto F=[&](ll t){ return n*max(0ll,t-k-Min)-B.Que(t-k)+(m-n)*t; };
	ll ans=max(F(B.Kth(1)),F(B.Kth(m)));
	int p=B.Kth(m)+k;
	cmax(ans,F(B.Prev(p))),cmax(ans,F(B.Next(p)));
	return ans;
}

ll Que(ll k){
	return max(QueA(k),QueB(k))+delta+(n-m)*k;
}

int main(){
	n=rd(),m=rd(),q=rd(),A.Init(n),B.Init(m);
	rep(i,1,n) AddA(a[i]=rd(),1);
	rep(i,1,m) AddB(b[i]=rd(),1);
	while(q--) {
		int opt=rd();
		if(opt==1) {
			int x=rd(),y=rd();
			AddA(a[x],-1),AddA(a[x]=y,1);
		} else if(opt==2) {
			int x=rd(),y=rd();
			AddB(b[x],-1),AddB(b[x]=y,1);
		} else printf("%lld\n",Que(rd()));
	}
}