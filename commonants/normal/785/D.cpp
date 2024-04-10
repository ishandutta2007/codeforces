#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
typedef long long LL;
const LL md=1000000007LL;
const int MX=400111;
LL fac[MX],facinv[MX],inv[MX];
inline LL C(LL x,LL y){
	return fac[x]*facinv[y]%md*facinv[x-y]%md;
}
void ini(){
	fac[0]=1LL,facinv[0]=1LL;
	inv[1]=1LL;
	for(LL i=2;i<=400000;i++)inv[i]=(md-md/i)*inv[md%i]%md;
	for(LL i=1;i<=400000;i++)fac[i]=fac[i-1]*i%md;
	for(LL i=1;i<=400000;i++)facinv[i]=facinv[i-1]*inv[i]%md;
}
char s[MX];
int n;LL lc,rc;
int main(){
	ini();
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)if(s[i]=='(')lc++;else rc++;
	LL tx=0LL,ty=rc,ans=0LL;
	for(LL i=0;i<n;i++){
		if(!ty)break;
		if(s[i]=='('){
			tx++;ans=(ans+C(tx+ty-1,ty-1))%md;
		}else ty--;
	}
	printf("%lld\n",ans);
	return 0;
}