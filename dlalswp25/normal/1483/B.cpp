#include <bits/stdc++.h>

using namespace std;

int N;
int A[101010];
set<int>::iterator it;
set<int> S;

int lft[101010];
int rgt[101010];

int gcd(int a, int b) {
	while(b) { a %= b; swap(a, b); } return a; 
}

void go() {
	if(it == S.end()) it = S.begin();
	it++;
	if(it == S.end()) it = S.begin();
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 0; i < N; i++) scanf("%d", &A[i]);

		if(N == 1) {
			if(A[0] == 1) puts("1 1");
			else puts("0");
			continue;
		}

		S.clear();
		vector<int> ans;
		for(int i = 0; i < N; i++) {
			if(gcd(A[i], A[(i + N - 1) % N]) == 1) {
				S.insert(i);
			}
		}

		for(int i = 0; i < N; i++) lft[i] = (i + N - 1) % N;
		for(int i = 0; i < N; i++) rgt[i] = (i + 1) % N;

		if(!S.size()) {
			puts("0");
			continue;
		}

		it = S.begin();
		if(*it == 0) go();
		while(S.size()) {
			int x = *it;
			ans.push_back(x);

			int l = lft[x], r = rgt[x];
			if(l == r) {
				if(A[l] == 1) ans.push_back(l);
				break;
			}

			if(S.find(r) != S.end()) S.erase(S.find(r));
			if(gcd(A[l], A[r]) == 1) S.insert(r);
			lft[r] = l; rgt[l] = r;
			it = S.erase(it);
			if(!S.size()) break;
			if(it == S.end()) it = S.begin();
			if(*it == r) go();
		}

		printf("%d ", ans.size());
		for(int i : ans) printf("%d ", i + 1); puts("");
	}
	return 0;
}