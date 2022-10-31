#include<stdio.h>
#define R register int
bool v1[100001],v2[100001];
int List[100001];
inline void Solve(){
	int n,m,x=0,y=0;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		v1[i]=v2[i]=false;
	}
	for(R i=1;i<=n;i++){
		scanf("%d",&m);
		for(R j=0;j!=m;j++){
			scanf("%d",List+j);
		}
		for(R j=0;j!=m;j++){
			if(v2[List[j]]==false){
				v1[i]=v2[List[j]]=true;
				break;
			}
		}
	}
	for(R i=1;i<=n;i++){
		if(v1[i]==false){
			x=i;
		}
		if(v2[i]==false){
			y=i;
		}
	}
	if(x==0){
		puts("OPTIMAL");
	}else{
		puts("IMPROVE");
		printf("%d %d\n",x,y);
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(register int i=0;i!=t;i++){
		Solve(); 
	}
	return 0;
}