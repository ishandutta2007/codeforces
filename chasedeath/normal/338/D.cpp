#include<cstdio>
#include<cctype>
#include<iostream>
#include<cassert>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)


//#pragma GCC optimize(2)



char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=1e5+10;


ll n,m,k;

ll b[N],a[N],mod[N];
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

ll base=3e9;
ll mul(ll x,ll y,ll P) {
	x=(x%P+P)%P,y=(y%P+P)%P;
	ll ans=0;
	for(;y;y>>=1,x=(x+x)%P) if(y&1) ans=(ans+x)%P;
	return ans;
}

ll P;
void Exgcd(ll a,ll b,ll &x,ll &y) {
	if(b==0) x=1,y=0;
	else {
		Exgcd(b,a%b,y,x);
		//y-=a/b*x;
		y-=mul(a/b,x,P);
		y=(y%P+P)%P;
	}
}


int main(){
	//cout<<900241264812+677788565226<<endl;
	//cout<<gcd(900241264812,677788565226+275);
	//ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	rep(i,1,k) cin>>b[i];
	//if(n==942751266745) cout<<b[275]<<endl;
	rep(i,1,k) mod[i]=b[i],a[i]=-i;
	//rep(i,1,k) cout<<a[i]<<' '<<mod[i]<<endl;
	ll x=1,y=0;
	rep(i,1,k) {
		ll A=x,B=a[i]-y,C=mod[i];
		ll X,Y,g=gcd(A,C);
		if(B%g) return puts("NO"),0;
		A/=g,B/=g,C/=g;
		P=C;
		Exgcd(A,C,X,Y);
		Y=mul(X,B,C);
		X=C;
		y=x*Y+y;
		if((double)x*X>1e13) return puts("NO"),0;
		x=x*X;
	}
	//cout<<"#"<<x<<' '<<y<<endl;
	y=(y%x+x)%x;
	//if(n==942751266745) cout<<x<<' '<<y<<endl;
	if(x>n||y+k>m) return puts("NO"),0;
	rep(i,1,k) {
		//cout<<"$"<<b[i]<<' '<<x<<' '<<y+i<<' '<<gcd(x,y+i)<<endl;
		//if(x>n||y+i>m) return puts("NO"),0;
		if(gcd(x,y+i)!=b[i]) return puts("NO"),0;
	}
	y+=x;
	puts("YES");
}