#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,la,x,ans=0,lala;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(i!=1){
			if(la==1){
				if(x==2){
					if(lala==3)ans+=2;
					else ans+=3;
				}
				else ans+=4;
			}
			if(la==2){
				if(x==1)ans+=3;
				else{
					puts("Infinite");
					return 0;
				}
			}
			if(la==3){
				if(x==1)ans+=4;
				else{
					puts("Infinite");
					return 0;
				}
			}
		}
		lala=la;
		la=x;
	}
	puts("Finite");
	printf("%d\n",ans);
	return 0;
}