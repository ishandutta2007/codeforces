#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
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
bool used[5]; int ans, a[5], cnt[2], b[5];
//	1	2
//	4	3
int sx[5], sy[5], tx[5], ty[5], resx[5], resy[5];
int sign(int x) {
	if (x < 0) return -1;
	if (x > 0) return 1;
	return 0;
}
void work(int pos) {
	if (pos == 5) {
		for (int i = 1; i <= 4; i++) {
			tx[i] = ty[i] = INF;
			if (b[i] == 0) tx[i] = sx[i];
			else ty[i] = sy[i];
		}
		for (int i = 1; i <= 4; i++) {
			if (tx[a[1]] == INF && tx[a[2]] != INF) tx[a[1]] = tx[a[2]];
			if (tx[a[2]] == INF && tx[a[1]] != INF) tx[a[2]] = tx[a[1]];
			if (tx[a[3]] == INF && tx[a[4]] != INF) tx[a[3]] = tx[a[4]];
			if (tx[a[4]] == INF && tx[a[3]] != INF) tx[a[4]] = tx[a[3]];
			if (ty[a[1]] == INF && ty[a[4]] != INF) ty[a[1]] = ty[a[4]];
			if (ty[a[4]] == INF && ty[a[1]] != INF) ty[a[4]] = ty[a[1]];
			if (ty[a[2]] == INF && ty[a[3]] != INF) ty[a[2]] = ty[a[3]];
			if (ty[a[3]] == INF && ty[a[2]] != INF) ty[a[3]] = ty[a[2]];
		}
		bool flg = false;
		if (cnt[0] < cnt[1]) {
			flg = true;
			for (int i = 1; i <= 4; i++) {
				swap(tx[i], ty[i]);
				swap(sx[i], sy[i]);
				b[i] ^= 1;
			}
			swap(a[2], a[4]);
			swap(cnt[0], cnt[1]);
		}
		if (cnt[0] == 4) {
			int delta = tx[a[4]] - tx[a[1]];
			int pos[4] = {sy[a[1]] + delta, sy[a[4]] + delta, sy[a[2]], sy[a[3]]};
			sort(pos + 0, pos + 4);
			ty[a[1]] = ty[a[4]] = (pos[0] + pos[3]) / 2 - delta;
			ty[a[2]] = ty[a[3]] = (pos[0] + pos[3]) / 2;
		} else if (cnt[0] == 3) {
			int delta = tx[a[4]] - tx[a[1]];
			if (ty[a[2]] == INF) ty[a[2]] = ty[a[3]] = ty[a[1]] + delta;
			else ty[a[1]] = ty[a[4]] = ty[a[3]] - delta;
		} else if (cnt[0] == 2) {
			if (b[a[1]] == 0 && b[a[2]] == 0) {
				int delta = ty[a[2]] - ty[a[1]];
				tx[a[3]] = tx[a[4]] = tx[a[1]] + delta;
			}
			if (b[a[3]] == 0 && b[a[4]] == 0) {
				int delta = ty[a[3]] - ty[a[4]];
				tx[a[1]] = tx[a[2]] = tx[a[3]] - delta;
			}
			if (b[a[1]] == 1 && b[a[4]] == 1) {
				int delta = tx[a[4]] - tx[a[1]];
				ty[a[2]] = ty[a[3]] = ty[a[1]] + delta;
			}
			if (b[a[2]] == 1 && b[a[3]] == 1) {
				int delta = tx[a[3]] - tx[a[2]];
				ty[a[1]] = ty[a[4]] = ty[a[2]] - delta;
			}
		}
		if (flg) {
			for (int i = 1; i <= 4; i++) {
				swap(tx[i], ty[i]);
				swap(sx[i], sy[i]);
				b[i] ^= 1;
			}
			swap(a[2], a[4]);
			swap(cnt[0], cnt[1]);
		}
		int size = ty[a[2]] - ty[a[1]];
		if (size <= 0) return;
		if (tx[a[1]] != tx[a[2]]) return;
		if (tx[a[3]] != tx[a[4]]) return;
		if (ty[a[1]] != ty[a[4]]) return;
		if (ty[a[3]] != ty[a[2]]) return;
		if (ty[a[2]] - ty[a[1]] != size) return;
		if (ty[a[3]] - ty[a[4]] != size) return;
		if (tx[a[4]] - tx[a[1]] != size) return;
		if (tx[a[3]] - tx[a[2]] != size) return;
		
		int Max = 0;
		for (int i = 1; i <= 4; i++) {
			if (b[i] == 0) chkmax(Max, abs(ty[i] - sy[i]));
			else chkmax(Max, abs(tx[i] - sx[i]));
		}
		if (Max < ans) {
			ans = Max;
			for (int i = 1; i <= 4; i++) {
				resx[i] = tx[i];
				resy[i] = ty[i];
			}
		}
		return;
	}
	for (int i = 1; i <= 4; i++)
		if (!used[i]) {
			a[pos] = i;
			used[i] = true;
			for (int j = 0; j <= 1; j++) {
				b[pos] = j;
				cnt[j]++;
				work(pos + 1);
				cnt[j]--;
			}
			used[i] = false;
		}
}
int main() {
	int T; read(T);
	while (T--) {
		for (int i = 1; i <= 4; i++)
			read(sx[i]), read(sy[i]);
		ans = INF, work(1);
		if (ans == INF) puts("-1");
		else {
			printf("%d\n", ans);
			for (int i = 1; i <= 4; i++)
				printf("%d %d\n", resx[i], resy[i]);
		}
	}
	return 0;
}