#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int m, h1, a1, x1, y1, h2, a2, x2, y2;
int main(){
	scanf("%d", &m);
	scanf("%d%d%d%d", &h1, &a1, &x1, &y1);
	scanf("%d%d%d%d", &h2, &a2, &x2, &y2);
	int t1 = 0, t2 = 0;
	int b1 = 0, b2 = 0;
	int c1 = h1, c2 = h2;
	int i;
	for(i = 1;i <= m;i ++){
		c1 = (1LL * x1 * c1 + y1) % m;
		c2 = (1LL * x2 * c2 + y2) % m;
		if(c1 == a1) break;
	}
	int p = i;
	if(i > m){
		printf("-1");
		return 0;
	}
	if(c2 == a2){
		printf("%d\n", i);
		return 0;
	}
	int j;
	for(j = 1;j <= m;j ++){
		c1 = (1LL * c1 * x1 + y1) % m;
		if(c1 == a1) break;
	}
	if(j > m){
		printf("-1");
		return 0;
	}
	b1 = 1, b2 = 0;
	for(i = 1;i <= j;i ++){
		b1 = (1LL * b1 * x2) % m;
		b2 = (1LL * b2 * x2 + y2) % m;
	}
	for(i = 1;i <= m;i ++){
		c2 = (1LL * b1 * c2 + b2) % m;
		if(c2 == a2){
			printf("%I64d\n", p + 1LL * i * j);
			return 0;
		}
	}printf("-1\n");
		
	
	return 0;
}