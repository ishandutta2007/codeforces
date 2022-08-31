#include <stdio.h>
#include <string.h>
int main(){
	char s[4];int a[6],p,q;
	for(int i=0;i<3;i++){
		scanf("%s",s);
		switch(s[0]){
			case 'C':a[i]=1;break;
			case 'D':a[i]=3;break;
			case 'E':a[i]=5;break;
			case 'F':a[i]=6;break;
			case 'G':a[i]=8;break;
			case 'A':a[i]=10;break;
			case 'B':a[i]=11;break;
			case 'H':a[i]=12;break;
		}
		if(strlen(s)==2)a[i]++;
	}
	for(int i=0;i<2;i++)
		for(int j=0;j<2-i;j++)
			if(a[j]>a[j+1]){
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
	for(int i=0;i<3;i++)
		a[i+3]=a[i]+12;
	for(int i=0;i<3;i++){
		p=a[i+1]-a[i];
		q=a[i+2]-a[i+1];
		if(p==4&&q==3)
			{printf("major");return 0;}
		if(p==3&&q==4)
			{printf("minor");return 0;}
	}
	printf("strange");
}