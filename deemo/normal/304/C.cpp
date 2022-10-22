#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAX = 1e5 + 20;

int ans[MAX];

int main(){
	int n;	scanf("%d", &n);
	if (n % 2 == 0){
		printf("-1\n");
		return 0;
	}
	
	for (int i = 0; i < n; i++)
		ans[(i + i) % n] = i;

	for (int w = 0; w < 2; w++){
		for (int i = 0; i < n; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
	for (int i = 0; i < n; i++)
		printf("%d ", i);
	printf("\n");
	return 0;
}