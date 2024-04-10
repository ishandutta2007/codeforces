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
const int N=1e6+10,INF=1e9+10,P=998244353;

int n;
int a[N],b[N];

ll qpow(ll x,ll k=P-2) {
	ll res=1;
	for(;k;k>>=1,x=x*x%P) if(k&1) res=res*x%P;
	return res;
}

int I[N],J[N];

int C(int n,int m) {
	if(n<0 || m<0 || n<m) return 0;
	return 1ll*J[n]*I[m]%P*I[n-m]%P;
}

Pii A[N];

bool Med;
int main() {
	rep(i,*J=1,N-1) J[i]=1ll*J[i-1]*i%P;
	I[N-1]=qpow(J[N-1]);
	drep(i,N-1,1) I[i-1]=1ll*I[i]*i%P;
	fprintf(stderr,"%.2lf\n",(&Med-&Mbe)/1024.0/1024.0);
	rep(_,1,rd()) {
		n=rd();
		rep(i,1,n) a[i]=rd();
		int l=1,r=n,c=0;
		int q=0;
		while(1) {
			//cout<<"!"<<l<<' '<<r<<' '<<q<<endl;
			int c1=0,c2=0;
			while(!a[l] && l<=r) l++,c1++;
			while(!a[r] && l<=r) r--,c2++;
			if(l>r) {
				int x=c1+c2-1;
				if(q) x+=2;
				assert(x>=0);
				A[++c]=mp(x,-1);
				break;
			} else A[++c]=mp(c1+(q>0),c2+(q>0));
			ll s=0;
			while(l<=r) {
				s+=a[l++];
				while(s>0 && l<=r) s-=a[r--];
				if(s==0) break;
			}
			if(s!=0) break;
			q++;
		}
		//cout<<"#"<<q<<endl;
		//rep(i,1,c) cout<<A[i].first<<' '<<A[i].second<<endl;
		//cout<<"#"<<c<<' '<<q<<endl;
		/*if(q==0) {
			assert(c==1);
			if(~A[c].second) {
				ll ans=0;
				int x=A[c].first,y=A[c].second;
				rep(i,0,max(x,y)) {
					ans=(ans+1ll*C(x,i)*(C(y,i)+C(y,i-1)+C(y,i+1)))%P;
				}
				continue;
			}
		}*/
		ll ans=1;
		//qpow(2,q);
		//cerr<<ans<<endl;
		rep(i,1,c) {
			int x=A[i].first,y=A[i].second;
			if(~y) {
				ll res=0;
				rep(j,0,min(x,y)) res=(res+1ll*C(x,j)*C(y,j))%P;
				ans=ans*res%P;
			} else {
				ll res=qpow(2,x);
				ans=ans*res%P;
			}
		}
		printf("%lld\n",ans);
	}
}