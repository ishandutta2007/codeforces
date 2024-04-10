#include<cstdio>
typedef unsigned long long ll;
const int mo = 1e9+7;
const ll mo2 = 17ULL*mo*mo;
int n,f[404][404];
inline void add(ll &x, ll y){x+=y;x=x>=mo2?x-mo2:x;}
int main(){
	scanf("%d",&n);f[1][1]=f[1][0]=1;
	for(int i=2;i<=n;i++)
		for(int j=0;j<=n-i+1;j++){
			ll v=0;
			for(register int k=0;k<=j;k++)add(v,(ll)f[i-1][k]*f[i-1][j-k]);
			f[i][j]=v%mo*(2*j+1)%mo;v=0;
			for(register int k=0;k<=j+1;k++)add(v,(ll)f[i-1][k]*f[i-1][j-k+1]);
			f[i][j]+=v%mo*j*(j+1)%mo;f[i][j]%=mo;v=0;
			for(register int k=0;k<j;k++)add(v,(ll)f[i-1][k]*f[i-1][j-1-k]);
			f[i][j]+=v%mo;f[i][j]%=mo;
		}
	printf("%d",f[n][1]);
	return 0;
}