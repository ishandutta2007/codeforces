#include<bits/stdc++.h>
using namespace std;
void Solve(){
	int n,i,j,x,a,b,mx1=0,mx2=0;
	scanf("%d%d",&n,&x);
	for(i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		if(a>mx1){
			mx1=a;
		}
		if(a-b>mx2){
			mx2=a-b;
		}
	}
	if(mx1>=x){
		printf("1\n");
	}else if(mx2>0){
		printf("%d\n",1+(x-mx1+mx2-1)/mx2);
	}else{
		printf("-1\n");
	}
}
int main(){
	int i,t;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		Solve();
	}
	return 0;
}