#include<bits/stdc++.h>

using namespace std;

const int MX=1<<18|1;
typedef long long LL;
typedef long double lf;

LL n,N;LL b[MX],c[MX],d[MX],dc[MX],da[MX];
LL s2b=0;
LL md,g;

inline LL mul(LL x,LL y){
	static const LL M=(1ll<<21)-1;
	LL r=0;
	while(y){
		r=(r+(y&M)*x)%md;
		x=(x<<21)%md;y>>=21;
	}
	return r;
}
inline LL mul(LL x,LL y,LL md){
	static const LL M=(1ll<<21)-1;
	LL r=0;
	while(y){
		r=(r+(y&M)*x)%md;
		x=(x<<21)%md;y>>=21;
	}
	return r;
}
inline LL pw(LL x,LL y){
	LL r=1;
	while(y){
		if(y&1)r=mul(r,x);
		x=mul(x,x);y>>=1;
	}
	return r;
}
namespace FT{
	LL W[2][MX];LL rev[MX];
	LL pwgii2n[MX],pwgnii2n[MX];
	inline bool isp(LL x){
		for(LL i=2;i*i<=x;i++)if(x%i==0)return false;
		return true;
	}
	bool ckg(LL g){
		for(LL i=2;i*i<=md-1;i++)if((md-1)%i==0&&(pw(g,i)==1||pw(g,(md-1)/i)==1))return false;
		return true;
	}
	void inidft(){
		for(N=1;N<n;N<<=1);N<<=1;
		LL phi=N*n*2/__gcd(N,n*2);
		for(md=100000000/phi*phi+phi+1;!isp(md);md+=phi);
		for(g=2;!ckg(g);g++);
		rev[0]=0;
		for(LL i=1;i<N;i++)rev[i]=(rev[i>>1]>>1)|((N>>1)*(i&1));
		for(LL i=0,t=1,G=pw(g,(md-1)/N);i<N;t=mul(t,G),i++)W[0][i]=t;
		for(LL i=0;i<N;i++)W[1][i]=W[0][(N-i)&(N-1)];
		for(LL i=0,G=pw(g,(md-1)/(2*n)),G2=mul(G,G),td=G,t=1;i<n;t=mul(t,td),td=mul(td,G2),i++)
			pwgii2n[i]=t;
		for(LL i=0,G=pw(g,md-1-(md-1)/(2*n)),G2=mul(G,G),td=G,t=1;i<n;t=mul(t,td),td=mul(td,G2),i++)
			pwgnii2n[i]=t;
	}
	void fft(LL n,LL a[],LL t){
		LL* w=W[t];
		for(LL i=0;i<n;i++)if(rev[i]<i)swap(a[i],a[rev[i]]);
		for(LL i=1,x,y;i<n;i<<=1)
			for(LL j=0,d=n/(i<<1);j<n;j+=(i<<1))
				for(LL k=j,l=0;k<j+i;k++,l+=d)
					x=mul(w[l],a[k+i]),y=a[k],a[k]=(y+x)%md,a[k+i]=(md+y-x)%md;
		if(t)for(LL i=0,t=pw(n,md-2);i<n;i++)a[i]=mul(a[i],t);
	}
	LL u[MX],v[MX],ans[MX];
	void dft(LL n,LL a[]){
		#ifdef BF
		memset(ans,0,sizeof(LL)*n);
		for(LL i=0;i<n;i++){
			for(LL j=0;j<n;j++)
				ans[i]=(ans[i]+mul(pw(g,mul(mul((md-1)/n,i,md-1),j,md-1)),a[j]))%md;
		}
		memcpy(a,ans,sizeof(LL)*n);
		return;
		#endif
		memset(v,0,sizeof(LL)*N);
		memset(u,0,sizeof(LL)*N);
		for(LL i=0;i<n;i++)v[i]=mul(a[i],pwgii2n[i]);
		for(LL i=0;i<n;i++)u[i]=pwgnii2n[i];
		fft(N,v,0),fft(N,u,0);
		for(LL i=0;i<N;i++)v[i]=mul(v[i],u[i]);
		fft(N,v,1);
		memcpy(ans,v,sizeof(LL)*n);
		memset(v,0,sizeof(LL)*N);
		for(LL i=0;i<n;i++)v[i]=mul(a[n-1-i],pwgii2n[n-1-i]);
		fft(N,v,0);
		for(LL i=0;i<N;i++)v[i]=mul(v[i],u[i]);
		fft(N,v,1);
		for(LL i=0;i<n;i++)ans[i]=(ans[i]+v[n-1-i])%md;
		for(LL i=0;i<n;i++)ans[i]=(ans[i]+md-mul(a[i],pwgii2n[i]))%md;
		for(LL i=0;i<n;i++)ans[i]=mul(ans[i],pwgii2n[i]);
		memcpy(a,ans,sizeof(LL)*n);
	}
	void idft(LL n,LL a[]){
		#ifdef BF
		memset(ans,0,sizeof(LL)*n);
		for(LL i=0,t=pw(n,md-2);i<n;i++){
			for(LL j=0;j<n;j++)
				ans[i]=(ans[i]+mul(pw(g,md-1-mul(mul((md-1)/n,i,md-1),j,md-1)),a[j]))%md;
			ans[i]=mul(ans[i],t);
		}
		memcpy(a,ans,sizeof(LL)*n);
		return;
		#endif
		memset(v,0,sizeof(LL)*N);
		memset(u,0,sizeof(LL)*N);
		for(LL i=0;i<n;i++)v[i]=mul(a[i],pwgnii2n[i]);
		for(LL i=0;i<n;i++)u[i]=pwgii2n[i];
		fft(N,v,0),fft(N,u,0);
		for(LL i=0;i<N;i++)v[i]=mul(v[i],u[i]);
		fft(N,v,1);
		memcpy(ans,v,sizeof(LL)*n);
		memset(v,0,sizeof(LL)*N);
		for(LL i=0;i<n;i++)v[i]=mul(a[n-1-i],pwgnii2n[n-1-i]);
		fft(N,v,0);
		for(LL i=0;i<N;i++)v[i]=mul(v[i],u[i]);
		fft(N,v,1);
		for(LL i=0;i<n;i++)ans[i]=(ans[i]+v[n-1-i])%md;
		for(LL i=0;i<n;i++)ans[i]=(ans[i]+md-mul(a[i],pwgnii2n[i]))%md;
		for(LL i=0;i<n;i++)ans[i]=mul(ans[i],pwgnii2n[i]);
		for(LL i=0,t=pw(n,md-2);i<n;i++)ans[i]=mul(ans[i],t);
		memcpy(a,ans,sizeof(LL)*n);
	}
}
using FT::inidft;
using FT::dft;
using FT::idft;
LL A[MX],C[MX],D[MX],DC[MX],DA[MX];
LL tans[MX],td[MX];LL ta[MX];
LL ansc;LL ans[2][MX];

bool ck(LL a0){
	if(abs(a0)>10000)return false;
	for(LL i=0;i<n;i++)ta[i]=a0+da[i];
	//for(LL i=0;i<n;i++)cerr<<ta[i]<<' ';cerr<<endl;
	/*
	for(LL i=0;i<n;i++)tans[i]=(md+ta[i])%md;
	dft(n,tans);
	for(LL i=0;i<n;i++)tans[i]=mul(tans[i],D[i]);
	idft(n,tans);
	LL s2a=0;
	for(LL i=0;i<n;i++)s2a+=ta[i]*ta[i];
	for(LL i=0;i<n;i++)if((c[i]+md)%md!=(s2b+s2a+tans[i])%md)return false;
	*/
	
	for(LL i=0;i<ansc;i++){
		bool flg=true;
		for(LL j=0;j<n;j++)if(ta[j]!=ans[i][j]){flg=false;break;}
		if(flg)return false;
	}
	//for(LL i=0;i<n;i++)if(!isint(tans[i]))return false;
	for(LL i=0;i<n;i++)ans[ansc][i]=ta[i];
	ansc++;
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	inidft();
	for(LL i=0;i<n;i++)cin>>b[i];
	for(LL i=0;i<n;i++)cin>>c[i];
	for(LL i=0;i<n;i++)s2b+=b[i]*b[i];
	for(LL i=0;i<n;i++)d[i]=-2*b[(n-i)%n];
	for(LL i=0;i<n;i++)D[i]=(md+d[i])%md;
	dft(n,D);
	
	for(LL i=0;i<n;i++)dc[i]=c[i]-c[(i+n-1)%n];
	for(LL i=0;i<n;i++)DC[i]=(md+dc[i])%md;
	dft(n,DC);
	for(LL i=0;i<n;i++)assert(D[i]!=0),DA[i]=mul(DC[i],pw(D[i],md-2));
	idft(n,DA);
	for(LL i=0;i<n;i++){
		if(DA[i]>10000&&DA[i]<md-10000)return cout<<0<<endl,0;
		da[i]=(DA[i]<=10000?DA[i]:DA[i]-md);
	}
	da[0]=0;
	for(LL i=1;i<n;i++)da[i]+=da[i-1];
	#ifdef DBG
	for(LL i=0;i<n;i++)cerr<<da[i]<<endl;
	#endif
	LL k0=0,k1=0,k2=0;
	//k2a0^2+k1a0+k0==0
	for(LL i=0;i<n;i++)k2+=1,k1+=2*da[i],k0+=da[i]*da[i];
	for(LL i=0;i<n;i++)k1+=d[i],k0+=d[(n-i)%n]*da[i];
	for(LL i=0;i<n;i++)k0+=b[i]*b[i];
	k0-=c[0];
	
	LL DLT=k1*k1-4*k0*k2;
	LL dlt=(LL)sqrt(DLT);while(dlt*dlt>DLT)--dlt;while(dlt*dlt<DLT)++dlt;
	if(dlt*dlt!=DLT)return cout<<0<<endl,0;
	if((-k1-dlt)%(k2*2)==0)ck((-k1-dlt)/(k2*2));
	if(dlt&&(-k1+dlt)%(k2*2)==0)ck((-k1+dlt)/(k2*2));
	cout<<ansc<<endl;
	for(LL i=0;i<ansc;cout<<endl,i++)
		for(LL j=0;j<n;j++)cout<<ans[i][j]<<' ';
	return 0;
}