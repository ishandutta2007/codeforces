#include <stdio.h>
#include <string.h>
int main(){
	int k,a[9];char c;
	scanf("%d",&k);k*=2;
	for(int i=0;i<9;i++) a[i]=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			scanf("%c",&c);
			if(c=='\n'){j--;continue;}
			if(c=='.')continue;
			a[c-'1']++;
		}
	}
	for(int i=0;i<9;i++)
	if(a[i]>k){printf("NO");return 0;}
	printf("YES");
}