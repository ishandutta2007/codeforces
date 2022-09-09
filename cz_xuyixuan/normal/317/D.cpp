#include<bits/stdc++.h>
using namespace std;
#define MAXN	20000005
#define MAXV	31
bool flg[MAXN];
int sg[30] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};
/*int sg[MAXN], mem[MAXV];
map <int, int> mp;
int get(int curr) {
	if (curr < MAXN && sg[curr] != -1) return sg[curr];
	if (curr >= MAXN && mp.count(curr)) return mp[curr];
	if (curr == 0) return sg[curr] = 0;
	bool mark[MAXV];
	memset(mark, false, sizeof(mark));
	for (int i = 1; i < MAXV; i++) {
		int now = 0;
		for (int j = i; j < MAXV; j += i)
			now += 1 << j - 1;
		int tmp = now & curr;
		if (tmp == 0) continue;
		mark[get(curr - tmp)] = true;
	}
	int ans = 0;
	while (mark[ans]) ans++;
	if (curr < MAXN) return sg[curr] = ans;
	else return mp[curr] = ans;
}
int SG(int x) {
	if (mem[x] != -1) return mem[x];
	else return mem[x] = get((1 << x) - 1);
}*/
int SG(int x) {
	return sg[x];
}
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	//memset(sg, -1, sizeof(sg));
	//memset(mem, -1, sizeof(mem));
	int m = sqrt(n), used = 0, ans = 0;
	for (int i = 2; i <= m; i++) {
		if (flg[i]) continue;
		long long tmp = i;
		int now = 0;
		while (tmp <= n) {
			used++; now++; tmp *= i;
			if (tmp <= m) flg[tmp] = true;
		}
		ans ^= SG(now);
	}
	if ((n - used) % 2 == 1) ans ^= SG(1);
	if (ans) cout << "Vasya" << endl;
	else cout << "Petya" << endl;
	return 0;
}