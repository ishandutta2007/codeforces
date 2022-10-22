#include<cstdio>

int main(){
	int t,k,n,s;
	scanf("%d%d%d",&t,&k,&n);
	s=t*n*k/100;
	for(int i=0;i<t;i++){
		if(s/k>0){
			printf("%d ",k);
			s-=k;
		}
		else{
			printf("%d ",s);
			s-=s;
		}
	}
}