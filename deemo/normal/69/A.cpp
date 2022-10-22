#include<cstdio>

using namespace std;

int main(){
	int n, sum[3] = {0};	scanf("%d", &n);
	n *= 3;
	while(n--){
		int temp;	scanf("%d", &temp);
		sum[n % 3] += temp;
	}	
	if (sum[0] || sum[1] || sum[2])	printf("NO\n");
	else printf("YES\n");
}