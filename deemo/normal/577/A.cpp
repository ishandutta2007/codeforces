#include<cstdio>

using namespace std;

int main(){
	int n, x;	scanf("%d%d", &n, &x);
	int cnt = 0;
	for (int i = 1;i * i <= x; i++){
		if (x % i != 0)	continue;
		if (i > n || x / i > n)	continue;
		cnt++;
		if (x/i != i)	cnt++;
	}
	printf("%d\n", cnt);
	return	0;
}