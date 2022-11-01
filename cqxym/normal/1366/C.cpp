#include<stdio.h>
#define R register int
int ct[29][2];
inline void Solve(){
	int n,m,e1,e2,ans=0,x;
	scanf("%d%d",&n,&m);
	if((n+m&1)==0){
		e1=e2=n+m-1>>1;
	}else{
		e1=n+m-1>>1;
		e2=e1-1;
	}
	for(R i=0;i!=e1;i++){
		ct[i][0]=ct[i][1]=0;
	}
	for(R i=0;i!=n;i++){
		for(R j=0;j!=m;j++){
			scanf("%d",&x);
			if(i+j<e1){
				ct[i+j][x]++;
			}else if(i+j>e2){
				ct[n+m-2-i-j][x]++;
			}
		}
	}
	for(R i=0;i!=e1;i++){
		ans+=ct[i][0]<ct[i][1]?ct[i][0]:ct[i][1];
	}
	printf("%d\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}