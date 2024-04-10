#include <cstdio>

using namespace std;

int a;

bool prime(int a)
{
	int i;
	for(i=2;i*i<=a;i++){
		if(a%i==0) return 0;
	}

	return 1;
}

int main()
{
	scanf("%d",&a);

	if(a%2){
		if(prime(a)) printf("1\n");
		else if(prime(a-2)) printf("2\n");
		else printf("3\n");
	}
	else{
		if(a==2) printf("1\n");
		else printf("2\n");
	}

	return 0;
}