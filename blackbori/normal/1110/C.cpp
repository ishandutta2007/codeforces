#include <bits/stdc++.h>

using namespace std;

int q;

int main()
{
	int a, i;
	
	scanf("%d", &q);
	
	for(; q--; ){
		scanf("%d", &a);
		if(a & a + 1){
			for(i=1; i-1<a; i<<=1);
			printf("%d\n", i - 1);
		}
		else{
			for(i=2; i*i<=a; i++){
				if(a % i == 0) break;
			}
			if(a % i == 0) printf("%d\n", a / i);
			else printf("1\n");
		}
	}
	
	return 0;
}