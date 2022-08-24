#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 3e5;
int arr[MAXN];
int go[MAXN * 31][2];
int cnt[MAXN * 31];

int num_vert = 1;

void add(int n) {
	int pos = 0;
	for (int i = 30; i >= 0; i--) {
		cnt[pos]++;
		if (go[pos][(n >> i) & 1] == 0) {
			go[pos][(n >> i) & 1] = num_vert++;
		}
		pos = go[pos][(n >> i) & 1];
	}
	cnt[pos]++;
}




signed main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		add(p);
	}
	int bit;
	for (int i = 0; i < n; i++) {
		int pos = 0;
		int tmp = 0;
		for (int j = 30; j >= 0; j--) {
			cnt[pos]--;
			bit = (arr[i] >> j) & 1;
			if (go[pos][bit] == 0 || cnt[go[pos][bit]] == 0) {
				pos = go[pos][bit ^ 1];
				tmp ^= (bit ^ 1) << j;
			} else {
				pos = go[pos][bit];
				tmp ^= (bit) << j;
			}
		}
		cout << (arr[i] ^ tmp) << " ";
		cnt[pos]--;
	}

	return 0;
}