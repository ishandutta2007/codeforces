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

const int N=1e5+10;

int n,m;
int pri[N],pc,notpri[N];

ll qmul(ll x,ll y,ll P){
	ull z=(long double)x/P*y+0.5;
	ll res=(ull)x*y-z*P; 
	Mod2(res);
	return res;
}
ll qpow(ll x,ll k,ll P){
	ll res=1;
	for(;k;k>>=1,x=qmul(x,x,P)) if(k&1) res=qmul(res,x,P);
	return res;
}

int Miller_Rabin(ll n){
	if(n<N) return !notpri[n];
	if(~n&1) return 0;
	ll s=n-1,t=0;
	while(s%2==0) s/=2,t++;
	rep(k,1,7) {
		ll a=qpow(pri[rand()%pc+1],s,n),b;
		rep(i,1,t) {
			b=qmul(a,a,n);
			if(b==1 && a!=1 && a!=n-1) return 0;
			a=b;
		}
		if(a!=1) return 0;
	}
	return 1;
}

ll a[N],mk[N];
vector <ll> F[N];
vector <ll> IF; // Independent Factor Set
void unique(vector <ll> &a){ sort(a.begin(),a.end()),a.erase(unique(a.begin(),a.end()),a.end()); }

map <ll,vector<int> > M;
ll ans[N];
void Outp(){
	rep(i,1,m) ans[i]=a[ans[i]];
	sort(ans+1,ans+m+1);
	rep(i,1,m) printf("%lld ",ans[i]);
	exit(0);
}

ll Root2(ll n){
	ll x=round(sqrt(n));
	return x*x==n?x:-1;
}
ll Root3(ll n){
	ll x=round(pow(n,1./3));
	return x*x*x==n?x:-1;
}

ll KDivide(ll x){
	if(Miller_Rabin(x)) return x;
	ll y;
	if(~(y=Root2(x))) return KDivide(y);
	if(~(y=Root3(x))) return KDivide(y);
	ll U=pow(x,1./5)+4;
	vector <ll> fac;
	for(int i=1;pri[i]<=U;++i) if(x%pri[i]==0) {
		while(x%pri[i]==0) x/=pri[i];
		fac.pb(pri[i]);
	}
	if(fac.size()==1 && x==1) return fac[0];
	return -1;
}


int main(){
	rep(i,2,N-1) if(!notpri[i]) {
		pri[++pc]=i;
		for(int j=i+i;j<N;j+=i) notpri[j]=1;
	}
	n=rd(),m=rd();
	rep(i,1,n) {
		ll x=KDivide(a[i]=rd<ll>());
		if(~x) IF.pb(x);
	}
	unique(IF);
	rep(i,1,n) {
		ll x=a[i];
		for(ll y:IF) if(x%y==0) {
			while(x%y==0) x/=y;
			F[i].pb(y);
		}
		if(x>1) F[i].pb(-1),F[i].pb(-2); // invalid factor, emm... to avoid some situation we push two 
		if(F[i].size()==1 && M[F[i][0]].size()<2) M[F[i][0]].pb(i),mk[i]=1;
	}
	int c=0;
	for(auto i:M) if(i.second.size()>=2) c++;
	if(m%2==0 && c*2>=m) {
		int k=m;
		for(auto i:M) if(i.second.size()>=2) {
			if(!k) break;
			rep(j,0,1) ans[k--]=i.second[j];
		}
		Outp();
	}
	if(c*2>=m) {
		rep(i,1,n) if(!mk[i] && (int)F[i].size()<=m/2) {
			int f=1;
			for(ll x:F[i]) if(M[x].size()<2) f=0;
			if(f) {
				int k=m;
				ans[k--]=i;
				for(ll x:F[i]) {
					rep(j,0,1) ans[k--]=M[x][j];
					M.erase(x);
				}
				for(auto i:M) if(i.second.size()>=2) {
					if(!k) break;
					rep(j,0,1) ans[k--]=i.second[j];
				}
				Outp();
			}
		}
	} else {
		int k=m;
		for(auto i:M) if(i.second.size()>=2) {
			if(!k) break;
			rep(j,0,1) ans[k--]=i.second[j];
		}
		rep(i,1,n) if(!mk[i]) {
			if(!k) break;
			int f=1;
			for(ll x:F[i]) if(M[x].size()<2) f=0;
			if(f) ans[k--]=i;
		}
		if(!k) Outp();
	}
	puts("0");
}