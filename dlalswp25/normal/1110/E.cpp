#include <bits/stdc++.h>

using namespace std;

int N;
int C[101010];
int T[101010];

vector<int> V1;
vector<int> V2;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &C[i]);
	for(int i = 1; i <= N; i++) scanf("%d", &T[i]);

	if(C[1] != T[1] || C[N] != T[N]) { puts("No"); return 0; }

	for(int i = 2; i <= N; i++) V1.push_back(C[i] - C[i - 1]);
	for(int i = 2; i <= N; i++) V2.push_back(T[i] - T[i - 1]);
	sort(V1.begin(), V1.end());
	sort(V2.begin(), V2.end());

	for(int i = 0; i < V1.size(); i++) {
		if(V1[i] != V2[i]) {
			puts("No"); return 0;
		}
	}
	puts("Yes");
	return 0;
}