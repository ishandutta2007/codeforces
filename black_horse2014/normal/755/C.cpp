#include <bits/stdc++.h>
using namespace std;

bool chk[11111];

int main() {
	
	int n;
	scanf("%d", &n);
	int a = 0, b = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		if (x == i) a++;
		else {
			if (!chk[x]) chk[x] = 1, b++;
		}
	}
	cout<<a + b / 2<<endl;
	
	return 0;
}