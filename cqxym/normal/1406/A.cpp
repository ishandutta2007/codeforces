#include<stdio.h>
#define R register int
bool v1[102],v2[102];
inline void Solve(){
	int n,x;
	scanf("%d",&n);
	for(R i=0;i!=101;i++){
		v1[i]=v2[i]=false;
	}
	for(R i=0;i!=n;i++){
		scanf("%d",&x);
		if(v1[x]==true){
			v2[x]=true;
		}else{
			v1[x]=true;
		}
	}
	int s1=0,s2=0;
	while(v1[s1]==true){
		s1++;
	}
	while(v2[s2]==true){
		s2++;
	}
	printf("%d\n",s1+s2);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}