#include<stdio.h>
#define R register int
bool b[301];
inline void Solve(){
	int n,x,tem;
	scanf("%d%d",&n,&x);
	for(R i=0;i!=101;i++){
		b[i]=false;
	}
	for(R i=0;i!=n;i++){
		scanf("%d",&tem);
		b[tem]=true;
	}
	for(R i=1;i!=301;i++){
		if(b[i]==false){
			if(x!=0){
				x--;
			}else{
				printf("%d\n",i-1);
				return;
			}
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}