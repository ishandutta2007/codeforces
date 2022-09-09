#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int tt,n,i,j,s,a[100005],c;
int main(){
	scanf("%d",&tt);
	while(tt--){
		scanf("%d",&n);
		s=c=0;
		rep(i,n){
			scanf("%d",&a[i]);
			s^=a[i];
		} 
		if(!s){
			puts("DRAW");
			continue;
		}
		for(i=30;i>=0;i--){
			if((s>>i)&1) break;
		}
		rep(j,n){
			if((a[j]>>i)&1) c++;
		}
		if((n&1)&&(c%4==3)){
			puts("LOSE");
		}
		else{
			puts("WIN");
		}
	}
	return 0;
}