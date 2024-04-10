#include<stdio.h>
#include<algorithm>
#define R register int
int S[26],col[200000];
int main(){
	int n,res=0,x;
	scanf("%d\n",&n);
	char c;
	for(R i=0;i!=n;i++){
		c=getchar();
		x=S[c-'a'];
		for(R j=0;j!=26;j++){
			if((x>>j&1)==0){
				col[i]=j;
				break;
			}
		}
		if(col[i]>res){
			res=col[i];
		}
		for(R j=0;j<c-'a';j++){
			S[j]|=1<<col[i];
		}
	}
	if(res>1){
		printf("NO");
	}else{
		puts("YES");
		for(R i=0;i!=n;i++){
			printf("%d",col[i]);
		}
	}
	return 0;
}