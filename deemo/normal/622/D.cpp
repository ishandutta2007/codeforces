#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 5e5 + 10;

int n;

int main(){
	scanf("%d", &n);
	if (n % 2 == 1){
		printf("%d ", n);
		for (int i = 1; i < n; i += 2)
			printf("%d ", i);
		printf("%d ", n);
		for (int i = n - 2; i >= 1; i -= 2)
			printf("%d ", i);

		for (int i = 2; i <= n; i += 2)
			printf("%d ", i);
		for (int i = n - 1; i > 0; i -= 2)
			printf("%d ", i);
		printf("\n");
	}
	else{
		for (int i = 1; i < n; i += 2)
			printf("%d ", i);
		for (int i = n - 1; i >= 1; i -= 2)
			printf("%d ", i);

		for (int i = 2; i < n; i += 2)
			printf("%d ", i);
		printf("%d ", n);
		for (int i = n - 2; i > 0; i -= 2)
			printf("%d ", i);
		printf("%d\n", n);
	}
	return	0;
}