#include <cstdio>
using namespace std;
#define MOD 1073741824

int divisors(int n){
	int c = 1;
	for (int d = 2; d < 100; d++){
		if (n % d == 0){
			int alpha = 0;
			while (n % d == 0) {
				n /= d;
				alpha++;
			}
			c *= (alpha + 1);
		}
	}
	return c;
}


int main(){
	int sum = 0, al, bl, cl;
	scanf("%d %d %d", &al, &bl, &cl);
	for (int a = 1; a <= al; a++){
		for (int b = 1; b <= bl; b++){
			for (int c = 1; c <= cl; c++){
				sum += divisors(a*b*c);
				sum %= MOD;
			}
		}
	}
	printf("%d", sum);
}