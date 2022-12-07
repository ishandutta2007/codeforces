#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 100100;
int n;
int w[maxn], a[maxn], c[maxn];


void add(int x){
	for(; x <= n; x += x & -x) ++c[x];
}

int ask(int x){
	int res = 0;
	for(; x; x -= x & -x) res += c[x];
	return res;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i), w[i] = i;
	sort(w + 1, w + n + 1, [](int x, int y) { return a[x] < a[y] || (a[x] == a[y] && x < y); });
	int last = 0;
	ll ans = 0;
	for(int i = 1, j = 1; i <= n; i = j){
		while(j <= n && a[w[i]] == a[w[j]]) ++j;
		int k = i;
		while(w[k] < last && k < j) ++k;
		if(k == j) k = i;
		for(int l = k; l < j; ++l){
			ans += w[l] > last ? w[l] - last - (ask(w[l]) - ask(last)) : n - last + w[l] - (ask(n) - (ask(last) - ask(w[l])));
			last = w[l];
			add(w[l]);
		}
		for(int l = i; l < k; ++l){
			ans += w[l] > last ? w[l] - last - (ask(w[l]) - ask(last)) : n - last + w[l] - (ask(n) - (ask(last) - ask(w[l])));
			last = w[l];
			add(w[l]);
		}
	}
	printf("%lld\n", ans);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}