#include <cstdio>

using namespace std;

int n,s,i,a,c;

int main()
{
	scanf("%d",&n);
	
	for(i=1;;i++){
		a=i,c=0;
		while(1){
			c++;
			if(a%5==0) a/=5;
			else break;
		}
		s+=c;
		if(s==n) break;
		if(s>n){
			printf("0\n");
			return 0;
		}
	}
	
	printf("5\n");
	printf("%d %d %d %d %d\n",i*5,i*5+1,i*5+2,i*5+3,i*5+4);
	
	return 0;
}