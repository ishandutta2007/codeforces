#include <bits/stdc++.h>
using namespace std;

const int prm[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		cout << prm[i] << endl;
		char str[100]; scanf("%s", str);
		if (!strcmp(str, "yes")) ans++;
	}
	if (ans > 1) {
		cout << "composite" << endl;
		return 0;
	}
	if (ans == 0) {
		cout << "prime" << endl;
		return 0;
	}
	for (int i = 4; i < 15; i++) {
		cout << prm[i] << endl;
		char str[100]; scanf("%s", str);
		if (!strcmp(str, "yes")) {
			cout << "composite" << endl;
			return 0;
		}
	}
	for (int i = 0; i < 4; i++) {
		cout << prm[i] * prm[i] << endl;
		char str[100]; scanf("%s", str);
		if (!strcmp(str, "yes")) {
			cout << "composite" << endl;
			return 0;
		}
	}
	cout << "prime" << endl;
	return 0;
}