#include<cstdio>

using namespace std;

int get(int x){
	int ret = 0;
	while (x){
		if (x & 1)	ret++;
		x >>= 1;
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", get(n));
	return 0;
}