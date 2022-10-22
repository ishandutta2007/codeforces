#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

const int max_n = 3e3 + 30;

int n, m;
bool row[max_n], col[max_n];

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		int a, b;	scanf("%d%d", &a, &b);	a--, b--;
		row[a] = row[a + n] = 1;
		col[b] = col[b + n] = 1;
	}

	int ans = 0;
	for (int i = 1; i < n/2; i++){
		int a = i, b = n - 1 - i;
		ans += !row[a];
		ans += !row[b];
		ans += !col[a];
		ans += !col[b];
	}

	if (n % 2 == 1){
		int k = n/2;
		ans += bool((!row[k]) | (!col[k]));
	}
	printf("%d\n", ans);
	return 0;
}