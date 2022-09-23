#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
int X[1010];
int Y[1010];
int N;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d%d", &X[i], &Y[i]);
		if(i > 1) { X[i] -= X[1]; Y[i] -= Y[1]; }
	}
	X[1] = Y[1] = 0;

	while(1) {
		bool f = false;
		for(int i = 1; i <= N; i++) {
			if(X[i] & 1) f = true;
			if(Y[i] & 1) f = true;
		}
		if(f) break;
		for(int i = 1; i <= N; i++) { X[i] /= 2; Y[i] /= 2; }
	}

	// for(int i = 1; i <= N;i ++) printf("%d %d\n", X[i], Y[i]);

	bool ok = true;
	for(int i = 1; i <= N; i++) {
		if((X[i] & 1) != (Y[i] & 1)) ok = false;
	}

	if(!ok) {
		for(int i = 1; i <= N; i++) if((X[i] & 1) == (Y[i] & 1)) ans.push_back(i);
	}
	else {
		for(int i = 1; i <= N; i++) if(X[i] & 1) ans.push_back(i);
	}
	printf("%d\n", ans.size());
	for(int i : ans) printf("%d ", i); puts("");

	return 0;
}