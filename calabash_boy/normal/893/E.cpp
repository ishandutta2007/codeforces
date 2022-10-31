#pragma warning(disable:4786)//  
#pragma comment(linker, "/STACK:102400000,102400000")// 
#include <bits/stdc++.h>
using namespace std;
#define lson 2*i    
#define rson 2*i+1    
#define LS l,mid,lson    
#define RS mid+1,r,rson    
#define UP(i,x,y) for(i=x;i<=y;i++)    
#define DOWN(i,x,y) for(i=x;i>=y;i--)    
typedef long long LL;
const int MOD = 1e9+7;
const int maxn = 2e6+5;
LL fac[maxn];
LL inv[maxn];
int x,y,Q;
LL bit[1005];
inline LL power(LL a,LL n){
	LL ret=1;LL now=a;
	while(n!=0){
		if(n&1)
			ret=ret*now%MOD;
		now=now*now%MOD;
		n>>=1;
	}
	return ret;
}
LL C(LL n,LL k){
	return fac[n]*inv[n-k]%MOD*inv[k]%MOD;
}
void init(){
	fac[0]=1;
	for(int i=1;i<=2000000;i++){
		fac[i]=1LL*fac[i-1]*i%MOD;	
	}
	inv[2000000]=power(fac[2000000],MOD-2);
	for(int i=2000000;i>=1;i--){
		inv[i-1]=1LL*inv[i]*i%MOD;	
	}
}
void solve(){
	scanf("%d%d",&x,&y);
	memset(bit,0,sizeof bit);
	int cnt=0;
	for(int i=2;1LL*i*i<=x;i++){
		if(x%i==0){
			cnt++;
			bit[cnt]=0;
			while(x%i==0){
				x/=i;
				bit[cnt]++;
			}
		}
	}
	if(x>1) cnt++,bit[cnt]=1;
	LL ret=power(2LL,y-1);
	for(int i=1;i<=cnt;i++){
		ret=ret*C(bit[i]+y-1,bit[i])%MOD;	
	}
	int res=ret;
	printf("%d\n",res);
}
int main(){
	init();
	scanf("%d",&Q);
	while(Q--){
		solve();
	}
	return 0;
}