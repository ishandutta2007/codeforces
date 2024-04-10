#include <stdio.h>
#include <string.h>
int main(){
	int n;char a,b,c;
	scanf("%d\n%c%c",&n,&a,&b);
if(a==b){printf("NO");return 0;}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==0&&j<2) continue;
			scanf("%c",&c);
			if(c=='\n'){j--;continue;}
			 if(i==j||(i+j+1)==n){
			  if(c!=a){
			   printf("NO");
			   return 0;
			  }
			 }
			else if(c!=b){
			   printf("NO");
			   return 0;
			  }
		}
	}
	printf("YES");	
}