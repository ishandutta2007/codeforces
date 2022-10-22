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

const int N=1<<18,P=1e9+7;
const db PI=acos(-1);


struct Cp{
	db a,b;
	Cp(){}
	Cp(db a,db b):a(a),b(b){}
	Cp operator + (const Cp _) const{ return Cp(a+_.a,b+_.b);  }
	Cp operator - (const Cp _) const{ return Cp(a-_.a,b-_.b);  }
	Cp operator * (const Cp _) const{ return Cp(a*_.a-b*_.b,a*_.b+b*_.a);  }
} R[N];
int rev[N];
void FFT(Cp *a,int f){
	rep(i,0,N-1) if(i<rev[i]) swap(a[i],a[rev[i]]);
	static Cp e[N>>1];
	e[0]=Cp(1,0);
	for(int i=1;i<N;i<<=1) {
		Cp t(cos(PI/i),f*sin(PI/i));
		for(int j=i-2;j>=0;j-=2) e[j+1]=(e[j]=e[j>>1])*t;
		for(int l=0;l<N;l+=i*2){
			for(int j=l;j<l+i;++j) {
				Cp t=a[j+i]*e[j-l];
				a[j+i]=a[j]-t;
				a[j]=a[j]+t;
			}
		}
	}
	if(f==-1) rep(i,0,N-1) a[i].a/=N;
}

int n,m,q;
int a[N],b[N];
ll A[N],B[N],C[N],D1[N],D2[N];
Cp D[N],E[N],F[N],G[N],H[N],I[N];

void Add(ll *a,Cp *b,Cp *c) {
	rep(i,0,N-1) R[i]=b[i]*c[i];
	FFT(R,-1);
	rep(i,0,N-1) a[i]+=round(R[i].a);
}

int main(){
	rep(i,0,N-1) rev[i]=(rev[i>>1]>>1)|((i&1)*(N/2));
	n=rd(),m=rd(),q=rd();
	rep(i,1,n) {
		D[a[i]=rd()].a++;
		if(i>1) F[max(a[i-1],a[i])].a++, G[min(a[i-1],a[i])].a++;
	}
	rep(i,1,m) {
		E[b[i]=rd()].a++;
		if(i>1) H[max(b[i-1],b[i])].a++, I[min(b[i-1],b[i])].a++;
	}
	FFT(D,1),FFT(E,1); FFT(F,1),FFT(G,1); FFT(H,1),FFT(I,1);
	Add(A,D,E);
	Add(B,D,H),Add(B,F,E);
	Add(C,D,I),Add(C,G,E);
	Add(D1,F,H),Add(D2,G,I);
	rep(i,1,N-1) A[i]+=A[i-1],B[i]+=B[i-1],D1[i]+=D1[i-1];
	drep(i,N-2,0) C[i]+=C[i+1],D2[i]+=D2[i+1];
	while(q--) {
		int x=rd();
		ll ans=1ll*n*m-2*A[x-1]-C[x]+B[x-1]+D2[x]-D1[x-1];
		printf("%lld\n",ans);
	}
}