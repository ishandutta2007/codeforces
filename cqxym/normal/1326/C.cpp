#include<stdio.h>
#include<vector>
using namespace std;
#define R register int
#define L long long
int main(){
	int n,k,ans=1,x;
	scanf("%d%d",&n,&k);
	L sum=0;
	vector<int>V;
	for(int i=0;i!=n;i++){
		scanf("%d",&x);
		if(x+k>n){
			sum+=x;
			V.push_back(i);
		}
	}
	x=V.size();
	for(R i=1;i!=x;i++){
		ans=(L)ans*(V[i]-V[i-1])%998244353;
	}
	printf("%lld",sum);
	printf(" %d",ans);
	return 0;
}