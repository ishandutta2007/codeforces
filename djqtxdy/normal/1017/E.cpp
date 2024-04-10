#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define big 20160116
#define INF 2147483647
#define pq priority_queue
#define rank rk124232
#define y1 y20160116
#define y0 y20160110
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
namespace Mymath{
	LL qp(LL x,LL p,LL mod){
		LL ans=1;
		while (p){
			if (p&1) ans=ans*x%mod;
			x=x*x%mod;
			p>>=1;
		}
		return ans;
	}
	LL inv(LL x,LL mod){
		return qp(x,mod-2,mod);
	}
	LL C(LL N,LL K,LL fact[],LL mod){
		return fact[N]*inv(fact[K],mod)%mod*inv(fact[N-K],mod)%mod;
	}
	template <typename Tp> Tp gcd(Tp A,Tp B){
		if (B==0) return A;
		return gcd(B,A%B);
	}
	template <typename Tp> Tp lcm(Tp A,Tp B){
		return A*B/gcd(A,B);
	}
};
namespace fwt{
	using namespace Mymath;
	void FWT(int a[],int n,LL mod)
	{
	    for(int d=1;d<n;d<<=1)
	        for(int m=d<<1,i=0;i<n;i+=m)
	            for(int j=0;j<d;j++)
	            {
	                int x=a[i+j],y=a[i+j+d];
	                a[i+j]=(x+y)%mod,a[i+j+d]=(x-y+mod)%mod;
	                //xor:a[i+j]=x+y,a[i+j+d]=x-y;
	                //and:a[i+j]=x+y;
	                //or:a[i+j+d]=x+y;
	            }
	}

	void UFWT(int a[],int n,LL mod)
	{
		LL rev=inv(2,mod);
	    for(int d=1;d<n;d<<=1)
	        for(int m=d<<1,i=0;i<n;i+=m)
	            for(int j=0;j<d;j++)
	            {
	                int x=a[i+j],y=a[i+j+d];
	                a[i+j]=1LL*(x+y)*rev%mod,a[i+j+d]=(1LL*(x-y)*rev%mod+mod)%mod;
	                //xor:a[i+j]=(x+y)/2,a[i+j+d]=(x-y)/2;
	                //and:a[i+j]=x-y;
	                //or:a[i+j+d]=y-x;
	            }
	}
	void solve(int a[],int b[],int n,LL mod)
	{
	    FWT(a,n,mod);
	    FWT(b,n,mod);
	    for(int i=0;i<n;i++) a[i]=1LL*a[i]*b[i]%mod;
	    UFWT(a,n,mod);
	}
};
const int Maxn=100005;
struct P{
	LL x,y;
	P(LL X,LL Y){
		x=X,y=Y;
	}
	P (){
		x=y=0;
	}
	P operator +(P p){
		return P(x+p.x,y+p.y);
	}
	P operator -(P p){
		return P(x-p.x,y-p.y);
	}
	P operator *(double k){
		return P(x*k,y*k);
	}
	LL det(P p){
		return x*p.y-y*p.x;
	}
	LL dot(P p){
		return x*p.x+y*p.y;
	} 
	bool operator <(const P&p)const{
		if (x!=p.x) return x<p.x;
		return y<p.y;
	}
	double dist(){
		return sqrt((double)x*x+y*y);
	}
};
P A[Maxn],B[Maxn];
int n,m;
vector<P> xp,yp;
#define sz ret.size()
vector<P> build(P X[],int l){
	vector<P> ret;
	sort(X+1,X+1+l);
	//for (int i=1;i<=l;i++) cout<<'f'<<X[i].x<<' '<<X[i].y<<endl;
	ret.pb(X[1]);
	for (int i=2;i<=l;i++){
		while (sz>=2 && (ret[sz-2]-X[i]).det(ret[sz-1]-X[i])>=0){
			//cout<<"fff"<<' '<<(ret[sz-2]-X[i]).det(ret[sz-1]-X[i])<<endl;
			ret.pop_back();
		}
		ret.pb(X[i]);
		//cout<<ret.size()<<endl;
	}
	int rs=ret.size()+1;
	for (int i=l-1;i>=1;i--){
		while (sz>=rs && (ret[sz-2]-X[i]).det(ret[sz-1]-X[i])>=0){
			
			ret.pop_back();
		}
		ret.pb(X[i]);
	}
	return ret;
}
using namespace Mymath;
const LL mod1=998244353;
const LL mod2=1000000007;
LL aa[Maxn],ab[Maxn];
LL pa1[Maxn],pa2[Maxn];
LL pb1[Maxn],pb2[Maxn]; 
LL Fa1[Maxn],Fa2[Maxn];
LL ifa1[Maxn],ifa2[Maxn];
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++){
		A[i].x=read();A[i].y=read();
	}
	for (int i=1;i<=m;i++){
		B[i].x=read();B[i].y=read();
	}
	xp=build(A,n);
	yp=build(B,m);
	//return 0; 
	if (xp.size()!=yp.size()){
		printf("NO\n");
		return 0;
	}
	for (int i=1;i<xp.size()-1;i++){
		P ta=xp[i-1]-xp[i],tb=xp[i+1]-xp[i];
		LL X=ta.det(tb);//X=abs(X);
		aa[i]=X;
	}
	{
		P ta=xp[1]-xp[0],tb=xp[xp.size()-2]-xp[0];
		LL X=ta.det(tb);X=-(X);
		aa[0]=aa[xp.size()-1]=X;
	}
	for (int i=1;i<yp.size()-1;i++){
		P ta=yp[i-1]-yp[i],tb=yp[i+1]-yp[i];
		LL X=ta.det(tb);
		//X=abs(X);
		ab[i]=X;
	}
	{
		P ta=yp[1]-yp[0],tb=yp[yp.size()-2]-yp[0];
		LL X=ta.det(tb);X=-X;
		//X=abs(X);
		ab[0]=ab[yp.size()-1]=X;
	}
	//for (int i=0;i<xp.size();i++) cout<<aa[i]<<' '<<ab[i]<<endl;
	vector<pair<LL,LL> > P1,P2;
	P1.pb(mp(0,0));
	for (int i=0;i<xp.size()-1;i++){
		P ed=xp[i+1]-xp[i];
		LL dd=ed.x*ed.x+ed.y*ed.y;
		LL h1=dd%mod1*239429834+aa[i]%mod1*834728734+aa[i+1]%mod1*349828333;
		h1%=mod1;
		LL h2=dd%mod2*239429834+aa[i]%mod2*834728734+aa[i+1]%mod2*349828333;
		h2%=mod2;
		P1.pb(mp(h1,h2));
		//cout<<dd<<' '<<aa[i]<<' '<<aa[i+1]<<endl;
		//cout<<h1<<' '<<h2<<endl;
	}
	P2.pb(mp(0,0));
	for (int i=0;i<yp.size()-1;i++){
		P ed=yp[i+1]-yp[i];
		LL dd=ed.x*ed.x+ed.y*ed.y;
		LL h1=dd%mod1*239429834+ab[i]%mod1*834728734+ab[i+1]%mod1*349828333;
		h1%=mod1;
		LL h2=dd%mod2*239429834+ab[i]%mod2*834728734+ab[i+1]%mod2*349828333;
		h2%=mod2;
		P2.pb(mp(h1,h2));
		//cout<<dd<<' '<<ab[i]<<' '<<ab[i+1]<<endl;
		//cout<<h1<<' '<<h2<<endl;
	}
	int L=P1.size()-1;
	/*
	for (int i=1;i<=L;i++){
		cout<<P1[i].first<<' '<<P1[i].second<<endl;
	}
	for (int i=1;i<=L;i++){
		cout<<P2[i].first<<' '<<P2[i].second<<endl;
	}*/
	for (int i=1;i<=L;i++){
		pa1[i]=pa1[i-1]*93482874+P1[i].first;
		pa1[i]%=mod1;
		pa2[i]=pa2[i-1]*93482874+P1[i].second;
		pa2[i]%=mod2;
	}
	for (int i=1;i<=L;i++){
		pb1[i]=pb1[i-1]*93482874+P2[i].first;
		pb1[i]%=mod1;
		pb2[i]=pb2[i-1]*93482874+P2[i].second;
		pb2[i]%=mod2;
	}
	Fa1[0]=Fa2[0]=1;
	for (int i=1;i<Maxn;i++){
		Fa1[i]=Fa1[i-1]*93482874%mod1;
		Fa2[i]=Fa2[i-1]*93482874%mod2;
	}
	//cout<<"H"<<" "<<pa1[L]<<' '<<pa2[L]<<endl;
	for (int i=1;i<=L;i++){
		LL h1=pa1[L]-pa1[i-1]*Fa1[L-i+1];
		h1=(h1%mod1+mod1)%mod1;
		h1=h1*Fa1[i-1]+pa1[i-1];
		h1%=mod1;
		LL h2=pa2[L]-pa2[i-1]*Fa2[L-i+1];
		h2=(h2%mod2+mod2)%mod2;
		h2=h2*Fa2[i-1]+pa2[i-1];
		
		h2%=mod2;
		//cout<<"hh"<<' '<<h1<<' '<<h2<<endl;
		if (h1==pb1[L] && h2==pb2[L]){
			printf("YES\n");
			return 0;
		}
	}
	//cerr<<123<<endl;
	printf("NO\n");
	return 0;
}