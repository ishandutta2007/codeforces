#include <cstdio>

using namespace std;

bool P[101010];
int n,i,j,k;

int main()
{
	scanf("%d",&n);

	if(n==1){
		printf("1\n1\n");
		return 0;
	}
	if(n==2){
		printf("1\n1 1\n");
		return 0;
	}

	k=n;
	n++;
	for(i=2;i<=n;i++){
		if(!P[i]){
			k--;
			for(j=i+i;j<=n;j+=i){
				P[j] = 1;
			}
		}
	}

	printf("2\n");
	for(i=2;i<=n;i++){
		printf("%d ",P[i]+1);
	}
	printf("\n");

	return 0;
}