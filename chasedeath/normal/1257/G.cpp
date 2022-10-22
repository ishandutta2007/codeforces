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

const int N=1<<20,P=998244353;

typedef vector <int> V;

ll qpow(ll x,ll k=P-2) {
	ll res=1;
	for(;k;k>>=1,x=x*x%P) if(k&1) res=res*x%P;
	return res;
}

int n,m;
int w[N];
void Init(){
	w[N>>1]=1;
	ll t=qpow(3,(P-1)/N);
	rep(i,(N>>1)+1,N-1) w[i]=w[i-1]*t%P;
	drep(i,(N>>1)-1,1) w[i]=w[i<<1];
}

int rev[N];
int Init(int n){
	int R=1,c=-1;
	while(R<=n) R<<=1,c++;
	rep(i,0,R-1) rev[i]=(rev[i>>1]>>1)|((i&1)<<c);
	return R;
}

void NTT(int n,V &A,int f){
	if((int)A.size()<n) A.resize(n);
	static ull a[N];
	rep(i,0,n-1) a[i]=A[rev[i]];
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
		ll base=qpow(n);
		rep(i,0,n-1) A[i]=A[i]*base%P;
	}
}

V operator * (V a,V b){
	int n=a.size()+b.size()-1,R=Init(n);
	//puts("Multiply ");
	//for(int i:a) cout<<i<<' ';
	//puts("");
	//for(int i:b) cout<<i<<' ';
	//puts("");
	NTT(R,a,1),NTT(R,b,1);
	rep(i,0,R-1) a[i]=1ll*a[i]*b[i]%P;
	NTT(R,a,-1),a.resize(n);
	//for(int i:a) cout<<i<<' ';
	//puts("");
	return a;
}

int c[N*3];
int A[N],C;


V Solve(int l,int r){
	if(l==r){
		V R(A[l]+1);
		rep(i,0,A[l]) R[i]=1;
		return R;
	}
	int mid=(l+r)>>1;
	return Solve(l,mid)*Solve(mid+1,r);
}

int main(){
	Init();
	rep(i,1,n=rd()) c[rd()]++;
	int m=0;
	rep(i,1,3e6) if(c[i]) A[++C]=c[i],m+=c[i];
	printf("%d\n",Solve(1,C)[m/2]);
}