#include<bits/stdc++.h>
using namespace std;

int n;
int a[15];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	clock_t start = clock();
	while((clock() - start) / CLOCKS_PER_SEC < 1.1);
	for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
	return 0;
}