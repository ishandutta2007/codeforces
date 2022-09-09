#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
int main() {
	int n;
	scanf("%d", &n);
	bool flg = false;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		if (x & 1) flg = true;
	}
	if (flg) printf("First\n");
	else printf("Second\n");
	return 0;
}