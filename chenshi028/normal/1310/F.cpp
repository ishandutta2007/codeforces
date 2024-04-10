#include<cstdio>
#include<iostream>
#include<unordered_map>
using namespace std;
#define ull unsigned long long
inline int qpw(ull b,int f,int MOD){int res=1;for(b%=MOD;f;f>>=1,b=b*b%MOD) if(f&1) res=res*b%MOD;return res;}
ull multiply_powers_of_2(int,int);
ull multiply(ull a,ull b){
	ull res=0;
	int yny[70],wb5[70],whx=0,cyf=0;
	for(int i=0;i<64;++i) if((a>>i)&1) yny[++whx]=i;
	for(int i=0;i<64;++i) if((b>>i)&1) wb5[++cyf]=i;
	for(int i=1;i<=whx;++i) for(int j=1;j<=cyf;++j) res^=multiply_powers_of_2(yny[i],wb5[j]);
	return res;
}
ull dp[99][99];
ull multiply_powers_of_2(int a,int b){
	if(!a||!b) return 1ull<<(a+b);
	if(dp[a][b]) return dp[a][b];
	int n=1;
	for(;(1<<n)<=max(a,b);++n);
	ull power=1ull<<(1<<(--n));
	if(a>=(1<<n)&&b>=(1<<n)) return dp[a][b]=multiply(power*3/2,multiply_powers_of_2(a-(1<<n),b-(1<<n)));
	else if(a>=(1<<n)) return dp[a][b]=multiply_powers_of_2(a-(1<<n),b)*power;
	else return dp[a][b]=multiply_powers_of_2(a,b-(1<<n))*power;
}
inline ull qp(ull b,ull f){ull res=1;for(;f;f>>=1,b=multiply(b,b)) if(f&1) res=multiply(res,b);return res;}
const int p[]={3,5,17,257,641,65537,6700417};const ull F=(((1ull<<63)-1)<<1)+1;
int T;ull a,b,z[7],c,d;__int128 ans;unordered_map<ull,int> mp;
int main(){
	for(scanf("%d",&T);T--;(ans<0)?printf("-1\n"):printf("%llu\n",(ull)(ans%F)),ans=0){
		scanf("%llu%llu",&a,&b);
		for(int i=0,B,flg=0;i<7;++i,flg=0){
			mp.clear();
			c=qp(a,F/p[i]);d=qp(b,F/p[i]);
			for(B=1;B*B<=p[i];++B);
			for(int j=0;j<=B;d=multiply(d,c)) mp[d]=j++;
			d=c=qp(c,B);
			for(int j=1;j<=B;d=multiply(d,c),++j) if(mp.count(d)){flg=1;z[i]=j*B-mp[d];break;}
			if(!flg){ans=-1;break;}
		}
		if(ans+1) for(int i=0;i<7;++i) ans+=F/p[i]*qpw(F/p[i],p[i]-2,p[i])*(__int128)z[i];
	}
	return 0;
}