#include <bits/stdc++.h>

using namespace std;

vector<int> vx;
vector<int> vy;

int x[7];
int y[7];
int A[7][7];

int main() {
	for(int i = 1; i <= 6; i++) {
		scanf("%d%d", &x[i], &y[i]);
		vx.push_back(x[i]);
		vy.push_back(y[i]);
	}
	sort(vx.begin(), vx.end());
	vx.erase(unique(vx.begin(), vx.end()), vx.end());

	sort(vy.begin(), vy.end());
	vy.erase(unique(vy.begin(), vy.end()), vy.end());

	for(int i = 1; i <= 6; i++) {
		x[i] = lower_bound(vx.begin(), vx.end(), x[i]) - vx.begin() + 1;
		y[i] = lower_bound(vy.begin(), vy.end(), y[i]) - vy.begin() + 1;
		if(i % 2 == 0) { x[i]--; y[i]--; }
	}

	for(int i = x[1]; i <= x[2]; i++) {
		for(int j = y[1]; j <= y[2]; j++) A[i][j] = 1;
	}
	for(int k = 3; k <= 5; k += 2) {
		for(int i = x[k]; i <= x[k + 1]; i++) {
			for(int j = y[k]; j <= y[k + 1]; j++) A[i][j] = 0;
		}
	}
	for(int i = 1; i <= 6; i++) {
		for(int j = 1; j <= 6; j++) {
			if(A[i][j] == 1) { puts("YES"); return 0; }
		}
	}
	puts("NO");
	return 0;
}