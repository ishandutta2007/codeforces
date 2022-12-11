#include <cstdio>
using namespace std;
int n,sums[100010],fir,fc,sec,ans[100010];
int main(){
	scanf("%d",&n);
	sums[0]=-0x7fffffff;
	for(int i=1;i<=n;++i)
		scanf("%d",&sums[i]);
	for(int i=n;i>=1;--i){
		if(sums[i]>fir)fir=sums[i],sec=fir,fc=1;
		else if(sums[i]==fir)++fc;
		else if(sums[i]>sec)sec=sums[i];
		if(sums[i]==fir)ans[i]=fc>1;
		else ans[i]=fir-sums[i]+1;
	}
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);putchar('\n');
	return 0;
}