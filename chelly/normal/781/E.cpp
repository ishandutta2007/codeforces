#include<bits/stdc++.h>
using namespace std;
const int N(100011);
int mod(1e9 + 7);
struct Rec {
	int h, l, r, delta;
	bool operator < (const Rec & b) const {
		return h > b.h;
	}
} a[N];
map<int, int> mp[N * 4];
void insert(int k, int le, int ri, int posi, int val, int cnt) {
	mp[k][val] = (mp[k][val] + cnt) % mod;
	if(le == ri)
		return;
	int mid(le + ri >> 1);
	if(posi <= mid)
		insert(k * 2, le, mid, posi, val, cnt);
	else
		insert(k * 2 + 1, mid + 1, ri, posi, val, cnt);
}
int count(int k, int le, int ri, int ql, int qr, int lim) {
	if(mp[k].empty() || mp[k].begin()->first > lim)
		return 0;
	if(le == ri) {
		int res(0);
		while(!mp[k].empty() && mp[k].begin()->first <= lim) {
			res = (res + mp[k].begin()->second) % mod;
			auto tmp(mp[k].begin()->first);
			int cnt(mp[k].begin()->second);
			for(int j(k); j; j /= 2) {
				mp[j][tmp] = (mp[j][tmp] - cnt + mod) % mod;
				if(mp[j][tmp] == 0) 
					mp[j].erase(tmp);
			}
		}
		return res;
	}
	int res(0);
	int mid(le + ri >> 1);
	if(ql <= mid)
		res = (res + count(k * 2, le, mid, ql, qr, lim)) % mod;
	if(qr >= mid + 1)
		res = (res + count(k * 2 + 1, mid + 1, ri, ql, qr, lim)) % mod;
	return res;
}
int main() {
	int h, w, n;
	scanf("%d%d%d", &h, &w, &n);
	for(int i(1); i <= w; i++) {
		insert(1, 1, w, i, h + 1, 1);
	}
	for(int i(1); i <= n; i++) {
		scanf("%d%d%d%d", &a[i].h, &a[i].l, &a[i].r, &a[i].delta);
	}
	sort(a + 1, a + n + 1);
	for(int i(1); i <= n; i++) {
		int cnt(count(1, 1, w, a[i].l, a[i].r, a[i].h + a[i].delta));
		if(a[i].l == 1) {
			insert(1, 1, w, a[i].r + 1, a[i].h, cnt * 2 % mod);
		}else if(a[i].r == w) {
			insert(1, 1, w, a[i].l - 1, a[i].h, cnt * 2 % mod);
		}else {
			insert(1, 1, w, a[i].l - 1, a[i].h, cnt);
			insert(1, 1, w, a[i].r + 1, a[i].h, cnt);
		}
	}
	cout << count(1, 1, w, 1, w, 2e9) << endl;
}