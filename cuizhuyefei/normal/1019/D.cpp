#include<bits/stdc++.h>
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
inline void read(ll &x) {
	x=0; char c=getchar();int f=1;
	while (!isdigit(c)) {f=(c=='-'?-1:f);c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();}x*=f;
}
const int N = 2003;
ll n,S,x[N],y[N],cro[N][N];
inline void find(int i,int j,int k){
	puts("Yes");
	printf("%lld %lld\n%lld %lld\n%lld %lld",x[i],y[i],x[j],y[j],x[k],y[k]);
	exit(0);
}
int main() {
	scanf("%lld%lld",&n,&S);
	rep(i,1,n)scanf("%lld%lld",&x[i],&y[i]);
	rep(i,1,n)rep(j,i,n)cro[i][j]=x[i]*y[j]-x[j]*y[i];
	for(int i=1;i<=n;i++)rep(j,i+1,n){
		ll a=-cro[i][j]-2*S,b=-cro[i][j]+2*S;register int k=j+1;
		for(k=j+1;k+7<=n;k+=8){
			if(cro[j][k]-cro[i][k]==a||cro[j][k]-cro[i][k]==b)find(i,j,k);
			if(cro[j][k+1]-cro[i][k+1]==a||cro[j][k+1]-cro[i][k+1]==b)find(i,j,k+1);
			if(cro[j][k+2]-cro[i][k+2]==a||cro[j][k+2]-cro[i][k+2]==b)find(i,j,k+2);
			if(cro[j][k+3]-cro[i][k+3]==a||cro[j][k+3]-cro[i][k+3]==b)find(i,j,k+3);
			if(cro[j][k+4]-cro[i][k+4]==a||cro[j][k+4]-cro[i][k+4]==b)find(i,j,k+4);
			if(cro[j][k+5]-cro[i][k+5]==a||cro[j][k+5]-cro[i][k+5]==b)find(i,j,k+5);
			if(cro[j][k+6]-cro[i][k+6]==a||cro[j][k+6]-cro[i][k+6]==b)find(i,j,k+6);
			if(cro[j][k+7]-cro[i][k+7]==a||cro[j][k+7]-cro[i][k+7]==b)find(i,j,k+7);
		}
		for(;k<=n;k++){
			register ll sum=cro[j][k]-cro[i][k];if(sum==a||sum==b)find(i,j,k);
		}
	}
	puts("No");
	return 0;
}