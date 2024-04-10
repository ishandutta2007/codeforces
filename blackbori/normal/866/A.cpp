#include <cstdio>

using namespace std;

int main()
{
	int n;
	
	scanf("%d",&n);
	
	if(n == 1){
		printf("1 1\n1\n");
	}
	else{
		printf("%d 2\n",n*2-2);
		printf("1 2\n");
	}
	
	return 0;
}