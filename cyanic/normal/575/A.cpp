#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define clz __builtin_clz
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

ll P;
const int N=100005,M=20;
struct mat{
	ll x[2][2];
	ll* operator [](int i){ return x[i]; }
	mat operator * (mat y){
		mat a;
		REP(i,2)REP(j,2)
			a[i][j]=(x[i][0]*y[0][j]+x[i][1]*y[1][j])%P;
		return a;
	}
}I,a[N][M],ans;
map<ll,ll> ss;
set<ll> p;
ll s[N],K;
int n,m;

mat power(mat a,ll p) {
	mat res=I;
	for(;p;p>>=1,a=a*a)
		if(p&1)res=res*a;
	return res;
}
mat qry(int l,int r) {
	if(l>r)return I;
	int lg=31-clz(r-l+1);
	return qry(l,r-(1<<lg))*a[r][lg];
}
ll S(ll k){
	return ss.count(k)?ss[k]:s[(k+n)%n];
}
mat nw(ll i) {
	mat a;
	a[0][0]=0,a[0][1]=S(i-1);
	a[1][0]=1,a[1][1]=S(i);
	return a;
}

int main(){
	I[0][0]=I[1][1]=1,ans=I;
	read(K),read(P),read(n);
	REP(i,n)read(s[i]);
	for(read(m);m--;){
		ll j,v;
		read(j),read(v),ss[j]=v;
		p.insert(j),p.insert(j+1);
	}
	REP(i,n){
		a[i][0]=nw(i);
		REP(j,18)if(i>=(1<<j))
			a[i][j+1]=a[i-(1<<j)][j]*a[i][j];
	}
	mat full=qry(0,n-1);
	for(ll i=0;i<K;)
		if(*p.begin()==i+1){
			ans=ans*nw(++i);
			p.erase(p.begin());
		}
		else{
			ll l=i+1,r=(!p.empty()&&*p.begin()<=K?r=*p.begin()-1:K);
			if(l/n==r/n)ans=ans*qry(l%n,r%n);
			else ans=ans*qry(l%n,n-1)*power(full,r/n-l/n-1)*qry(0,r%n);
			i=r;
		}
	cout<<ans[1][0]%P<<endl;
	return 0;
}