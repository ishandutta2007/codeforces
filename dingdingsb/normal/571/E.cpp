#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef __int128 ll;
const int mod=1e9+7;
struct mint{
	int x;mint(int o=0){x=o;}mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}mint&operator-=(mint a){return(x+=mod-a.x)%=mod,*this;}
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}
	mint&operator/=(mint a){return*this*=(a^=mod-2);}friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}
	friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}friend mint operator^(mint a, int b){return a^=b;}
};
const int N=110;
int n,a[N],b[N];
int u[N],v[N],w[N],l[N];
ll p[N],q[N];
void exgcd(ll x,ll y,ll&a,ll&b){
	if(!y)return a=1,b=0,void();
	exgcd(y,x%y,b,a);b-=(x/y)*a;
}
vector<int>prs;
void ins(int x){
	for(int i=2;i*i<=x;i++)
		while(x%i==0)prs.pb(i),x/=i;
	if(x>1)prs.pb(x);
}
bool ispow(int a,int b){
	//a^x=b
	if(a==1&&b>1)return 0;
	ll res=1;
	while(res<b)res*=a;
	return res==b;
}
struct vec{
	vector<ll>a;
	ll&operator[](int x){return a[x];}
	void init(int x){
		a.resize(prs.size());
		for(ll i=2;i*i<=x;i++)
			while(x%i==0){
				a[lower_bound(prs.begin(),prs.end(),i)-prs.begin()]++;
				x/=i;
			}
		if(x>1)a[lower_bound(prs.begin(),prs.end(),x)-prs.begin()]++;
	}
	friend vec operator+(vec a,vec b){
		for(int i=0;i<(int)prs.size();i++)a[i]+=b[i];
		return a;
	}
	friend vec operator-(vec a,vec b){
		for(int i=0;i<(int)prs.size();i++)a[i]-=b[i];
		return a;
	}
	friend vec operator*(vec a,ll b){
		for(int i=0;i<(int)prs.size();i++)a[i]*=b;
		return a;
	}
	friend bool operator==(vec a,vec b){return a.a==b.a;}
	friend bool operator!=(vec a,vec b){return a.a!=b.a;}
	friend bool operator<(vec a,vec b){return a.a<b.a;}
	friend bool operator%(vec a,vec b){
		//a,b
		for(int i=0;i<(int)prs.size();i++)
			for(int j=i+1;j<(int)prs.size();j++)
				if(a[i]*b[j]-a[j]*b[i])
					return 0;
		return 1;
	}
	friend pair<int,int>operator^(vec a,vec b){
		//
		for(int i=0;i<(int)prs.size();i++)
			for(int j=i+1;j<(int)prs.size();j++)
				if(a[i]*b[j]-a[j]*b[i])
					return mp(i,j);
		exit(-1);
	}
}A[N],B[N],X;
#define orz return puts("-1"),0
pair<int,int>deal(vec v){
	// mp(a,b)  v = a/b b1
	for(int i=0;i<(int)prs.size();i++)if(B[1][i]){
		int x=v[i],y=B[1][i];
		return mp(x/__gcd(x,y),y/__gcd(x,y));
	}
	exit(-1);
}
signed main(){
	read(n);
	for(int i=1;i<=n;i++)read(a[i],b[i]),ins(a[i]),ins(b[i]);
	sort(prs.begin(),prs.end());prs.resize(unique(prs.begin(),prs.end())-prs.begin());
	for(int i=1;i<=n;i++)if(b[i]==1){
		for(int j=1;j<=n;j++)if(a[i]%a[j]||!ispow(b[j],a[i]/a[j]))orz;
		writeln(a[i]);return 0;
	}
	for(int i=1;i<=n;i++)A[i].init(a[i]),B[i].init(b[i]);
	for(int i=1;i<n;i++)if(!(B[i]%B[i+1])){
		pair<int,int>r=B[i]^B[i+1];
		ll u=-(A[i][r.se]*B[i][r.fi]*B[i+1][r.fi]-A[i+1][r.se]*B[i][r.fi]*B[i+1][r.fi]-A[i][r.fi]*B[i][r.se]*B[i+1][r.fi]+A[i+1][r.fi]*B[i][r.fi]*B[i+1][r.se]);
		ll v=B[i][r.se]*B[i+1][r.fi]-B[i][r.fi]*B[i+1][r.se];
		if(u%v)orz;
		//x
		int val=u/v;
		u=i;if(!B[u][r.fi])u=i+1;
		assert(B[u][r.fi]);
		if((val-A[u][r.fi])%B[u][r.fi])orz;
		v=(val-A[u][r.fi])/B[u][r.fi];
		if(v<0)orz;
		X=A[u]+B[u]*v;
		//chk
		for(int i=1;i<=n;i++){
			for(u=0;!B[i][u];u++);
			if((X[u]-A[i][u])%B[i][u])orz;
			v=(X[u]-A[i][u])/B[i][u];
			if(v<0)orz;
			if(X!=A[i]+B[i]*v)orz;
		}
		mint ans=1;
		for(int i=0;i<(int)prs.size();i++)
			ans*=(mint(prs[i])^(X[i]%(mod-1)));
		writeln(ans.x);
		return 0;
	}
	//B[i] (A[i]-A[1])  B[?] 
	for(int i=2;i<=n;i++)
		if(!((A[i]-A[1])%B[1]))
			orz;
	for(int i=2;i<=n;i++)if(a[i]<a[1])swap(a[i],a[1]),swap(b[i],b[1]);
	// A1 + ui/vi B1 + wi/li ki B1  ki 
	ll M=1;
	for(int i=1;i<=n;i++){
		tie(u[i],v[i])=deal(A[i]-A[1]);
		tie(w[i],l[i])=deal(B[i]);
		M=M/__gcd(M,(ll)v[i])*v[i];
		M=M/__gcd(M,(ll)l[i])*l[i];
	}
	//pi + qi ki  =X  X>=pi X%qi=pi
	for(int i=1;i<=n;i++)p[i]=M/v[i]*u[i],q[i]=M/l[i]*w[i];
	//excrt
	M=1;ll R=0;
	for(int i=1;i<=n;i++){
		//x mod m = r
		//x mod M = R
		//x mod lcm(M,m) = ?
		ll m=q[i],r=p[i],d=__gcd(M,m);
		if((R-r)%d)orz;
		ll k1,k2;exgcd(M/d,m/d,k1,k2);
		k1*=(r-R)/d;ll nm=M/d*m;k1%=nm;
		R=k1*M+R;R=(R%nm+nm)%nm;M=nm;
	}
	for(int i=1;i<=n;i++)while(R<p[i])R+=M;
	mint ans=1;
	//k1
	ll k1=(R-p[1])/q[1];
	for(int i=0;i<(int)prs.size();i++)
		ans*=(mint(prs[i])^((A[1][i]+B[1][i]*k1)%(mod-1)));
	writeln(ans.x);
	cerr<<"luogu is the greatest OJ!!";
}