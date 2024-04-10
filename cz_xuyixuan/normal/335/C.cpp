#include<bits/stdc++.h>
using namespace std;
#define MAXN	205
#define MAXV	1005
bool mp[MAXN][5];
int one, two, n, m;
int mxone, mnone, mxtwo, mntwo;
int sg[MAXN][5], num, mark[MAXV];
void work(int x, int y) {
	mp[x][y] = true;
	if (y == 1) {
		mxone = max(mxone, x);
		mnone = min(mnone, x);
		one++;
	} else {
		mxtwo = max(mxtwo, x);
		mntwo = min(mntwo, x);
		two++;
	}
	if (!mp[x][y - 1]) work(x, y - 1);
	if (!mp[x][y + 1]) work(x, y + 1);
	if (!mp[x + 1][y]) work(x + 1, y);
	if (!mp[x - 1][y]) work(x - 1, y);
	if (!mp[x - 1][y - 1]) work(x - 1, y - 1);
	if (!mp[x + 1][y - 1]) work(x + 1, y - 1);
	if (!mp[x - 1][y + 1]) work(x - 1, y + 1);
	if (!mp[x + 1][y + 1]) work(x + 1, y + 1);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		mp[x][y] = mp[x - 1][3 - y] = true;
		mp[x][3 - y] = mp[x + 1][3 - y] = true;
	}
	for (int i = 0; i <= n + 1; i++)
		mp[i][0] = mp[i][3] = true;
	mp[0][1] = mp[0][2] = true;
	mp[n + 1][1] = mp[n + 1][2] = true;
	memset(sg, 0, sizeof(sg));
	sg[1][0] = sg[1][1] = sg[1][2] = sg[1][3] = 1;
	for (int i = 2; i <= n; i++) {
		int ans;
		num++;
		for (int j = 1; j <= i; j++)
			mark[sg[j - 1][0] ^ sg[i - j][0]] = num;
		for (int j = 1; j <= i - 2; j++)
			mark[sg[j - 1][3] ^ sg[i - 2 - j][3]] = num;
		ans = 0;
		while (mark[ans] == num) ans++;
		sg[i][0] = ans;
		num++;
		for (int j = 1; j <= i; j++)
			mark[sg[j - 1][0] ^ sg[i - j][1]] = num;
		for (int j = 1; j <= i - 1; j++)
			mark[sg[j - 1][1] ^ sg[i - 1 - j][3]] = num;
		ans = 0;
		while (mark[ans] == num) ans++;
		sg[i][1] = ans;
		num++;
		for (int j = 1; j <= i; j++)
			mark[sg[j - 1][1] ^ sg[i - j][1]] = num;
		ans = 0;
		while (mark[ans] == num) ans++;
		sg[i][2] = ans;
		num++;
		for (int j = 1; j <= i; j++)
			mark[sg[j - 1][0] ^ sg[i - j][3]] = num;
		ans = 0;
		while (mark[ans] == num) ans++;
		sg[i][3] = ans;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= 2; j++) {
		if (mp[i][j]) continue;
		one = two = 0;
		mxone = 1; mnone = n;
		mxtwo = 1; mntwo = n;
		work(i, j);
		if (mxone > mxtwo && mnone < mntwo) ans ^= sg[one][0];
		if (mxone > mxtwo && mnone == mntwo) ans ^= sg[one][1];
		if (mxone > mxtwo && mnone > mntwo) ans ^= sg[one][3];
		if (mxone == mxtwo && mnone < mntwo) ans ^= sg[one][1];
		if (mxone == mxtwo && mnone == mntwo) ans ^= sg[one][2];
		if (mxone == mxtwo && mnone > mntwo) ans ^= sg[two][1];
		if (mxone < mxtwo && mnone < mntwo) ans ^= sg[two][3];
		if (mxone < mxtwo && mnone == mntwo) ans ^= sg[two][1];
		if (mxone < mxtwo && mnone > mntwo) ans ^= sg[two][0];
	}
	if (ans) cout << "WIN" << endl;
	else cout << "LOSE" << endl;
	return 0;
}