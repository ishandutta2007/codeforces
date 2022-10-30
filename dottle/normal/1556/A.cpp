#include<bits/stdc++.h>
using namespace std;

int a,b,t; 

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);
		if((a^b)&1)printf("-1\n");
		else if(a==0&&b==0) printf("0\n");
		else if(a==b) printf("1\n");
		else printf("2\n");
	}
}