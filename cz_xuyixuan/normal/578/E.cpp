#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
char s[MAXN]; int n, nxt[MAXN];
vector <pair <int, int>> rr, rl, lr, ll;
int main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		pair <int, int> tmp;
		if (s[i] == 'L') {
			if (lr.size()) {
				tmp = lr.back(), lr.pop_back();
				nxt[tmp.second] = i, tmp.second = i;
				ll.push_back(tmp);
			} else if (rr.size()) {
				tmp = rr.back(), rr.pop_back();
				nxt[tmp.second] = i, tmp.second = i;
				rl.push_back(tmp);
			} else ll.emplace_back(i, i);
		} else {
			if (rl.size()) {
				tmp = rl.back(), rl.pop_back();
				nxt[tmp.second] = i, tmp.second = i;
				rr.push_back(tmp);
			} else if (ll.size()) {
				tmp = ll.back(), ll.pop_back();
				nxt[tmp.second] = i, tmp.second = i;
				lr.push_back(tmp);
			} else rr.emplace_back(i, i);
		}
	}
	while (lr.size() >= 2) {
		ans++;
		pair <int, int> tmp = lr.back(); lr.pop_back();
		pair <int, int> tnp = lr.back(); lr.pop_back();
		nxt[tmp.second] = tnp.first, tmp.second = tnp.second;
		lr.push_back(tmp);
	}
	while (rl.size() >= 2) {
		ans++;
		pair <int, int> tmp = rl.back(); rl.pop_back();
		pair <int, int> tnp = rl.back(); rl.pop_back();
		nxt[tmp.second] = tnp.first, tmp.second = tnp.second;
		rl.push_back(tmp);
	}
	while (ll.size() + lr.size() + rr.size() + rl.size() >= 2) {
		ans++;
		if (lr.size()) {
			pair <int, int> tmp = lr.back(), tnp; lr.pop_back();
			if (ll.size()) {
				tnp = ll.back(); ll.pop_back();
				nxt[tmp.second] = tnp.first, tmp.second = tnp.second;
				ll.push_back(tmp);
			} else {
				tnp = rr.back(); rr.pop_back();
				nxt[tnp.second] = tmp.first, tmp.first = tnp.first;
				rr.push_back(tmp);
			}
		} else if (rl.size()) {
			pair <int, int> tmp = rl.back(), tnp; rl.pop_back();
			if (ll.size()) {
				tnp = ll.back(); ll.pop_back();
				nxt[tnp.second] = tmp.first, tmp.first = tnp.first;
				ll.push_back(tmp);
			} else {
				tnp = rr.back(); rr.pop_back();
				nxt[tmp.second] = tnp.first, tmp.second = tnp.second;
				rr.push_back(tmp);
			}
		} else {
			pair <int, int> tmp = ll.back(); ll.pop_back();
			pair <int, int> tnp = rr.back(); rr.pop_back();
			nxt[tmp.second] = tnp.first, tmp.second = tnp.second;
			lr.push_back(tmp);
		}
	}
	cout << ans << endl;
	int pos = 0;
	if (ll.size()) pos = ll.back().first;
	if (lr.size()) pos = lr.back().first;
	if (rl.size()) pos = rl.back().first;
	if (rr.size()) pos = rr.back().first;
	while (pos != 0) {
		printf("%d ", pos);
		pos = nxt[pos];
	}
	return 0;
}