#include<cstdio>
#include<algorithm>

using namespace std;

const int MAX = 1e7 + 4;

bool pr[MAX];

int main(){
	int n;	scanf("%d", &n);
	for (int i = 2; n && i <= MAX; i++){
		if (pr[i])	continue;
		printf("%d ", i);
		n--;
		for (int j = i + i; j <= MAX; j += i)
			pr[j] = 1;
	}
	printf("\n");
	return 0;
}