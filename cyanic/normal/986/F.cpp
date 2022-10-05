#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const ll inf=1e18+99;
const int N=2000005,Q=10005;
struct node{ll n,k;int id;} q[Q];
bitset<32000005> flag;
int p[N],ans[Q],cnt;
vector<ll> d;

void init(int n){
	rep(i,2,n){
		if(!flag[i]) p[++cnt]=i;
		for(int j=1;j<=cnt&&i*p[j]<=n;j++){
			flag[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}

void factor(ll x){
	d.clear();
	for(int i=1;(ll)p[i]*p[i]<=x;i++){
		if(x%p[i]) continue;
		d.pb(p[i]);
		for(;x%p[i]==0;x/=p[i]);
	}
	if(x>=2) d.pb(x);
}

ll power(ll x,ll p,ll mod){
	ll res=1;
	for(;p;p>>=1,x=x*x%mod)
		if(p&1) res=res*x%mod;
	return res;
}
int fix(int x,int mod){
	return x>=mod?x-mod:x;
}
void cmin(ll &a,ll b){
	if(b<a) a=b;
}

ll f[N],last;
int solve(ll n,ll k){
	if(k==1) return 0;
	if(d.size()==1) return n%k==0;
	if(d.size()==2){
		ll p=d[0],q=d[1];
		if(p==q) return n%p==0;
		ll t=n%p*power(q%p,p-2,p)%p;
		return t*q<=n;
	}
	if(k!=last){
		int l=d[0];
		fill(f,f+l,inf),f[0]=0;
		for(int i=1;i<d.size();i++)
			for(int k=0,step=d[i]%l,T=2*l;T;k=fix(k+step,l),T--)
				cmin(f[fix(k+step,l)],f[k]+d[i]);
		last=k;
	}
	return f[n%d[0]]<=n;
}

int main(){
	init(32000000);
	int T; read(T);
	rep(i,1,T) read(q[i].n),read(q[i].k),q[i].id=i;
	sort(q+1,q+T+1,[&](node a,node b){
		return a.k<b.k;
	});
	rep(i,1,T){
		if(q[i].k!=q[i-1].k) factor(q[i].k);
		ans[q[i].id]=solve(q[i].n,q[i].k);
	}
	rep(i,1,T) puts(ans[i]?"YES":"NO");
	return 0;
}