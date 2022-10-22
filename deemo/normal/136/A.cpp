#include<cstdio>

using namespace std;

int ans[300];

int main(){
	int n;	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int temp;	
		scanf("%d", &temp);
		ans[temp] = i + 1;
	}
	for (int i = 1; i <= n ;i++)
		printf("%d ", ans[i]);
	printf("\n");
	return	0;
}