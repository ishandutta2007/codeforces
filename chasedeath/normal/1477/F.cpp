#include<bits/stdc++.h>
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
#define reg register
#define pb push_back
#define mp make_pair
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,const T &b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,const T &b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=1<<11|10,P=998244353;

int n,m,k;
ll qpow(ll x,ll k=P-2) {
	ll res=1;
	for(;k;k>>=1,x=x*x%P) if(k&1) res=res*x%P;
	return res;
}

int rev[N],I[N],J[N];
typedef vector <int> V;
void Init(){
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
void NTT(int n,V &a,int f) {
	static int e[N>>1];
	rep(i,0,n-1) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=e[0]=1;i<n;i<<=1) {
		ll t=qpow(f==1?3:(P+1)/3,(P-1)/i/2);
		for(int j=i-2;j>=0;j-=2) e[j+1]=(e[j]=e[j>>1])*t%P;
		for(int l=0;l<n;l+=i*2) {
			for(int j=l;j<l+i;++j) {
				int t=1ll*e[j-l]*a[j+i]%P;
				a[j+i]=a[j]-t,Mod2(a[j+i]);
				a[j]+=t,Mod1(a[j]);
			}
		}
	}
	if(f==-1) {
		ll Inv=1ll*I[n]*J[n-1]%P;
		rep(i,0,n-1) a[i]=a[i]*Inv%P;
	}
}

V operator * (V a,V b){
	if(!a.size() || !b.size()) return {};
	/*puts("Multiplication");
	for(int x:a) cout<<x<<' '; 
	puts("");
	for(int x:b) cout<<x<<' '; 
	puts("");*/
	int n=a.size()+b.size()-1,R=Init(n);
	a.resize(R),b.resize(R);
	NTT(R,a,1),NTT(R,b,1);
	rep(i,0,R-1) a[i]=1ll*a[i]*b[i]%P;
	NTT(R,a,-1);
	a.resize(n);
	/*for(int x:a) cout<<x<<' '; 
	puts("");
	puts("---------------");*/
	return a;
}
V operator + (V a,V b){
	if(a.size()<b.size()) swap(a,b);
	rep(i,0,b.size()-1) a[i]+=b[i],Mod1(a[i]);
	return a;
}

V F[55],A,B;
int S,L[55];

int main(){
	Init();
	n=rd(),k=rd();
	rep(i,1,n) S+=L[i]=rd();
	sort(L+1,L+n+1);
	int InvS=qpow(S);
	F[0]={1};
	rep(i,1,n) {
		int W=(L[i]-1)/k;
		A.clear(),A.resize(W+1);
		B.clear(),B.resize(W+1);
		rep(j,0,W) {
			int w=1ll*(L[i]-j*k)*InvS%P;
			A[j]=1ll*(j&1?P-I[j]:I[j])*qpow(w,j)%P;
			if(j) B[j]=1ll*(j&1?P-I[j]:I[j])*qpow(w,j-1)%P*j%P;
		}
		/*puts("------");
		for(int x:A) cout<<x<<' '; 
		puts("");
		for(int x:B) cout<<x<<' '; 
		puts("");
		puts("------");*/
		drep(j,i,0) {
			if(!j) F[j]=F[j]*A;
			else F[j]=F[j]*A+F[j-1]*B;
		}
		/*rep(j,0,i) {
			for(int x:F[j]) cout<<x<<' ';
			puts("");
		}*/
	}
	int ans=0;
	rep(i,0,n) {
		rep(j,max(i,1),F[i].size()-1) if(F[i][j]) {
			//cout<<F[i][j]<<' ';
			int k=j-i;
			ans=(ans+1ll*F[i][j]*J[k]%P*qpow(1ll*j*::k*InvS%P,P-1-k-1))%P;
		}
		//puts("");
	}
	ans=(P-ans)%P;
	printf("%d\n",ans);
}