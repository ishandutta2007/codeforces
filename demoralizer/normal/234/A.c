#include <stdio.h>
#include <string.h>
int main(){
	FILE *fr,*fw;
	fr=fopen("input.txt","r");
	fw=fopen("output.txt","w");
	int n;
	fscanf(fr,"%d",&n);
	char s[n+5];
	fscanf(fr,"%s",s);
	int a[n/2],b[n/2],p=0,q=0;
	for(int i=1;i<=n/2;i++){
		if(s[i-1]=='R')
		fprintf(fw,"%d %d\n",i+n/2,i);
		else
		fprintf(fw,"%d %d\n",i,i+n/2);
	}
	fclose(fr);fclose(fw);
}