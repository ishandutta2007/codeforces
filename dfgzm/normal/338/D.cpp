#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1000010;
int i,j,k;ll n,m,a[maxn],Gcd[maxn];
ll Mod=1,yu=0;
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
int prime[maxn],is[maxn],Max[maxn][2],cnt;
void init(){
	memset(is,-1,sizeof(is));is[1]=0;
	for(i=2;i<maxn;i++){
		if(is[i])prime[++cnt]=i;
		for(j=1;j<=cnt;j++){
			if(1ll*i*j>=maxn)break;
			is[i*j]=0;
		}
	}
}
ll X,Y;
void fun(ll a,ll b){
	if(!b){X=1;Y=0;return;}
	fun(b,a%b);int now=X;X=Y;Y=now-(a/b)*Y;
}
ll ny(ll a,ll b){
	X=Y=0;
	fun(a,b);
//	cout<<"ny "<<a<<' '<<b<<' '<<(X+b)%b<<endl;
	return (X+b)%b;
}
ll ksm(ll a,ll b){
	ll c=1;
	while(b){
		if(b&1)c=c*a;
		a=a*a;b>>=1;
	}return c;
}
__int128 I=1;
int main(){
	Gcd[0]=1;
	init();
//	long long N,M,K;
//	scanf("%lld%lld%lld",N,M,K);
//	n=N;m=M;k=K;
	cin>>n>>m>>k;
	for(i=1;i<=k;i++){
		long long w;scanf("%lld",&w);a[i]=w;
		ll G=gcd(a[i],Gcd[i-1]);G=a[i]/G;
		if(G>max(n,m)/Gcd[i-1] || G*Gcd[i-1]>max(n,m)){
			puts("NO");
			return 0;
		}Gcd[i]=Gcd[i-1]*G;
	}
	for(i=1;i<=k;i++){
		bool b=true;ll s=a[i];
		for(j=1;j<=cnt && s>=prime[j];j++){
			int num=0;
			while(s%prime[j]==0){
				s/=prime[j];
				++num;
			}
			if(num>Max[j][0]){
				Max[j][0]=num;
				Max[j][1]=i;
			}
		}
		ll MOD=Mod*s;
		if(Mod%s!=0)yu=Mod*(s-i+1)%MOD*ny(Mod,s)%MOD+s*yu%MOD*ny(s,Mod)%MOD,Mod*=s,yu+=Mod,yu%=Mod;
		yu%=Mod;
	}
//	cout<<"choose="<<yu<<" "<<Gcd[k]<<' '<<m<<endl;
	for(i=1;i<=cnt;i++){
		ll s=ksm(prime[i],Max[i][0]),A=Max[i][1];
		if(s==1)continue;
//		cout<<"... "<<s<<' '<<A<<endl;
		ll MOD=Mod*s;
		yu=I*Mod*(s-A+1)%MOD*ny(Mod,s)%MOD+I*s*yu%MOD*ny(s,Mod)%MOD,Mod*=s;
		yu%=Mod;yu+=Mod;yu%=Mod; 
//		cout<<"yu="<<yu<<endl;
	}
	if(!yu)yu=Gcd[k];
//	cout<<"choose="<<yu<<" "<<Gcd[k]<<' '<<m<<endl;
	for(i=1;i<=k;i++){
		if(gcd(yu+i-1,Gcd[k])!=a[i] || yu+i-1>m || yu>n){
			puts("NO");
			return 0;
		}
	}puts("YES");
	return 0;
}