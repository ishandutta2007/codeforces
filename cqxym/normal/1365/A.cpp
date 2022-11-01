#include<stdio.h>
#define R register int
bool v[2][50];
inline void Solve(){
	int n,m,x,y=0;
	scanf("%d%d",&n,&m);
	for(R i=0;i!=n;i++){
		for(R j=0;j!=m;j++){
			scanf("%d",&x);
			if(x==1){
				v[0][i]=v[1][j]=true;
			}
		}
	}
	x=0;
	for(R i=0;i!=n;i++){
		if(v[0][i]==false){
			x++;
		}else{
			v[0][i]=false;
		}
	}
	for(R i=0;i!=m;i++){
		if(v[1][i]==false){
			y++;
		}else{
			v[1][i]=false;
		}
	}
	x=x<y?x:y;
	if((x&1)==0){
		puts("Vivek");
	}else{
		puts("Ashish");
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