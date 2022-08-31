#include <stdio.h>
#include <string.h>
int main(){
	char a[100],b[100];
	scanf("%s\n%s",a,b);
	int n=strlen(a),p=0;
	for(int i=0;i<n;i++){
		if(a[i]<96)a[i]+=32;
		if(b[i]<96)b[i]+=32;
		if(a[i]==b[i]) continue;
		if(a[i]>b[i]){p=1;break;}
		else{p=-1;break;}
		}
		printf("%d",p);
}