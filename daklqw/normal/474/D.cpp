#include <iostream>
using namespace std;
#define LLINT long long
LLINT f[100010],pre[100010];
int T,k,a,b;
int main(){
	scanf("%d %d",&T,&k);
	f[0]=1;
	for(int i=1;i<=100000;++i){
		f[i]=(f[i-1]+(i<k?0:f[i-k]))%1000000007;
		pre[i]=(pre[i-1]+f[i])%1000000007;
	}
	while(T--){
		scanf("%d %d",&a,&b);
		printf("%d\n",((LLINT)(pre[b]-pre[a-1]+1000000007)%1000000007));
	}
	return 0;
}