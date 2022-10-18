#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d", &t);
	while(t --){
		int n;
		scanf("%d", &n);
		int tmp = (n - 1) >> 2;
		tmp ++;
		n -= tmp;
		for (register int i = 1;i <= n;i ++) putchar('9');
		while(tmp --) putchar('8');
		putchar(10);
	}
}