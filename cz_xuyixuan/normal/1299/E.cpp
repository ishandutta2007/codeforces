#include<bits/stdc++.h>
using namespace std;
const int MAXN = 805;
const int p[4] = {3, 5, 7, 8};
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n, res, ans[MAXN];
bool odd[MAXN], used[MAXN];
pair <int, int> pos[5];
int gett(int x) { // Modulo 3
	cout << '?' << ' ' << 3 << ' ' << x << ' ';
	cout << pos[1].first << ' ' << pos[2].first << endl;
	read(res); if (res) return 0;
	cout << '?' << ' ' << 3 << ' ' << x << ' ';
	cout << pos[2].first << ' ' << pos[3].first << endl;
	read(res); if (res) return 1;
	return 2;
}
int getf(int x) { // Modulo 5
	bool mark[5];
	memset(mark, false, sizeof(mark));
	for (int i = 1; i <= 4; i++) {
		cout << '?' << ' ' << 5 << ' ' << x << ' ' <<
			pos[1].second << ' ' << pos[2].second << ' ' << pos[3].second << ' ';
		cout << pos[i].first << endl;
		int value = (5 - (3 * n - 3 + i) % 5) % 5;
		read(res); if (res) return value;
		mark[value] = true;
	}
	for (int i = 0; i <= 4; i++)
		if (!mark[i]) return i;
	return -1;
}
int gets(int x) { // Modulo 7
	bool mark[7]; int cnt = 0;
	memset(mark, false, sizeof(mark));
	for (int i = 1; i <= 4 && cnt <= 5; i++)
	for (int j = 1; j <= 4 && cnt <= 5; j++) {
		int value = (7 - (n * 4 + 4 - i - (n - j + 1)) % 7) % 7;
		if (mark[value]) continue;
		cout << '?' << ' ' << 7 << ' ' << x << ' ';
		for (int k = 1; k <= 4; k++)
			if (k != i) cout << pos[k].first << ' ';
		for (int k = 1; k <= 4; k++)
			if (k != j) cout << pos[k].second << ' ';
		cout << endl; read(res); if (res) return value;
		mark[value] = true, cnt++;
	}
	for (int i = 0; i <= 6; i++)
		if (!mark[i]) return i;
	return -1;
}
int gete(int x) { // Modulo 8
	int ans = odd[x];
	for (int i = 1; i <= 4; i++) {
		int value = (4 - (10 - i) % 4) % 4;
		if (value == ans) {
			cout << '?' << ' ' << 4 << ' ' << x << ' ';
			for (int k = 1; k <= 4; k++)
				if (k != i) cout << pos[k].first << ' ';
			cout << endl; read(res);
			if (res) ans = ans;
			else ans = ans + 2;
			break;
		}
	}
	for (int i = 1; i <= 4; i++) {
		int value = (8 - (n * 4 + 4 - i) % 8) % 8;
		if (value == ans || value == ans + 4) {
			cout << '?' << ' ' << 8 << ' ' << x << ' ';
			for (int k = 1; k <= 4; k++) {
				if (k != i) cout << pos[k].first << ' ';
				cout << pos[k].second << ' ';
			}
			cout << endl; read(res);
			if (res ^ (value == ans)) ans = ans + 4;
			else ans = ans;
			break;
		}
	}
	return ans;
}
void Output() {
	if (ans[1] > n / 2) {
		for (int i = 1; i <= n; i++)
			ans[i] = n + 1 - ans[i];
	}
	cout << '!' << ' ';
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << endl;
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		cout << '?' << ' ' << n - 1 << ' ';
		for (int j = 1; j <= n; j++)
			if (i != j) cout << j << ' ';
		cout << endl; read(res);
		if (res) {
			if (pos[1].first) pos[1].second = i;
			else pos[1].first = i;
		}
	}
	used[pos[1].first] = used[pos[1].second] = true;
	odd[pos[1].first] = true;
	for (int i = 1; i <= n; i++)
		if (i != pos[1].first) {
			cout << '?' << ' ' << 2 << ' ' << i << ' ' << pos[1].first << endl;
			read(odd[i]);
		}
	for (int k = 2; k <= 4 && k * 2 <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (used[i]) continue;
			cout << '?' << ' ' << n - k * 2 + 1 << ' ';
			for (int j = 1; j <= n; j++)
				if (i != j && !used[j]) cout << j << ' ';
			cout << endl; read(res);
			if (res) {
				if (odd[i] ^ (k % 2 == 1)) pos[k].second = i;
				else pos[k].first = i;
			}
		}
		used[pos[k].first] = used[pos[k].second] = true;
	}
	for (int i = 1; i <= 4 && i <= n / 2; i++) {
		ans[pos[i].first] = i;
		ans[pos[i].second] = n + 1 - i;
	}
	if (n <= 6) {
		Output();
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (ans[i]) continue;
		int t = gett(i);
		int f = getf(i);
		int s = gets(i);
		int e = gete(i);
		for (int j = 1; j <= n; j++)
			if (j % 3 == t && j % 5 == f && j % 7 == s && j % 8 == e) {
				ans[i] = j;
				break;
			}
	}
	Output();
	return 0;
}