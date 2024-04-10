#include<stdio.h>
#include<algorithm>
#define R register int
int p[200000];
int main(){
	int n,a,b,k,x,t;
	scanf("%d%d%d%d",&n,&a,&b,&k);
	b+=a;
	for(R i=0;i!=n;i++){
		scanf("%d",&x);
		t=x%b;
		if(t==0){
			t=b;
		}
		if(t<=a){
			p[i]=0;
		}else{
			p[i]=(t-1)/a;
		}
	}
	std::sort(p,p+n);
	x=0;
	for(R i=0;i!=n;i++){
		if(k>=p[i]){
			x++;
			k-=p[i];
		}else{
			break;
		}
	}
	printf("%d",x);
	return 0;
}