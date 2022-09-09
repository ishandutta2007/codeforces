#include<bits/stdc++.h>
using namespace std;
#define MAXN	100005
#define MAXC	26
int n, value[MAXN];
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= 500; i++)
		value[i] = value[i / 2] + value[i - i / 2] + i / 2 * (i - i / 2);
	for (int i = 1; i <= 26; i++) {
		int pos = 0;
		for (int j = 500; j >= 1; j--) {
			if (value[j] <= n) {
				pos = j;
				break;
			}
		}
		n -= value[pos];
		for (int j = 1; j <= pos; j++)
			cout << (char)(i - 1 + 'a');
	}
	cout << endl;
	return 0;
}