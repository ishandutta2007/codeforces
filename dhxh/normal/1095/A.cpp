#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t, k;

char a[maxn];

int main(){
	int i, j, l;
	int x, y;
	int cnt = 0;
	
	scanf("%d", &n);
	scanf("%s", &a[1]);
	
	int p = 1;
	
	for(i=1;p<=n;i++){
		printf("%c", a[p]);
		p += i;
	}
	
	printf("\n");
	
	return 0;
}