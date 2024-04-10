#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n, a[MAXN];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d", &a[i]);
	sort(a, a + n);
	int q;	scanf("%d", &q);
	while (q--){
		int x;	scanf("%d", &x);
		printf("%d\n", upper_bound(a, a + n, x) - a);
	}
	return 0;
}