#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(a < b) swap(a, b);
		int tmp = a - b;
		if(tmp % 10) printf("%d\n", tmp / 10 + 1);
		else printf("%d\n", tmp / 10);
	}	
	return 0;
}