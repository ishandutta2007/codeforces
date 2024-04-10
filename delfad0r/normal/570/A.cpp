#include <bits/stdc++.h>

using namespace std;

int N, M;
int V[200][200];
int V2[200];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int m = 0; m < M; ++m)
		for(int n = 0; n < N; ++n)
			cin >> V[m][n];
	
	for(int m = 0; m < M; ++m) {
		int w, best = -1;
		for(int n = 0; n < N; ++n)
			if(V[m][n] > best) {
				best = V[m][n];
				w = n;
			}
		++V2[w];
	}
	
	cout << (max_element(V2, V2 + N) - V2 + 1) << '\n';
}