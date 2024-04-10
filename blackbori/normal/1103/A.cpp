#include <bits/stdc++.h>

using namespace std;

char str[1010];
int ax[4] = {1, 1, 1, 1}, ay[4] = {1, 2, 3, 4};
int bx[4] = {3, 3, 4, 4}, by[4] = {1, 3, 1, 3};
int a, b;

int main()
{
	int i;
	
	scanf("%s", str);
	
	for(i=0; str[i]; i++){
		if(str[i] == '0'){
			printf("%d %d\n", ax[a], ay[a]);
			a = (a + 1) % 4;
		}
		else{
			printf("%d %d\n", bx[b], by[b]);
			b = (b + 1) % 4;
		}
	}
	
	return 0;
}