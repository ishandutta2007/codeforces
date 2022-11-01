#include<stdio.h>
#define R register int
int pos[1001];
inline void Solve(){
	int n,x,l=1,r;
	scanf("%d",&n);
	r=n;
	for(R i=1;i<=n;i++){
		scanf("%d",&x);
		pos[x]=i;
	}
	for(R i=n;i!=0;i--){
		if(pos[i]==l){
			l++;
		}else if(pos[i]==r){
			r--;
		}else{
			printf("Yes\n%d %d %d\n",l,pos[i],r);
			return;
		}
	}
	puts("NO");
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}