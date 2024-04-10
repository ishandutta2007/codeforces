#include<bits/stdc++.h>

using namespace std;

int main(){
	int a, b, n;
	scanf("%d", &n);
	scanf("%d:%d", &a, &b);
	if (b >= 60)
		b = b % 10;
	if (n == 24){
		if (a >= 24)	
			a = a % 10;
	}
	else{
		if (a > 12){
			if (a % 10 <= 2)
				a = 10 + a % 10;
			else
				a %= 10;
		}
		if (a == 0)
			a = 1;
	}
	printf("%02d:%02d\n", a, b);
	return 0;
}