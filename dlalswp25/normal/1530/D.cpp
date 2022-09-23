#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];
int B[202020];
set<int> S, X, Y;
vector<int> V[202020];

void print() {
	for(int i = 1; i <= N; i++) printf("%d ", B[i]); puts("");
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		S.clear(); X.clear(); Y.clear();
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) B[i] = 0;
		for(int i = 1; i <= N; i++) V[i].clear();
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			V[A[i]].push_back(i);
			if(S.find(A[i]) == S.end()) B[i] = A[i];
			S.insert(A[i]);
		}

		for(int i = 1; i <= N; i++) {
			if(S.find(i) == S.end()) Y.insert(i);
		}
		for(int i = 1; i <= N; i++) {
			if(!B[i]) X.insert(i);
		}

		printf("%d\n", S.size());
		if(S.size() == N - 1) {
			int x = *X.begin(), y = *Y.begin();
			if(x == y) {
				for(int i : V[A[x]]) {
					if(i == x) continue;
					B[i] = y;
				}
				B[x] = A[x];
			}
			else {
				B[x] = y;
			}
			print(); continue;
		}

		while(X.size()) {
			if(X.size() == 1) {
				B[*X.begin()] = *Y.begin();
				X.erase(X.begin()); Y.erase(Y.begin());
			}
			else if(X.size() == 2) {
				auto it = X.begin();
				if(Y.find(*it) == Y.end()) it++;
				int x = *it; X.erase(it);
				it = Y.begin();
				if(x == *it) it++;
				B[x] = *it;
				Y.erase(it);
			}
			else {
				int x = *X.begin(); X.erase(X.begin());
				auto it = Y.begin();
				if(x == *it) it++;
				B[x] = *it;
				Y.erase(it);
			}
		}
		print();
	}
	return 0;
}