#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1111111;
bool chk[MAXN];

int main() {
	
	chk[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		if (!chk[i]) {
			for (int j = i; j <= MAXN / i; j++) chk[i * j] = 1;
		}
	}
	
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= 1000; i++) {
		if (chk[i * n + 1]) {
			m = i;
			break;
		}
	}
	
	cout<<m<<endl;
	
	return 0;
}