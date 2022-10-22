#include<cstdio>

using namespace std;

typedef long long ll;

int f[300];

int main(){
	int n;	scanf("%d", &n);
	if (n == 0){
		printf("0 0 0\n");
		return 0;
	}
	if (n == 1){
		printf("0 0 1\n");
		return 0;
	}
	if (n == 2){
		printf("0 1 1\n");
		return 0;
	}
	f[1] = 1;
	int i;
	for (i = 2; f[i - 1] != n; i++)
		f[i] = f[i - 1] + f[i - 2];
	printf("%d %d %d\n", f[i - 5], f[i - 4], f[i - 2]);
	return	0;
}