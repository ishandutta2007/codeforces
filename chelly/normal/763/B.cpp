#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	printf("YES\n");
	for(int i(1); i <= n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		printf("%d\n", 1 + 2 * (((min(x1, x2) % 2) + 1) % 2) + ((min(y1, y2) % 2 + 1) % 2));
	}
}