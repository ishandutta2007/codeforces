#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
typedef vector <int> V;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int L=18,N=1<<L|10,P=998244353;

ll qpow(ll x,ll k=P-2) {
	ll res=1;
	for(;k;k>>=1,x=x*x%P) if(k&1) res=res*x%P;
	return res;
}

int I[N],J[N];
int rev[N],w[N];
void Init(){
	w[1<<(L-1)]=1;
	int t=qpow(3,(P-1)>>L);
	rep(i,(1<<(L-1))+1,1<<L) w[i]=1ll*w[i-1]*t%P;
	drep(i,(1<<(L-1))-1,1) w[i]=w[i<<1];
	rep(i,J[0]=1,N-1) J[i]=1ll*J[i-1]*i%P;
	I[N-1]=qpow(J[N-1]);
	drep(i,N-1,1) I[i-1]=1ll*I[i]*i%P;
}
int Init(int n){
	int R=1,c=-1;
	while(R<=n) R<<=1,c++;
	rep(i,0,R-1) rev[i]=(rev[i>>1]>>1)|((i&1)<<c);
	return R;
}
void NTT(int n,V &A,int f) {
	static ull a[N];
	if((int)A.size()<n) A.resize(n);
	rep(i,0,n-1) a[rev[i]]=A[i];
	for(int i=1;i<n;i<<=1) {
		int *e=w+i;
		for(int l=0;l<n;l+=i*2) {
			for(int j=l;j<l+i;++j) {
				int t=a[j+i]*e[j-l]%P;
				a[j+i]=a[j]+P-t;
				a[j]+=t;
			}
		}
	}
	rep(i,0,n-1) A[i]=a[i]%P;
	if(f==-1) {
		reverse(A.begin()+1,A.end());
		ll base=1ll*I[n]*J[n-1]%P;
		rep(i,0,n-1) A[i]=A[i]*base%P;
	}
}

V operator + (V a,const V &b) {
	if(a.size()<b.size()) a.resize(b.size());
	rep(i,0,b.size()-1) a[i]+=b[i],Mod1(a[i]);
	return a;
}
V operator - (V a,const V &b) {
	if(a.size()<b.size()) a.resize(b.size());
	rep(i,0,b.size()-1) a[i]-=b[i],Mod2(a[i]);
	return a;
}
V operator * (V a,V b) {
	int n=a.size()-1,m=b.size()-1;
	int R=Init(n+m);
	NTT(R,a,1),NTT(R,b,1);
	rep(i,0,R-1) a[i]=1ll*a[i]*b[i]%P;
	NTT(R,a,-1),a.resize(n+m+1);
	return a;
}
void println(const V &a){
	for(int i:a) printf("%d ",i);
	puts("");
}
V read(int n){
	V A(n);
	rep(i,0,n-1) A[i]=rd();
	return A;
}
V operator ~ (V a) {
	int n=a.size(),m=(n+1)>>1;
	if(n==1) return {(int)qpow(a[0])};
	V b=a; b.resize(m),b=~b;
	int R=Init(n*2);
	NTT(R,a,1),NTT(R,b,1);
	rep(i,0,R-1) a[i]=(P+2-1ll*a[i]*b[i]%P)*b[i]%P;
	NTT(R,a,-1),a.resize(n);
	return a;
}

int Div2(int x){ return (x&1?x+P:x)/2; }
V Sqrt(V a){
	if(a.size()==1) return a;
	int n=a.size();
	V b=a; b.resize((n+1)/2),b=Sqrt(b),b.resize(n);
	a=a*~b; a.resize(n);
	rep(i,0,b.size()-1) a[i]+=b[i],Mod1(a[i]);
	rep(i,0,n-1) a[i]=Div2(a[i]);
	return a;
}

int Pow[N],IPow[N];

int main(){
	Init();
	int n=rd(),m=rd();
	V G(m+1);
    rep(i,1,n) {
        int x=rd();
        if(x<=m) G[x]=P-4;
    }
    G[0]=1;
    G=Sqrt(G),G[0]++;
    G=~G;
    rep(i,1,m) printf("%d\n",G[i]*2%P);
}