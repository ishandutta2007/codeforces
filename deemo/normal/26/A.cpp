#include<cstdio>

using namespace std;

bool pr(int x){
	if (x == 1)	return	false;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)	return	false;
	return	true;
}

bool ok(int x){
	for (int i = 2; i*i < x; i++){
		if (x % i != 0)	continue;
		while (x % i == 0)	x /= i;
		if (pr(x))	return	true;
		if (x == 1)	return	false;	

		int j = 2;
		for (; j * j <= x; j++)
			if (x % j == 0)	break;
		while (x % j == 0)	x /= j;
		return	x == 1;
	}
	return	false;
}

int main(){
	int n;	scanf("%d", &n);
	int cnt = 0;
	for (int i = 1; i <= n; i++)	
		if (ok(i))	cnt++;
	printf("%d\n", cnt);
	return	0;
}