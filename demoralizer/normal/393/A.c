#include <stdio.h>
#include <string.h>
int main(){
	char c;
	int a[4]={0,0,0,0};
	while(scanf("%c",&c)>0){
		switch(c){
			case 'n':
			a[0]++;
			break;
			case 'i':
			a[1]++;
			break;
			case 't':
			a[2]++;
			break;
			case 'e':
			a[3]++;
			break;
		}
	}
	int n=a[0];
	a[0]/=2;
	if(n%2==0)a[0]--;
	a[3]/=3;
	int m=a[0];
	for(int i=0;i<4;i++)
		if(m>a[i])m=a[i];
	printf("%d",m>0?m:0);
}