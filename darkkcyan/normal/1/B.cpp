#include <bits/stdc++.h>
using namespace std;

char a[10000];
int x, y;

int tonum(char* x) {
	int ans = 0;
	for (; *x != 0; ++x) {
		ans = ans * 26 + (*x - 'A') + 1;
	}
	return ans;
}

string tostr(int num) {
	string ans = "";
	for (num --; num >= 0; num = num / 26 - 1) {
		ans += char(num % 26 + 'A');
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	int n; cin >> n >> ws;
	for (int i = 0; i < n; ++i) {
		cin >> ws;
		scanf("%[A-Z]s", a);
		cin >> x;
		if (!isalpha(cin.peek())) {
			printf("R%dC%d\n", x, tonum(a));
			continue;
		}
		scanf("%*[A-Z]s");
		cin >> y;
		printf("%s%d\n", tostr(y).c_str(), x);
	}
	return 0;
}