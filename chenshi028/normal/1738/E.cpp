#include<cstdio>
#include<map>
using namespace std;
const int o=1e5+10,MOD=998244353;
int T,n,a[o],ans,fac[o],inv[o];long long s;map<long long,int> mp1,mp2;
inline int C(int x,int y){return fac[x]*1ll*inv[y]%MOD*inv[x-y]%MOD;}
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans),mp1.clear(),mp2.clear()){
		scanf("%d",&n);s=0;ans=1;inv[1]=1;
		for(int i=2;i<=n;++i) inv[i]=MOD-MOD/i*1ll*inv[MOD%i]%MOD;
		for(int i=fac[0]=inv[0]=1;i<=n;++i) fac[i]=fac[i-1]*1ll*i%MOD,inv[i]=inv[i-1]*1ll*inv[i]%MOD;
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),++mp1[s+=a[i]];
		if(!s){
			for(int i=1;i<n;++i) ans=ans*2%MOD;
			continue;
		}
		s=0;
		for(int i=n;i;--i) ++mp2[s+=a[i]];
		for(map<long long,int>::iterator iter=mp1.begin();iter!=mp1.end();++iter){
			int x=(*iter).second,y=mp2[(*iter).first],coef;
			if((*iter).first*2==s){
				for(int i=1;i<=x;++i) ans=ans*2%MOD;
				break;
			}
			if((*iter).first*2>s) break;
			if(!y||!(*iter).first) continue;
			ans=ans*2%MOD;coef=0;
			for(int i=1;i<=x&&i<=y;++i) coef=(coef+C(x,i)*1ll*C(y,i))%MOD;
			ans=ans*1ll*(coef+1ll)%MOD*(MOD+1)/2%MOD;
		}
		int x=mp1[0],y=mp2[0],coef=0;
		for(int i=0;i<=x&&i<=y;++i) coef=(coef+C(x,i)*1ll*C(y,i))%MOD;
		ans=ans*1ll*coef%MOD;
	}
	return 0;
}