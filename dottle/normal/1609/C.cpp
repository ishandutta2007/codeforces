#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5;
int n, e, a[N];
int pri[N], vis[N], tot;
int nxt[N];

void GetPrime(int n) {
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) pri[++tot] = i;
		for(int j = 1; j <= tot && i * pri[j] <= n; j++) {
			vis[i * pri[j]] = 1;
			if(i % pri[j] == 0) break;
		}
	}
//	for(int i = 1; i <= 20; i++) cout << vis[i] << " "; cout << endl;
}

void solve() {
	n = get(), e = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	int ans = 0;
	for(int i = n; i >= 1; i--) {
		if(i + e > n) { nxt[i] = i + e; continue; }
		if(a[i + e] != 1) nxt[i] = i + e;
		else nxt[i] = nxt[i + e];
//		cout << "run " << i << endl;
		if(a[i] != 1) {
			if(vis[a[i]]) continue;
			ans += (nxt[i] - i) / e - 1;
		}
		else {
			int pos = nxt[i];
			if(vis[a[pos]] || pos > n) continue;
			ans += (nxt[pos] - pos) / e;
//			cout << "debug: " << i << " " << (nxt[pos] - pos) / e << endl;;
		}
	}
//	for(int i = 1; i <= n; i++) cout << nxt[i] << " "; cout << endl;
	cout << ans << endl;
}

main() {
	GetPrime(1000000);
	int T = get();
	while(T--) solve();
	return 0;
}