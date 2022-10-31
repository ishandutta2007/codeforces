#include<stdio.h>
#include<map>
using namespace std;
#define R register int
#define L long long
map<L,int>Q;
map<L,bool>P;
int main(){
	int n,x,lt=-1;
	scanf("%d",&n);
	L ans=0,sum=0;
	P[0]=true;
	Q[0]=0;
	for(R i=1;i<=n;i++){
		scanf("%d",&x);
		sum+=x;
		if(P[sum]==true&&Q[sum]>lt){
			lt=Q[sum];
		}
		Q[sum]=i;
		P[sum]=true;
		ans+=i-lt-1;
	}
	printf("%lld",ans);
	return 0;
}