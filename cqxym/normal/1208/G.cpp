#include<stdio.h>
#include<algorithm>
using namespace std;
int p[1000001];
int main(){
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	if(k==1){
		printf("3");
		return 0;
	}
	for(i=1;i<=n;i++){
		p[i]=i;
	}
	for(i=2;i<=n;i++){
		if(p[i]==i){
			p[i]--;
			for(j=i+i;j<=n;j+=i){
				p[j]-=p[j]/i;
			}
		}
	}
	sort(p+1,p+1+n);
	long long s=2;
	k+=3;
	for(i=3;i<k;i++){
		s+=p[i];
	}
	printf("%lld",s);
	return 0;
}