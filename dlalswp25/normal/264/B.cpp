#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int mx[100005];
int a[100005];
vector<int> V;

void f(int x) {
	if(x <= 1) return;
	if(x % 2 == 0) {
		V.push_back(2); f(x / 2); return;		
	}
	for(int i = 3; i * i <= x; i += 2) {
		if(x % i == 0) {
			V.push_back(i); f(x / i); return;			
		}
	}
	V.push_back(x); return;
}

int main() {
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
	if(N == 1 && a[1] == 1) { printf("1\n"); return 0; }

	for(int i = 1; i <= N; i++) {
		V.clear(); f(a[i]);
		int now = 0;
		for(int i = 0; i < V.size(); i++) {
			now = max(now, mx[V[i]] + 1);
		}
		for(int i = 0; i < V.size(); i++) {
			mx[V[i]] = max(mx[V[i]], now);			
		}
		//for(int i = 1; i <= 5; i++) printf("%d ", mx[i]); puts("");
	}
	int ans = 0;
	for(int i = 0; i < 100001; i++) ans = max(ans, mx[i]);
	printf("%d\n", ans);
	return 0;
}