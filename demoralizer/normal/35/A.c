#include <stdio.h>
#include <string.h>
int main(){
	int k,a,b;
	FILE *fr,*fw;
	fr=fopen("input.txt","r");
	fw=fopen("output.txt","w");
	fscanf(fr,"%d",&k);
	for(int i=0;i<3;i++){
		fscanf(fr,"%d %d",&a,&b);
		if(a==k)k=b;
		else if(b==k)k=a;

	}
	fprintf(fw,"%d",k);
	fclose(fr);fclose(fw);
}