#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define next Cry_For_theMoon
typedef long long ll;
using namespace std;
const int MAXN=2e5+10;
ll a,b,k,x[MAXN],y[MAXN];
int main(){
	scanf("%lld%lld%lld",&a,&b,&k);
	if(!a && k){
		printf("No");return 0;
	}
	if(a && b==1 && k){
		// 
		printf("No");return 0;
	}
	x[a+b]=y[a+b]=1;
	if(a && k>a+b-2){
		printf("No");return 0; 
	} 
	printf("Yes\n");
	int tmp=b-1;
	if(k){
		x[a+b-1]=1;
		y[a+b-1-k]=1;
		tmp--;
	}
	rep(i,1,a+b-1){
		if(!tmp)break;
		if(!x[i] && !y[i])x[i]=y[i]=1,tmp--;
	}
	per(i,a+b,1)printf("%lld",x[i]);printf("\n");
	per(i,a+b,1)printf("%lld",y[i]);
	return 0;
}