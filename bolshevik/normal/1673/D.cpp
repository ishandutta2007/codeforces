#include<cstdio>
using namespace std;
const int MOD=1e9+7; 
int T,b,q,y,c,r,z,ans;
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
inline void slv(int d){
	long long p=d*1ll*r/q;
	if(gcd(p,q)==d) p=q/gcd(q,d),ans=(ans+p*p)%MOD;
}
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans),ans=0){
		scanf("%d%d%d%d%d%d",&b,&q,&y,&c,&r,&z);
		if((c-b)%q||r%q) continue;
		if((c-b)/q<0||(c-b)/q>=y) continue;
		if((c+r*(z-1ll)-b)/q<0||(c+r*(z-1ll)-b)/q>=y) continue;
		if(c-r<b||c+r*1ll*z>b+q*(y-1ll)){ans=-1;continue;}
		for(int i=1;i*i<=q;++i) if(q%i==0){
			slv(i);
			if(i*i<q) slv(q/i);
		}
	}
	return 0;
}