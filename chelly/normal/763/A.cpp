#include<bits/stdc++.h>
using namespace std;
const int N(100011);
vector<int> adj[N];
int rela[N], a[N], b[N], c[N], siz[N], cnt[N];
int getr(int x) {
	int p(x);
	while(p != rela[p])
		p = rela[p];
	int p1(p); p = x;
	while(p != rela[p]) {
		int p2(rela[p]);
		rela[p] = p1;
		p = p2;
	}
	return p1;
}
int t, stmp[N];
int main() {
	int n;
	cin >> n;
	for(int i(0); i < n - 1; i++) {
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
		adj[a[i]].push_back(b[i]);
		adj[b[i]].push_back(a[i]);
	}
	for(int i(0); i < n; i++)
		cin >> c[i], rela[i] = i;
	int tot(0);
	for(int i(0); i < n - 1; i++) {
		if(c[a[i]] != c[b[i]]) {
			cnt[a[i]]++;
			cnt[b[i]]++;
			tot++;
		}
	}
	for(int i(0); i < n; i++) {
		if(cnt[i] == tot) {
			printf("YES\n%d\n", i + 1);
			return 0;
		}
	}
	printf("NO\n");
}