#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
#define MAXLOG	35
#define MAXC	20000005
int a[MAXN], ans, n, sg[MAXC];
int get(int curr) {
	if (curr == 0) return 0;
	if (curr < MAXC) {
		if (sg[curr] != -1) return sg[curr];
		bool now[MAXLOG];
		memset(now, false, sizeof(now));
		for (int i = 1, j = 1; i <= curr; i <<= 1, j++)
			now[get(curr & (i - 1) | (curr >> j))] = true;
		for (int i = 0; i < MAXLOG; i++)
			if (!now[i]) return sg[curr] = i;
	} else {
		bool now[MAXLOG];
		memset(now, false, sizeof(now));
		for (int i = 1, j = 1; i <= curr; i <<= 1, j++)
			now[get(curr & (i - 1) | (curr >> j))] = true;
		for (int i = 0; i < MAXLOG; i++)
			if (!now[i]) return i;
	}
}
void check(int x) {
	int curr = 0;
	for (int i = 1; i <= n; i++) {
		int now = 0;
		while (a[i] % x == 0) {
			a[i] /= x;
			now++;
		}
		if (now) curr |= 1 << now - 1;
	}
	ans ^= get(curr);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	memset(sg, -1, sizeof(sg));
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int j = 2;
		while (j * j <= a[i]) {
			if (a[i] % j == 0) check(j);
			j++;
		}
		if (a[i] != 1) check(a[i]);
	}
	if (ans == 0) cout << "Arpa" << endl;
	else cout << "Mojtaba" << endl;
	return 0;
}