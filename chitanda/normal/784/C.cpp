#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int y = 0, x;
	for(int i = 1; i <= n; ++i) scanf("%d", &x), y = max(y, x);
	printf("%d\n", x ^ y);
	return 0;
}