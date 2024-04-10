#include <bits/stdc++.h>

using namespace std;

char A[15];
int ans;

int g() {
	int x = 5, y = 5;
	int a = 0, b = 0;
	int ret = 0;
	for(int i = 1; i <= 10; i++) {
		if(i & 1) {
			if(A[i] == '1') a++;
			x--;
		}
		else {
			if(A[i] == '1') b++;
			y--;
		}
		if(a + x < b || b + y < a) return i;
	}
	return 10;
}

void f(int i) {
	if(i > 10) {
		ans = min(ans, g());
		return;
	}
	if(A[i] != '?') {
		f(i + 1);
		return;
	}
	A[i] = '0';
	f(i + 1);
	A[i] = '1';
	f(i + 1);
	A[i] = '?';
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ans = 10;
		scanf("%s", A + 1);
		f(1);
		printf("%d\n", ans);
	}
	return 0;
}