#include <bits/stdc++.h>
using namespace std;

const int N = 111;

char str[N];

int main() {
	ios::sync_with_stdio(0);
	int n; cin >> n;
	cin >> str;
	int p = 0;
	for (int i = 1; str[p]; i++) {
		printf("%c", str[p]);
		p += i;
	}
	puts("");
	return 0;
}