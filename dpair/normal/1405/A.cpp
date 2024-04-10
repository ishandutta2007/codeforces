#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
int n;
int a[105], x[105]; 
int main(){
	int t;scanf("%d", &t);
	while(t --){
		scanf("%d", &n);
		for (register int i = 1;i <= n;i ++) scanf("%d", &a[i]);
		reverse(a + 1, a + n + 1);
		for (register int i = 1;i <= n;i ++) printf("%d ", a[i]);
		putchar(10);
	}
}