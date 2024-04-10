#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
typedef long long LL;
const LL MX=1111;
LL n,x[MX],y[MX],r[MX],fa[MX],dep[MX],S[MX];
#define R(x) ((x)*(x))
LL D(LL k){return k==0?0:D(fa[k])+1;}
int main(){
	scanf("%lld",&n);
	for(LL i=1;i<=n;i++)scanf("%lld%lld%lld",&x[i],&y[i],&r[i]);
	
	for(LL i=1;i<=n;i++){
		LL no=0,mnr=1LL<<60;
		for(LL j=1;j<=n;j++)if(j!=i){
			if(R(x[i]-x[j])+R(y[i]-y[j])<R(r[j])&&r[j]>r[i]){
				if(r[j]<mnr)mnr=r[j],no=j;
			}
		}
		fa[i]=no;
	}
	
	for(LL i=1;i<=n;i++)dep[i]=D(i);
	
	for(LL i=1;i<=n;i++)S[i]=R(r[i]);
	
	for(LL i=1;i<=n;i++)if(fa[i])S[fa[i]]-=R(r[i]);
	
	LL ans=0LL;
	for(int i=1;i<=n;i++)ans+=(2-(dep[i]&1))*S[i];
	printf("%.12f\n",(double)ans*3.1415926535897932384626);
	return 0;
}