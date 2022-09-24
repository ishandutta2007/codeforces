#include <cstdio>

using namespace std;

int main()
{
	int a,b,i,c;
	
	scanf("%d%d%d",&a,&b,&c);
	
	for(i=0;a*i<=c;i++){
		if((c-a*i)%b==0){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	
	return 0;
}