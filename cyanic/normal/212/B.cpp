#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000007, MOD = 7920329;
int H[maxn*10], V[maxn*10], link[maxn*10], HEAD[MOD];
int Hash[30], n, m, tmp, HASH, cur, size;
pair<int,int> a[30];
char s[maxn], ch;

inline void add(int h) {
	int k = HEAD[h % MOD];
	while (k) {
		if (H[k] == h) { V[k]++; return; }
		k = link[k];
	}
	H[++size] = h; V[size] = 1;
	link[size] = HEAD[h % MOD];
	HEAD[h % MOD] = size;
}

inline int query(int h) {
	int k = HEAD[h % MOD];
	while (k) {
		if (H[k] == h) return V[k];
		k = link[k];
	}
	return 0;
}

int main() {
	for (int i=0; i<=25; i++) {
		Hash[i] = 1<<(i+5);
		for (int j=0; j<=i+4; j++)
			if (rand()&1) Hash[i] |= 1<<j;
	}
	scanf("%s", s+1);
	n = strlen(s+1);
	for (int i=n; i>=1; i--) {
		cur = tmp + 1;
		for (int j=1; j<=tmp; j++) 
			if (a[j].second == s[i]-'a') cur = j;
		tmp = max(tmp, cur);
		a[cur] = make_pair(i, s[i]-'a');
		while (cur < tmp && a[cur] > a[cur+1]) swap(a[cur], a[cur+1]), cur++;
		while (cur > 1 && a[cur] < a[cur-1]) swap(a[cur], a[cur-1]), cur--;
		HASH = 0;
		for (int j=1; j<=tmp&&a[j].second!=s[i-1]-'a'; j++) 
			HASH ^= Hash[a[j].second], add(HASH);
	}
	scanf("%d", &m);
	while (m--) {
		scanf("%s", s+1); HASH = 0;
		for (int i=1; s[i]; i++)
			HASH ^= Hash[s[i]-'a'];
		printf("%d\n", query(HASH));
	}
	return 0;
}