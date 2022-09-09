#include<bits/stdc++.h>
using namespace std;
#define MAXN	100005
struct info { int type, pos, time, value, home; };
struct res {int x, y, type; };
info a[MAXN], b[MAXN];
res ans[MAXN], now[MAXN];
bool cmp(info x, info y) {
	return x.value < y.value;
} 
bool cnp(info x, info y) {
	if (x.type == 1 && y.type == 2) return true;
	if (x.type == 2 && y.type == 1) return false;
	if (x.type == 1) return x.pos > y.pos;
	else return x.pos < y.pos;
}
bool ctp(res x, res y) {
	if (x.type == 1 && y.type == 2) return false;
	if (x.type == 2 && y.type == 1) return true;
	if (x.type == 1) return x.x > y.x;
	else return x.y < y.y;
}
int main() {
	ios::sync_with_stdio(false);
	int n, w, h;
	cin >> n >> w >> h;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].type >> a[i].pos >> a[i].time;
		a[i].value = a[i].pos - a[i].time;
		a[i].home = i;
	}
	sort(a + 1, a + n + 1, cmp);
	int pos = 1;
	while (pos <= n) {
		int cnt = 0, tmp = a[pos].value;
		while (pos <= n && a[pos].value == tmp)
			b[++cnt] = a[pos++];
		for (int i = 1; i <= cnt; i++)
			if (b[i].type == 1) now[i] = (res) {b[i].pos, h, 1};
			else now[i] = (res) {w, b[i].pos, 2};
		sort(b + 1, b + cnt + 1, cnp);
		sort(now + 1, now + cnt + 1, ctp);
		for (int i = 1; i <= cnt; i++)
			ans[b[i].home] = now[i];
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i].x << ' ' << ans[i].y << endl;
	return 0;
}