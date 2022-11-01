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

int a[maxn];

int main(){
	int i, j, l;
	int x, y;
	int cnt = 0;
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		scanf("%d", &a[i]);
	}
	
	sort(a + 1, a + n + 1);
	
	printf("%d", min(a[n - 1] - a[1], a[n] - a[2]));
	
	return 0;
}